#! /bin/bash

echo "Write one number per line, ^D to display the sum:"

sum=0

while read -r n; do
    ((sum += n))
done
echo "Sum = $sum"
