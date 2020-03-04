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
     			echo "Start checkout $path"
     			sh 'env '
     			sh 'pwd '
     			sh 'ls /home/app'
				git credentialsId: 'camel', url: "ssh://cacalos@camel.uangel.com/data3/git/ua5g/usmsf_map.git"
     			sh 'ln -s "${WORKSPACE}" /home/app/src'
     			sh 'ln -s "${WORKSPACE}" /home/app/SMSF'
     			sh 'ls -lt  /home/app'
     			sh 'ls -lt /home/app/src'
     			sh 'cd /home/app/src;jam clean;jam install;'
    		}
  		}
	}
}
