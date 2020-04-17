void call(){
    node {

        def make_error = config.make_error ?:
            false
		def registry = config.registry ?:
			"camel.uangel.com:5000"
		def registry_url = "https://${registry}"
		def target_image = config.target_image ?:
			{ error "Not define base image name in Pipeline Config" } ()
		def target_tag = config.target_tag ?:
			"${env.BUILD_ID}"
		def dockerfile = config.dockerfile ?:
			"Dockerfile"

		def pre_script = config.pre_script ?:
			"echo no pre_script"
		def run_script = config.run_script ?:
			"echo no run_script"
		def post_script = config.post_script ?:
			"echo no post_script"

        currentBuild.description = 'build Docker Image'
        currentBuild.result = 'SUCCESS'
        try {
            if (make_error == true){
                throw new Exception("Don't worry ..   User make error!")
            }
            stage("$currentBuild.description Stage"){
				echo "Start $currentBuild.description "
				docker.withRegistry("${registry_url}") {
					def customImage = docker.build("${target_image}:${target_tag}", "-f ${dockerfile} .")
					customImage.push()
					if ("${target_tag}" != "latest") {
						customImage.push('latest')
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

