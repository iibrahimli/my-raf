#! /bin/bash

if [ $# -le 3 ]; then
echo "Error! Number of arguments isn't more than 3"
else
echo "The number of arguments : $#"
echo "The name of the script : $0"
echo "Value of first three arguments : $1 $2 $3"
echo "List of all arguments : $*"
echo "PID of the parent process : $PPID"
echo "Number of characters in first 3 args : $( echo -n $1 | wc -m ) $( echo -n $2 | wc -m ) $( echo -n $3 | wc -m ) "
fi

