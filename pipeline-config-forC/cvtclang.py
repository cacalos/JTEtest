
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
    out = out.replace("\"", "&quot;")
    return out

def getUnitTest(cmd, jsondata):

    output = getDatas(cmd)

    base = jsondata['results']['errors']['error']

    pattern = r"[^\:]+"


    lines = output.split('\n')
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

    jsondata = json.loads(json.dumps(xmltodict.parse(xmldata)).replace("@","").replace("&","&amp;").replace(">","&gt;").replace("<","&lt;").replace('\\\"', '&quot;'))


    if len(sys.argv) > 2:
        jsondata = getUnitTest('cat ' + sys.argv[2], jsondata)
    else:
        jsondata = getUnitTest('cat ./reports/clang.txt', jsondata)

    te = TemplateEngine('./', None)
    p = unicode(te.render_output('makexml.j2', jsondata).replace('\'','&apos;').replace('(\")', '(&quot;)'))
    print p

if __name__ == "__main__":
    main(sys.argv)
