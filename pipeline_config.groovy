allow_scm_jenkinsfile = false
libraries{
  github_enterprise
  sonarqube{
    enforce_quality_gate = true
  }
}
