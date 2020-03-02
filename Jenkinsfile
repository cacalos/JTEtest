node {

     stage('Compile SMSF ') {
        docker.withRegistry('https://camel.uangel.com:5000') {
    		docker.image("usmsf_jks").inside {
     			echo "Start checkout"
				/*
     			git credentialsId: 'camel', url: "ssh://cacalos@camel.uangel.com/data3/git/ua5g/usmsf_map.git"
     			sh 'cd /home/app/SMSF;jam clean;jam install;'
				*/
     			sh 'ls '
    		}
  		}
	}
}
