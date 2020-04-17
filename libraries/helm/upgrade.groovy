void call(){
    node {
		/*
			overriding = "resources/helm_charts/dish_samsung/overriding-values/uangel/t2x-master1/values.yaml"
			name_space = "testjks"
			name = "usmsf-jks"
			service = "resources/helm_charts/dish_samsung/dish-smsf-1.2.0.tgz"
	   */
		def overriding = config.overriding ?:
			{ error "Not define overriding in Pipeline Config" } ()
		def name_space = config.name_space ?:
			{ error "Not define name_space in Pipeline Config" } ()
		def name = config.name ?:
			{ error "Not define name in Pipeline Config" } ()
		def service = config.service ?:
			{ error "Not define service in Pipeline Config" } ()

        currentBuild.description = 'Upgrade by helm'
        currentBuild.result = 'SUCCESS'
        try {
            stage("$currentBuild.description Stage"){
				echo "Start $currentBuild.description "
    			sh "/usr/local/bin/helm upgrade  ${name} ${WORKSPACE}/${service} -f ${WORKSPACE}/${overriding}"
			}
		} catch (e) {
			def Boolean throwflag = true
			error_catch e,throwflag
		} finally {
			echo "Finally $currentBuild.description $currentBuild.result "
		}
    }
}

