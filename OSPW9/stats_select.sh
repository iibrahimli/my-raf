#! /bin/bash

fmt="%-14s%-10s%-12s\n"

file="students.txt"

lc=0

PS3="> "

while read -r line
do
	name[$lc]=$(echo "$line" | cut -d"|" -f1)
	class[$lc]=$(echo "$line" | cut -d"|" -f2)
	res[$lc]=$(echo "$line" | cut -d"|" -f3)
	printf $fmt "${name[$lc]}" "${class[$lc]}" "${res[$lc]}"
	lc=$((lc+1))
done < $file

select u in "Display students of given class" "Display GPA of a class" "Exit"
do
	if [ $REPLY -eq 1 ]; then
		echo "Enter the name of the class (needs to be exactly the same as in the file) :"
		read -r clname
		for cla in "${!class[@]}"; do
			if [ "${class[$cla]}" == "$clname" ]; then
				echo ${name[$cla]}
			fi
		done
	elif [ $REPLY -eq 2 ]; then
		echo "Enter the name of class (needs to be exactly the same as in the file) :"
		read -r clname
		count=1
		for cla in "${!class[@]}"; do
			if [ "${class[$cla]}" == "$clname" ]; then
				avg=$((avg+${res[$cla]}))
			counter=$((counter+1))			
			fi
		done
		avg=$((avg/counter))
		echo "GPA for the $clname class is $avg"
	else exit
	fi
done
