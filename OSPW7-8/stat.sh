#! /bin/bash

fmt="%-14s%-20s%-12s\n"

file="students.txt"

while read -r line
do
	name=$(echo "$line" | cut -d"|" -f1)
	subj=$(echo "$line" | cut -d"|" -f2)
	res=$(echo "$line" | cut -d"|" -f3)
	printf $fmt "$name" "$subj" "$res"
done < $file


