void call(){
    node {

		currentBuild.description = 'Make Makefile by git'
		currentBuild.result = 'SUCCESS'

		def moduleName = ""
        if (fileExists("${WORKSPACE}/go.mod")) {
			String fileContents = new File("${WORKSPACE}/go.mod").getText('UTF-8')
			moduleName = (fileContents.split("\n")[0].split(" ")[1] + "/").replace("/", "\\/")
        }

        def makefile_config, makefile_name, headers, tails , git_url, git_credential, git_base, file_names
        (makefile_config, makefile_name, headers, tails , git_url, git_credential, git_base, file_names) = makefile_func(fileExists("${WORKSPACE}/Makefile"), moduleName, true)

        if (fileExists("${WORKSPACE}/Makefile")) {
            sh "mv ${WORKSPACE}/Makefile ${WORKSPACE}/MakefileOrigin"
        }

		try {
            stage("$currentBuild.description Checkout Stage"){
				checkout([$class: 'GitSCM', 
					branches: [[name: '*/master']], 
					doGenerateSubmoduleConfigurations: false, 
					extensions: [[$class: 'RelativeTargetDirectory', relativeTargetDir: 'jte_config']],
					submoduleCfg: [], 
					userRemoteConfigs: [[credentialsId: "${git_credential}", url: "${git_url}"]]
				])
			}

            stage("$currentBuild.description Copy Stage"){
                echo "Start $currentBuild.description "
				writeFile file: "${WORKSPACE}/Makefile", text: "${headers}\n${makefile_config}\n"
				sh "cat ${git_base}/Makefile >> ${WORKSPACE}/Makefile"
				sh "echo ${tails}  >> ${WORKSPACE}/Makefile"
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
