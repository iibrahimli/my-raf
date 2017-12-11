#! /bin/bash

#1
if [ -e /etc ]
then
echo "/etc exists"
else
echo "/etc doesn't exist"
fi

#2
if [ -r /etc/hosts ];then
echo "/etc/hosts is readable"
else
echo "/etc/hosts is not readable"
fi

#3
if [ -x /etc/hosts ];then
echo "/etc/hosts is executable"
else
echo "/etc/hosts is not executable"
fi

#4
if [ -d /usr ] && [ -x /usr ];then
echo "/usr can be visited"
else
echo "/usr cannot be visited"
fi

#5
if [ -c /dev/null ];then
echo "/dev/null is a special device file"
else
echo "/dev/null is not a special device file"
fi


