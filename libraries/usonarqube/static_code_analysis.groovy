/*
  Copyright © 2018 Booz Allen Hamilton. All Rights Reserved.
  This software package is licensed under the Booz Allen Public License. The license can be found in the License file or at http://boozallen.github.io/licenses/bapl
*/

def call(){

  // sonarqube api token
    cred_id = config.credential_id ?:
                "sonarqube"
    sonar_server = config.sonar_server ?:
                "SonarQube"
    sonar_scanner = config.sonar_scanner ?:
                "scanner-4.2.0"
    enforce = config.enforce_quality_gate ?:
                true

    node {
        withCredentials([usernamePassword(credentialsId: cred_id, passwordVariable: 'token', usernameVariable: 'user')]) {
            env.sonarHome= tool name: sonar_scanner, type: 'hudson.plugins.sonar.SonarRunnerInstallation'
			stage("SonarQube Analysis"){
				withSonarQubeEnv(sonar_server){
					withEnv(["SONAR_SCANNER_OPTS=-Xmx2048m"]) {
						echo "env  ${env}"
						projectKey = "$env.JOB_NAME".replaceAll("/", ":")
						projectName = "$env.JOB_NAME".replaceAll("/", "-")
						def script = """${sonarHome}/bin/sonar-scanner -X -Dsonar.login=${user} -Dsonar.password=${token} -Dsonar.projectKey="$projectKey" -Dsonar.projectName="$projectName" -Dsonar.projectBaseDir=. """
						//def script = """${sonarHome}/bin/sonar-scanner -X -Dsonar.login=${user} -Dsonar.password=${token} -Dsonar.projectKey="$projectKey" -Dsonar.projectName="$projectName" -Dsonar.projectBaseDir=. -Dsonar.analysis.testInfo="$env.JENKINS_URL" """
				
						if (!fileExists("sonar-project.properties")) {
							echo "file not found  sonar-project.properties"
							script += "-Dsonar.sources=\"./src\""
						} 
						echo "script ${script}"
						sh script
					}
				}
			}
        }
    }
	stage("SonarQube waitForQualityGate"){
		timeout(time: 1, unit: 'HOURS') {
			def qg = waitForQualityGate()
			if (qg.status != 'OK' && enforce) {
				error "Pipeline aborted due to quality gate failure: ${qg.status}"
			}
		}
	}
}
