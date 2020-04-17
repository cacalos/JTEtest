void call(){

    node {
        def registry = config.registry ?:
            "https://camel.uangel.com:5000"
        def home = config.home ?:
            "/home/app/src"
        def image = config.base_image ?:
            { error "Not define base image name in Pipeline Config" } ()

        currentBuild.description = 'Lint by Makefile'
        currentBuild.result = 'SUCCESS'
        try {
            stage("$currentBuild.description Stage"){
                echo "Start $currentBuild.description "
                docker.withRegistry("${registry}") {
                    docker.image("${image}").inside('-u 0:0 ') {
                        sh "ln -s ${WORKSPACE} ${home}"
						/*
                        def addClang, makeXml
                        addClang = this.getAddClang()
                        makeXml = this.getMakeXml()
                        writeFile file: "${WORKSPACE}/addClang.py", text: "${addClang}"
                        writeFile file: "${WORKSPACE}/make_xml.j2", text: "${makeXml}"
						*/
                        sh "cd ${home};make lint"
                        sh "chown -R ${JENKINS_ID} ${WORKSPACE}"
                        publishCppcheck pattern:'reports/cppcheck.xml'
                    }
                }
            }
        } catch (e) {
            def Boolean throwflag = true
            error_catch e,throwflag
        } finally {
            echo "Finally $currentBuild.description $currentBuild.result "
        }
    }
}

String getAddClang(){
    def contents = """
# -*- coding: utf-8 -*- 
import os
import io
import re
import json
import sys
import xmltodict
from jinja2 import Environment, FileSystemLoader
import subprocess

def todict(str):
    return eval(str)
def is_list(value):
    return isinstance(value, list)

class TemplateEngine():
    def __init__(self, src_path, dst_path):
        self.src_path = os.path.expandvars(src_path)
        if dst_path:
            self.dst_path = os.path.expandvars(dst_path)

    def render_output(self, jinja_file, params):
        env = Environment(loader=FileSystemLoader(searchpath=self.src_path), trim_blocks=True, lstrip_blocks=True)
        env.add_extension('jinja2.ext.loopcontrols')
        env.add_extension('jinja2.ext.do')
        env.filters['todict'] = todict
        env.filters['islist'] = is_list
        jinja = env.get_template(jinja_file)
        return jinja.render(params=params)

def getDatas(cmd):
    p = subprocess.Popen(cmd, stdout=subprocess.PIPE, shell=True)
    (output, err) = p.communicate()
    p_status = p.wait()
    if p_status != 0:
        print "Command exit status/return code : ", p_status
        sys.exit(-1)

    new = list(output)
    for i, c in enumerate(output):
        if ord(c) > 127:
            new[i] = " "
    output = ''.join(new)
    return output

def covertReserved(inp):

    out = inp.replace(">", "&gt;")
    out = out.replace("<", "&lt;")
    out = out.replace("&", "&amp;")
    out = out.replace("%", "&#37;")
    return out

def getUnitTest(cmd, jsondata):

    output = getDatas(cmd)

    base = jsondata['results']['errors']['error']

    pattern = r"[^&slash&:]+"


    lines = output.split('&slash&n')
    for idx, line in enumerate(lines):
        m = re.findall(pattern, line)
        if not m or len(m) != 5:
            continue
        msg = covertReserved(line)
        if ((idx + 1) < len(lines)):
            verbose = covertReserved(lines[idx + 1])
        else:
            verbose = ""

        sp = msg.split(':')
        base.append({"verbose": verbose.strip(), 
                    "symbol": "jam check", 
                    "location": {
                        "column": sp[2].strip(), 
                        "line": sp[1].strip(), 
                        "file": sp[0].strip() 
                    }, 
                    "msg": sp[4].strip(),
                    "id": "clang", 
                    "severity": sp[3].strip()})
    return jsondata

def main(args):

    if len(sys.argv) > 1:
        config_path = sys.argv[1]
    else:
        config_path = './reports/cppcheck.xml'

    try:
        with open(config_path) as f:
            xmldata = f.read()
    except IOError:
        print("Unable to read configuration file %s." % (config_path))

    jsondata = json.loads(json.dumps(xmltodict.parse(xmldata)).replace("@","").replace("&","&amp;").replace(">","&gt;").replace("<","&lt;").replace('&slash&&slash&&slash&"', '&quot;'))


    if len(sys.argv) > 2:
        jsondata = getUnitTest('cat ' + sys.argv[2], jsondata)
    else:
        jsondata = getUnitTest('cat ./reports/clang.txt', jsondata)

    te = TemplateEngine('./', None)
    p = unicode(te.render_output('make_xml.j2', jsondata).replace('&slash&'','&apos;').replace('(&slash&")', '(&quot;)'))
    print p

if __name__ == "__main__":
    main(sys.argv)
"""
    return contents.replace("&slash&", "\\")
}

String getMakeXml(){
    def contents = """<?xml version="1.0" encoding="UTF-8"?>
<results version="{{params.results.version}}">
    <cppcheck version="{{params.results.cppcheck.version}}"/>
    <errors>
        {% for err in  params.results.errors.error %}
        {% set items = [] %}
        {% do items.append("<error id=&slash&"" + err.id + "&slash&" severity=&slash&"" + err.severity + "&slash&" msg=&slash&"" + err.msg + "&slash&" verbose=&slash&"" + err.verbose + "&slash&"") %}
        {% if err.cwe %}
            {% do items.append("cwe=&slash&"" + err.cwe + "&slash&""  ) %}
        {% endif %}
        {% do items.append(">") %}
        {{items|join(' ')|replace(' >','>')}}
            {% if not err.location %}
        </error>
                {% continue %}
            {% elif err.location|islist  %}
                {% for loc in  err.location %}
                    {% set items = [] %}
                    {% do items.append("<location") %}
                    {% if loc.file0 %}
                        {% do items.append("file0=&slash&"" + loc.file0 + "&slash&"") %}
                    {% endif %}
                    {% do items.append("file=&slash&"" + loc.file + "&slash&" line=&slash&"" + loc.line + "&slash&" column=&slash&"" + loc.column + "&slash&"") %}
                    {% if loc.info %}
                        {% do items.append("info=&slash&"" + loc.info + "&slash&"") %}
                    {% endif %}
                    {% do items.append("/>") %}
            {{items|join(' ')|replace(' />','/>')}}
                {% endfor %}
            {% else %}
                {% set loc = err.location %}
                {% set items = [] %}
                {% do items.append("<location") %}
                {% if loc.file0 %}
                    {% do items.append("file0=&slash&"" + loc.file0 + "&slash&"") %}
                {% endif %}
                {% do items.append("file=&slash&"" + loc.file + "&slash&" line=&slash&"" + loc.line + "&slash&" column=&slash&"" + loc.column + "&slash&"") %}
                {% if loc.info %}
                    {% do items.append("info=&slash&"" + loc.info + "&slash&"") %}
                {% endif %}
                {% do items.append("/>") %}
            {{items|join(' ')|replace(' />','/>')}}
            {% endif %}
            {% if err.symbol %}
            <symbol>{{err.symbol}}</symbol>
            {% endif %}
        </error>
        {% endfor %}
    </errors>
</results>"""
    return contents.replace("&slash&", "\\")
}
