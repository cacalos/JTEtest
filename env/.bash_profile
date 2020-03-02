# .bash_profile

# Get the aliases and functions
if [ -f ~/.bashrc ]; then
	. ~/.bashrc
fi

# User specific environment and startup programs

PATH=$PATH:$HOME/.local/bin:$HOME/bin

export JAVA_HOME=/usr/java/jdk-13.0.2/
export PATH=$PATH:$JAVA_HOME/bin
