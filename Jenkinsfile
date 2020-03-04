node {

	def path = "${JENKINS_HOME}/workspace/" + "_${JOB_BASE_NAME}"
	/*
     stage('Test SMSF ') {
		withDockerContainer('camel.uangel.com:5000/usmsf_jks') {
     		echo "Test SMSF"
     		sh 'pwd '
		}
	}
	*/

     stage('Compile SMSF ') {
        docker.withRegistry('https://camel.uangel.com:5000') {
    		docker.image("usmsf_jks").inside('-u 0:0 ') {
     			echo "Start checkout $path"
     			sh 'env '
     			sh 'pwd '
     			sh 'ls /home/app'
				git credentialsId: 'camel', url: "ssh://cacalos@camel.uangel.com/data3/git/ua5g/usmsf_map.git"
     			sh 'ln -s "$path" /home/app/src'
     			sh 'ln -s "$path" /home/app/SMSF'
     			sh 'ls /home/app'
     			sh 'ls /home/app/src'
     			//sh 'cd /home/app/SMSF;jam clean;jam install;'
    		}
  		}
	}
}
