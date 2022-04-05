#!/bin/bash -l 

echo nbody_count,time > output_serial.csv
for n in 100 500 1000 5000 10000 20000 50000
do
	./nbody $n >> output_serial.csv
done