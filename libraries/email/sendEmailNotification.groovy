@AfterStep
@CleanUp
void call(context){
	node {
		if (context.library.equals("email")){
			return
		}

		if (context.library.equals(null) && context.status.equals("SUCCESS") ) {
			send_email()
			echo "email Cleanup Success case $context"
		}

		if (!context.status.equals("FAILURE") || (context.library.equals("common") || context.library.equals(null))){
			return
		}
		send_email()
	}
}

