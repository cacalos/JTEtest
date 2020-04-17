void call(){

    node {
        def registry = config.registry ?:
            "https://camel.uangel.com:5000"
        def home = config.home ?:
            "/home/app/src"
        def image = config.base_image ?:
            { error "Not define base image name in Pipeline Config" } ()

        currentBuild.description = 'Coverage by Makefile'
        currentBuild.result = 'SUCCESS'
        try {
            stage("$currentBuild.description Stage"){
                echo "Start $currentBuild.description "
                docker.withRegistry("${registry}") {
                    docker.image("${image}").inside('-u 0:0 ') {
                        sh "ln -s ${WORKSPACE} ${home}"
                        sh "cd ${home};make coverage"
                        sh "chown -R ${JENKINS_ID} ${WORKSPACE}"
                    	cobertura autoUpdateHealth: false, autoUpdateStability: false, coberturaReportFile: 'reports/coverage/*.xml', conditionalCoverageTargets: '70, 0, 0', failUnhealthy: false, failUnstable: false, lineCoverageTargets: '80, 0, 0', maxNumberOfBuilds: 0, methodCoverageTargets: '80, 0, 0', onlyStable: false, sourceEncoding: 'ASCII', zoomCoverageChart: false
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
