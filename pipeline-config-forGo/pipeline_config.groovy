allow_scm_jenkinsfile = false
libraries{
    common{
		git_url = "ssh://cacalos@camel.uangel.com/data3/git/ua5g/ujte.git"
		git_credential = "camel"
		makefile_name = "goMakefile"
        merge = true
	}
    sonarqube{
        enforce_quality_gate = true
        merge = true
    }
    helm{
        merge = true
    }
    merge = true
}
