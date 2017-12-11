#! /bin/bash

s1=yes
s2=no
mt=""
file1=report.pdf

#1
if [ $s1 == $s2 ];then
echo "\$s1 is equal to \$s2"
else
echo "\$s1 is not equal to \$s2"
fi

#2
if [ $s1 != $s2 ];then
echo "\$s1 is not equal to \$s2"
else
echo "\$s1 is equal to \$s2"
fi

#3
if [ -z $mt ];then
echo "\$mt is empty"
else
echo "\$mt is not empty"
fi

#4
if [ ! -z $mt ];then
echo "\$mt is not empty"
else
echo "\$mt is empty"
fi

#5
if [ $file1 = *.doc ];then
echo "\$file1 ends with .doc"
else
echo "\$file1 does not end with .doc"
fi

#6
if [[ $file1 = *.doc || $file1 = *.pdf ]];then
echo "\$file1 ends with .doc or .pdf"
else
echo "\$file1 does not end with .doc or .pdf"
fi
