void call(){
    node {

		currentBuild.description = 'Make Makefile by config'
		currentBuild.result = 'SUCCESS'

        def moduleName = ""
        if (fileExists("${WORKSPACE}/go.mod")) {
            String fileContents = new File("${WORKSPACE}/go.mod").getText('UTF-8')
            moduleName = (fileContents.split("\n")[0].split(" ")[1] + "/").replace("/", "\\/")
        }

        def makefile_config, makefile_name, headers, tails, file_names
        (makefile_config, makefile_name, headers, tails, file_names) = makefile_func(fileExists("${WORKSPACE}/Makefile"), moduleName)

        if (fileExists("${WORKSPACE}/Makefile")) {
            sh "mv ${WORKSPACE}/Makefile ${WORKSPACE}/MakefileOrigin"
        }

		try {

            stage("$currentBuild.description Stage"){
                echo "Start $currentBuild.description"
				configFileProvider( [configFile(fileId: "${makefile_name}", variable: 'TempMakefile')]) {
					writeFile file: "${WORKSPACE}/Makefile", text: "${headers}\n${makefile_config}\n"
					sh "cat $TempMakefile >> ${WORKSPACE}/Makefile"
					sh "echo ${tails}  >> ${WORKSPACE}/Makefile"
				}
				sh "cat ${WORKSPACE}/Makefile"
			}
		} catch (e) {
			def Boolean throwflag = true
			error_catch e,throwflag
		} finally {
			echo "Finally $currentBuild.description $currentBuild.result "
		}
	}
}




