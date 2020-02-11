allow_scm_jenkinsfile = false
libraries{
  sonarqube{
    enforce_quality_gate = true
	credential_id = sonar-admin
  }
}
