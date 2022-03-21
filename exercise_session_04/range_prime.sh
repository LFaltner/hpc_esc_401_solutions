#!/bin/bash

input="$@"

# check for input
if ! [ $# -eq 2 ]; then
    echo "error: No or wrong number of arguments supplied, requires two integers" >&2; exit 1
fi

# check if input is an integer
regex='^[0-9]+$'
if ! [[ "$1" =~ $regex ]] ; then
   echo "error: Not a number: "$1"" >&2; exit 1

elif ! [[ "$2" =~ $regex ]] ; then
   echo "error: Not a number: "$2"" >&2; exit 1  
fi

# check if first input is smaller than second
if (("$1" >= "$2")); then
	echo "error: first number has to be smaller than second number" >&2; exit 1
fi


function prime() 
{

# use factor and wc to test if prime
res=$(factor $number_in | wc -w)
if ! (( $res > 2 )); then
	echo "$number_in is prime"
fi
}

for number_in in  $(seq "$1" "$2"); do
	prime $number_in
done
