void call(Boolean makefileExist, String moduleName,Boolean gitFlag = false) {

	def makefile_config, makefile_name, headers, tails, git_url, git_credential, git_base, file_names


	makefile_config = this.get_makefile_config()
	makefile_name = this.get_makefile_name()
	file_names = config.file_names ?:
		""
	(headers, tails) = this.get_makefile_headers_tails(makefileExist, moduleName)
	if (moduleName.length() > 0) {
		headers = headers + "\nMODULE_NAME := ${moduleName}"
	}

	if (gitFlag) {
        git_url = config.git_url ?:
            { error "Not define git_url config" } ()
        git_credential = config.git_credential ?:
            { error "Not define git_credential config" } ()
		if (makefile_name == "goMakefile") {
			git_base = "./jte_config/pipeline-config-forGo"
		} else {
			git_base = "./jte_config/pipeline-config-forC"
		}
		return [makefile_config, makefile_name, headers, tails, git_url,  git_credential, git_base, file_names]
	} else {
		return [makefile_config, makefile_name, headers, tails, file_names]
	}
}

String get_makefile_config(){

	def makefile_config = config.makefile_config ?:
		""
	return makefile_config.replace("&slash&", "\\").replace("&quot;", "\"")
}

String get_makefile_name(){
	def makefile_strategies = [ "jamMakefile", "goMakefile" ]
	if (!(config.makefile_name in makefile_strategies))
		error "makefile strategy: ${config.makefile_name} not one of ${makefile_strategies}"

	return config.makefile_name
}


String get_makefile_headers_tails(Boolean makefileExist, String moduleName){
	def headers, tails
    tails = ""
	if (config.makefile_name == "jamMakefile") {
   		headers = '''CONFIGURE_PATH := ${PWD}/config
BUILD_HOME := ${PWD}
CLEAN_SCRIPT_LIST := echo "make clean"
'''
	} else {
		headers = '''PKG_LIST := $(shell go list ./...)
BUILD_HOME := ${PWD}
'''
		if (makefileExist) {
			tails = "include ./MakefileOrigin"
		}
	}
	return [headers, tails]
}
