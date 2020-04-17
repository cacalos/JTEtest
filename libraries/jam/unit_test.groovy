void call(){
    node {
        def registry = config.registry ?:
            "https://camel.uangel.com:5000"
        def home = config.home ?:
            "/home/app/src"
        def image = config.base_image ?:
            { error "Not define base image name in Pipeline Config" } ()

        currentBuild.description = 'Unit Test code by Makefile'
        currentBuild.result = 'SUCCESS'
        try {
            stage("$currentBuild.description Stage"){
                echo "Start $currentBuild.description "
                docker.withRegistry("${registry}") {
                    docker.image("${image}").inside('-u 0:0 ') {
                        sh "ln -s ${WORKSPACE} ${home}"
                        sh "cd ${home};make unittest"
                        sh "chown -R ${JENKINS_ID} ${WORKSPACE}"
//						junit 'reports/unittest/*.xml'
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
