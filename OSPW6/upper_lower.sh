#! /bin/bash

if [ $# -ne 1 ]; then
	echo "No directory name is provided. Assuming current directory"
	dir=$(pwd)
fi

dir=$1

if [ ! -d $dir ]; then
	echo "$dir is not a directory"
fi

for file in $(ls $dir); do
	mv $dir/$file $dir/$(echo $file | tr [:upper:] [:lower:]) 2> /dev/null
done
