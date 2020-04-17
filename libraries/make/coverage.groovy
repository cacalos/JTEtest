void call(){
    node {
		properties(
			[
				parameters(
					[
					string(name: 'DEBUG', defaultValue: 'FALSE', description: 'Debug flag')
					]
				)
			]
		)

        def root = tool name: 'Go 1.13', type: 'go'
        withEnv(["GOROOT=${root}", "PATH+GO=${root}/bin:${HOME}/go/bin"]) {    
			currentBuild.result = 'SUCCESS'
			currentBuild.description = 'Coverage'
            try {
				stage("$currentBuild.description Stage"){
                	echo "Start $currentBuild.description "
					if( env.DEBUG == 'TRUE') {
						sh 'make -rRd jenkins_coverage'
					} else {
						sh 'make jenkins_coverage'
					}
                    cobertura autoUpdateHealth: false, autoUpdateStability: false, coberturaReportFile: 'reports/coverage/*.xml', conditionalCoverageTargets: '70, 0, 0', failUnhealthy: false, failUnstable: false, lineCoverageTargets: '80, 0, 0', maxNumberOfBuilds: 0, methodCoverageTargets: '80, 0, 0', onlyStable: false, sourceEncoding: 'ASCII', zoomCoverageChart: false
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
