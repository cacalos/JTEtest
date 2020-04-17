allow_scm_jenkinsfile = false
libraries{
    common{
        git_url = "ssh://cacalos@camel.uangel.com/data3/git/ua5g/ujte.git"
        git_credential = "camel"
        makefile_name = "jamMakefile"
		file_names = 'cvtclang.py,makexml.j2'
        merge = true
    }
    sonarqube{
        enforce_quality_gate = true
        merge = true
    }
    merge = true
}
