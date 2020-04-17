
void call(Exception e=null) {

	def git_committer_email
	try {
		git_committer_email = sh(script:"git --no-pager show -s --format='%ae'", returnStdout:true).trim()
	} catch (err) {
		git_committer_email = sh(script:"svn info |grep 'Last Changed Author'", returnStdout:true).split(": ")[1].trim() + "@uangel.com"
	}

	def receivers


	echo "git commiter $git_committer_email"

	if ("$currentBuild.result" == "SUCCESS") {
		receivers = config.success_mail_lists ?:
			"empty"
	} else {
		receivers = config.fail_mail_lists ?:
			{ error "fail_mail_lists not defined in Pipeline Config" } ()

		if (e != null) {
			currentBuild.description  += "&&" + e.getMessage()
		} else {
			currentBuild.description  += "&&Unknown error"
		}

		if (!receivers.contains(git_committer_email)) {
			receivers += ",$git_committer_email"
			echo "add $git_committer_email to receivers final $receivers"
		}
	}
	echo "mail description $currentBuild.description "

	if ("$receivers" != "empty") {
		if ("$currentBuild.result" == "SUCCESS") {
			emailext mimeType: 'text/html', \
								subject: "${env.JOB_NAME} - Build# ${env.BUILD_NUMBER} - ${currentBuild.result}",\
								to: "$receivers", \
								body: '''${SCRIPT, template="success.groovy"}'''
		} else {
			emailext mimeType: 'text/html', \
								subject: "${env.JOB_NAME} - Build# ${env.BUILD_NUMBER} - ${currentBuild.result}",\
								to: "$receivers", \
								body: '''${SCRIPT, template="failure.groovy"}'''
		}
		echo "send email $currentBuild.result "
	} else {
		echo "Not send email $currentBuild.result "
	}
}




