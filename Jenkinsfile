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
     			sh 'ls /home/app'
     			sh 'cp -rf usmsf_map /home/app/SMSF'
     			sh 'ls /home/app'
     			sh 'ls /home/app/SMSF'
     			//sh 'cd /home/app/SMSF;jam clean;jam install;'
    		}
  		}
	}
}
