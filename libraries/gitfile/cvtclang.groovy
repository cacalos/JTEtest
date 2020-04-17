void call(){
    node {
		currentBuild.description = 'Make cvt clang'
		currentBuild.result = 'SUCCESS'

        def makefile_config, makefile_name, headers, tails , git_url, git_credential, git_base, file_names
        (makefile_config, makefile_name, headers, tails , git_url, git_credential, git_base, file_names) = makefile_func(false, "", true)

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
                echo "Start $currentBuild.description  ${file_names}"
				files = file_names.split(",")
				files.each{ file_name->
					sh "cp ${git_base}/${file_name} ${WORKSPACE}/${file_name}"
					echo "copy  ${git_base}/${file_name} to workspace"
					sh "cat ${WORKSPACE}/${file_name}"
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

