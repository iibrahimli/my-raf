#! /bin/bash

if [ $# -ne 1 ];then
	echo "Wrong number of arguments"
	echo "Usage: ./exist_user.sh <username>"
elif [ $(grep -i $1 /etc/passwd | cut -d: -f1) ];then
	echo "User $1 exists in the system"
else
	echo "User $1 is not defined in this system"
fi
	
