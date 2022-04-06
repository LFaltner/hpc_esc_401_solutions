#!/bin/bash -l 
#SBATCH --job-name="nbody_serial" 
#SBATCH --account="uzh8" 
#SBATCH --time=00:05:00 
#SBATCH --nodes=1 
#SBATCH --ntasks-per-core=1 
#SBATCH --ntasks-per-node=1 
#SBATCH --cpus-per-task=36 
#SBATCH --partition=debug 
#SBATCH --constraint=mc 
#SBATCH --hint=nomultithread
#SBATCH --output=nbody_serial.logs 
#SBATCH --error=nbody_serial.err 

echo nbody_count,time > output_serial.csv
for n in 100 500 1000 5000 10000 20000 50000
do
	srun ./nbody_serial $n >> output_serial.csv
done
