#!/bin/bash -l
#SBATCH --job-name="OMP_128"
#SBATCH --account="uzh8"
#SBATCH --time=04:00:00
#SBATCH --nodes=1
#SBATCH --ntasks-per-core=1
#SBATCH --ntasks-per-node=1
#SBATCH --cpus-per-task=36
#SBATCH --partition=normal
#SBATCH --constraint=mc
#SBATCH --hint=nomultithread
#SBATCH --output=OMP_128.log
#SBATCH --error=OMP_128.err

export OMP_NUM_THREADS=1
../main

export OMP_NUM_THREADS=4
../main

export OMP_NUM_THREADS=16
../main

export OMP_NUM_THREADS=36
../main
