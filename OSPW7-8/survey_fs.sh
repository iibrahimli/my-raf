#! /bin/bash

sweep (){
	emptyfiles=$(ls -l ~ | grep -v ^d | tr -s ' ' : | cut -d: -f5,10 | grep ^0: | tr -d "0:")
	if [ ${emptyfiles[@]} == "+(' ')" ]; then
		echo "There are no empty files in your home directory"
		return
	fi
	for file in ${emptyfiles[@]}; do		
	rm -i ~/$file
	done
}

no_space (){
	used=$(df -h --total | grep -i total| tr -s ' ' : | cut -d: -f5 | tr -d %)
	if [ $used -gt 80 ]; then
		echo "More than 80% of space is used"
	else
		echo "Less than 80% of space is used"
	fi
}

while true; do
	echo "0 - End"
	echo "1 - Remove files of size 0 from my home directory"
	echo "2 - Check the space available at the root of the filesystem"
	read -p "Choose an item: " ch
	case $ch in
	0)
		exit
		;;
	1)
		echo " "
		sweep
		echo " "
		;;
	2)
		echo " "
		no_space
		echo " "
		;;
	*)
		echo " "
		echo "Invalid choice"
		echo " "
		;;		
	esac
done
