#!/bin/bash

input="$@"

# check for input
if [ $# -eq 0 ]; then
    echo "error: No argument supplied" >&2; exit 1
fi


function prime() 
{
# check if input is an integer
regex='^[0-9]+$'
if ! [[ $number_in =~ $regex ]] ; then
   echo "error: Not a number: $number_in" >&2; exit 1
fi

# use factor and wc to test if prime
res=$(factor $number_in | wc -w)
if (( $res > 2 )); then
	echo "$number_in is composite"
else
	echo "$number_in is prime"
fi
}

for number_in in $input; do
	prime $number_in
done
