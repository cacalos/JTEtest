void call(){
    node {
        def root = tool name: 'Go 1.13', type: 'go'
		def allowEmptyResults = config.allowEmptyResults ?:
			false

		properties(
			[
				parameters(
					[
					string(name: 'DEBUG', defaultValue: 'FALSE', description: 'Debug flag')
					]
				)
			]
		)

        withEnv(["GOROOT=${root}", "PATH+GO=${root}/bin:${HOME}/go/bin"]) {    
			currentBuild.result = 'SUCCESS'
			currentBuild.description = 'Unittest'
            try {
				stage("$currentBuild.description Stage"){
                	echo "Start $currentBuild.description "
					if( env.DEBUG == 'TRUE') {
						sh 'make -rRd jenkins_junittest'
					} else {
						sh 'make jenkins_junittest'
					}
					junit allowEmptyResults: "${allowEmptyResults}", testResults:"reports/unittest/*.xml"
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
