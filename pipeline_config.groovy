allow_scm_jenkinsfile = false
libraries{
   github{
      source_type = "github"
   }
  sonarqube{
    enforce_quality_gate = true
	credential_id = sonar-admin
  }
}
