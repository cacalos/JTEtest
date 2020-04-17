void call(){
    node {
        def make_error = config.make_error ?:
            false

        def registry = config.registry ?:
            "https://camel.uangel.com:5000"
        def image = config.image ?:
            { error "Not define image name in Pipeline Config" } ()
        def init_script = config.init_script ?:
            "echo no init script"

		currentBuild.description = 'Dockerimage'
		currentBuild.result = 'SUCCESS'
        try {
            stage("$currentBuild.description Stage"){
                echo "Start $currentBuild.description "
				sh 'cd /home/app'
				sh 'docker build -f Dockerfile.diameter --tag camel.uangel.com:5000/dia_svc:latest .'
				/*
                docker.withRegistry("${registry}") {

					def dockerfile = 'Dockerfile.test'
					def customImage = docker.build("my-image:${env.BUILD_ID}", "-f ${dockerfile} ./dockerfiles") 
					stage('Build docker image') {
					container('docker') {
					withDockerRegistry([ credentialsId: "$registryCredential", url: "http://$registry" ]) {
					sh "docker build -t $registry/sampleapp:1.0 -f ./Dockerfile ."
					}
										           }
                    docker.image("${image}").inside('-u 0:0 ') {
						echo "Start $currentBuild.description "
						sh 'cd /home/app;build_dia.sh'
					}
				}
				*/
			}
		} catch (e) {
			def Boolean throwflag = true
			error_catch e,throwflag
		} finally {
			echo "Finally $currentBuild.description $currentBuild.result "
		}
    }
}
