#!/bin/bash
(cat Files.txt | while read line 
do
   cat $line | ./mapper.py;
done ) | sort | ./reducer.py
