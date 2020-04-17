
void call(){

    node {
		def cron_period = config.cron_bt_period ?:
			"*/1 * * * *"
		def cron_srcs = config.srcs ?:
			{ error "Not define checked srcs in Pipeline Config" } ()
		def username = config.username ?:
			{ error "Not define username in Pipeline Config" } ()
		def mail_lists = config.mail_lists ?:
			{ error "Not define email in Pipeline Config" } ()

		def srcs
		
		properties([pipelineTriggers([cron("$cron_period")])])

		srcs = cron_srcs.split(";;")
		srcs.each{ temp_src->
			def project = temp_src.split("/")[-1]
			if (project == "trunk") {
				project = temp_src.split("/")[-2]
			}

			src = temp_src.split("://")[0] + "://$username@" + temp_src.split("://")[1]
			echo "src $src "

			if (src.contains("svn+ssh")) {
				checkout([$class: 'SubversionSCM', additionalCredentials: [], excludedCommitMessages: '', excludedRegions: '', excludedRevprop: '', excludedUsers: '', filterChangelog: false, ignoreDirPropChanges: false, includedRegions: '', locations: [[cancelProcessOnExternalsFail: true, credentialsId: 'camel', depthOption: 'infinity', ignoreExternalsOption: true, local: '.', remote: "$src"]], quietOperation: true, workspaceUpdater: [$class: 'UpdateUpdater']])
			} else {
				git credentialsId: 'camel', url: "$src"
			}

			stage('CheckDailyCommit ' + "$project") {
				lastChanges since: 'LAST_SUCCESSFUL_BUILD', format:'SIDE',matching: 'LINE'
				msg = changes()
				if ( msg != "") {
					mail to: "$mail_lists",
						subject: "daily check: ${project}",
						body: "${msg}\n${env.BUILD_URL}"
				} else {
					echo "Not send mail by unchanged"
				}
			}
		}
	}
}

@NonCPS
def changes() {
    MAX_MSG_LEN = 100
    def changeString = ""

    echo "Gathering SCM changes"
    def changeLogSets = currentBuild.changeSets
    for (int i = 0; i < changeLogSets.size(); i++) {
        def entries = changeLogSets[i].items
        for (int j = 0; j < entries.length; j++) {
            def entry = entries[j]
            truncated_msg = entry.msg.take(MAX_MSG_LEN)
            changeString += " - [${entry.author}] : ${truncated_msg}\n"
        }
    }

    return changeString
}

