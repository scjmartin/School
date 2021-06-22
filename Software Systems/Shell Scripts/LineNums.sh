#!/bin/bash                                                                               \

#Scott Martin
#HW3
#CS-270
#04/15/20
#LineNums.sh

echo enter a file name.
read fileName

touch tempFile.txt
ln=1
zero=0

# Reads first value of a string.
while read line; do

    temp="${line}"
    pat='^[0-9]'

    # Checks if file has line numbers or not.
    if [[ $temp =~ $pat ]]

       # Line numbers are present, will remove line numbers.
    then
	echo "Removing line number"
	echo "${line:3}" >> "tempFile.txt"

	# Line numbers are not present, adds line numbers.
    else
	if [[ ln -lt 10 ]]
	then
	    echo "Adding line number"
	    echo "$[zero]${ln} ${line}" >> "tempFile.txt"
	    let "ln++"

	else
	    echo "Adding line number"
	    echo "${ln} ${line}" >> "tempFile.txt"
	    let "ln++"

	fi

    fi

done < $fileName

mv "tempFile.txt" $fileName

echo
echo "Printing the file after the script "
cat $fileName
echo

