#!/bin/bash -l 
#SBATCH --job-name="nbody_omp" 
#SBATCH --account="uzh8" 
#SBATCH --time=00:05:00 
#SBATCH --nodes=1 
#SBATCH --ntasks-per-core=1 
#SBATCH --ntasks-per-node=1 
#SBATCH --cpus-per-task=12 
#SBATCH --partition=debug 
#SBATCH --constraint=mc 
#SBATCH --hint=nomultithread
#SBATCH --output=nbody_omp.logs 
#SBATCH --error=nbody_omp.err 


bash loop.sh
