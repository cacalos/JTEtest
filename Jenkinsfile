node {

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
     			echo "Start checkout"
     			sh 'pwd '
     			sh 'ls '
				git credentialsId: 'camel', url: "ssh://cacalos@camel.uangel.com/data3/git/ua5g/usmsf_map.git"
     			sh 'ln -s /var/lib/jenkins/workspace/docker_multibranch_master /home/app/src'
     			sh 'ln -s /var/lib/jenkins/workspace/docker_multibranch_master /home/app/SMSF'
     			sh 'ls /home/app'
     			sh 'ls /home/app/src'
     			sh 'cd /home/app/SMSF;jam clean;jam install;'
    		}
  		}
	}
}
