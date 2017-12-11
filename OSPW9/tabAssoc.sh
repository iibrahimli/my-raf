#! /bin/bash

declare -A class #keys=student names, values=class
declare -A sperc #keys=class,         values=# of students

file=students.txt

while read -r line
do
	if [ $line == "Name|Class|Result" ]; then
		continue
	fi
	class[$(echo "$line" | cut -d"|" -f1)]=$(echo "$line" | cut -d"|" -f2)
done < $file

for student in "${!class[@]}"
do
	sperc[${class[$student]}]=$((sperc[${class[$student]}]+1))
done

tput bold
printf "%-10s" "Class"
tput sgr0
printf "%-10s" "${!sperc[@]}"
printf "\n"
tput bold
printf "%-10s" "# of St."
tput sgr0
printf "%-10s" "${sperc[@]}"
printf "\n"
