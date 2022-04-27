#!/bin/bash -l 
#SBATCH --job-name="poisson_omp" 
#SBATCH --account="uzh8" 
#SBATCH --time=00:05:00 
#SBATCH --nodes=1 
#SBATCH --ntasks-per-core=1 
#SBATCH --ntasks-per-node=1 
#SBATCH --cpus-per-task=4 
#SBATCH --partition=debug 
#SBATCH --constraint=mc 
#SBATCH --hint=nomultithread
#SBATCH --output=poisson_omp.logs 
#SBATCH --error=poisson_omp_errors.logs 


export OMP_NUM_THREADS=$SLURM_CPUS_PER_TASK 

srun ./main
