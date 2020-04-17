void call(){
    node {
        currentBuild.description = 'Make cvt clang'
        currentBuild.result = 'SUCCESS'

        def makefile_config, makefile_name, headers, tails , file_names 
        (makefile_config, makefile_name, headers, tails , file_names) = makefile_func(false,"")

        try {
            stage("$currentBuild.description Stage"){
                echo "Start $currentBuild.description "
                files = file_names.split(",")
                files.each{ file_name->
                    configFileProvider( [configFile(fileId: "${file_name}", variable: 'Tempfile')]) {
                        sh "cp $Tempfile ${WORKSPACE}/${file_name}"
                    }
                    sh "cat ${WORKSPACE}/${file_name}"
                }
            }
        } catch (e) {
            def Boolean throwflag = true
            error_catch e,throwflag
        } finally {
            echo "Finally $currentBuild.description $currentBuild.result "
        }
    }
}
