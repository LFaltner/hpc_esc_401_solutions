#!/bin/bash

if [ -z "$1" ]
  then
    echo "No argument supplied"
    exit 1
fi

if [ -f "$1" ] 
	then
		sed  's/.*/&\n\n\n/' "$1"
	else
		echo "File does not exist."
		exit 1
fi
