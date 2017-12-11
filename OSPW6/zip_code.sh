#! /bin/bash

if [ $# -ne 1 ];then
	echo "Wrong number of arguments"
	echo "Usage: ./zip_code.sh <zipcode>"
fi
case $1 in
67[0-9][0-9][0-9])
	echo "$1 is a zip code from the area of Strasbourg"
	;;
[0-9][0-9][0-9][0-9][0-9])
	echo "$1 is a correct zip code, not from the area of Strasbourg"
	;;
*)
	echo "$1 is incorrect"
	;;
esac
