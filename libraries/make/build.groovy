void call(){
    node {
        def root = tool name: 'Go 1.13', type: 'go'
        withEnv(["GOROOT=${root}", "PATH+GO=${root}/bin:${HOME}/go/bin"]) {    
			currentBuild.description = 'Build'
			currentBuild.result = 'SUCCESS'
            try {
				stage("$currentBuild.description Stage"){
                	echo "Start $currentBuild.description "
					sh 'make build'
				}
            } catch (e) {
				def Boolean throwflag = true
				error_catch e,throwflag
            } finally {
                echo "Finally $currentBuild.description $currentBuild.result "
            }

        }
    }
}
