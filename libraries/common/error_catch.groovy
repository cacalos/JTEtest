
void call(Exception e, Boolean throwflag=true){

	echo "where  $currentBuild.description"
	currentBuild.result = 'FAILED'

	//send_email e
	if (throwflag == true) {
		throw e
	}
}

/*
	def String message = e.getMessage()

	echo "why  $message"

	// throw new Exception("$e")
	println "println catch $e "
	println("println catch $message ")

	notifyBuild('FAILED')
	sh 'curl  "https://api.telegram.org/bot1054860701:AAEnkV2L_FnoZ4hq1LPY04ueWeTe5HNRGr8/sendMessage?chat_id=414717032
	&text=hello By Jenkins"'
	
	println "error catch $e "
	echo e.toString()
	echo e.getMessage()
	//echo e.getStackTrace()
	//def String s = Throwables.getStackTraceAsString(e)
*/



