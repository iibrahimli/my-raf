#! /bin/bash

users_connect (){
	echo "Currently logged in users:" $(who | cut -d ' ' -f1)
}

disk_space (){
	echo "Free disk space:" $(df -h --total | grep -i total | tr -s ' ' : | cut -d: -f4)
}

pause (){
	while true; do
		read -s -n 1 key
		if [[ $key = "" ]]; then 
    			echo 'Quitting...'
			exit
		fi
	done
}

while true; do
	echo "0 - End"
	echo "1 - Display users"
	echo "2 - Display space available"
	read -p "Choose an item: " ch
	case $ch in
	0)
		pause
		;;
	1)
		clear
		echo " "
		users_connect
		echo " "
		;;
	2)
		clear
		echo " "
		disk_space
		echo " "
		;;
	*)
		clear
		echo " "
		echo "Invalid choice"
		echo " "
		;;		
	esac
done
