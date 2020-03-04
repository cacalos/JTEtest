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
     			sh 'ls -lt '
				if(fileExists("SMSF")) {
					sh 'rm -rf  SMSF'
					echo "rm -rf SMSF"
				}
     			sh 'pwd '
     			sh 'ls -lt '
				sh 'mkdir SMSF'
     			sh 'ls -lt ./SMSF/*'
     			sh 'ls -lt ./SMSF/.*'
     			sh 'whoami '
				dir('SMSF') {
					git credentialsId: 'camel', url: "ssh://cacalos@camel.uangel.com/data3/git/ua5g/usmsf_map.git"
				}
     			sh 'ls'
     			sh 'ls /home/app'
     			//sh 'cd /home/app/SMSF;jam clean;jam install;'
    		}
  		}
	}
}
