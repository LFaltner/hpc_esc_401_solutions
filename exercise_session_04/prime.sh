#!/bin/bash

number_in="$1"

# check for input
if [ -z $number_in ]; then
    echo "error: No argument supplied" >&2; exit 1
fi


# check if input is an integer
regex='^[0-9]+$'
if ! [[ $number_in =~ $regex ]] ; then
   echo "error: Not a number: $number_in" >&2; exit 1
fi

# use factor and wc to test if prime
res=$(factor $number_in | wc -w)
if (( $res > 2 )); then
	echo "$number_in is composite"; exit 0
else
	echo "$number_in is prime"; exit 0
fi