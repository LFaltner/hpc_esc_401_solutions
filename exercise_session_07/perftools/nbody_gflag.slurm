#!/bin/bash -l
#SBATCH --job-name="nbody_gflag"
#SBATCH --account="uzh8"
#SBATCH --time=00:5:00
#SBATCH --nodes=1
#SBATCH --ntasks-per-core=1
#SBATCH --ntasks-per-node=1
#SBATCH --cpus-per-task=1
#SBATCH --partition=debug
#SBATCH --constraint=mc
#SBATCH --hint=nomultithread
#SBATCH -o nbody_gflag.log
#SBATCH -e nbody_gflag.err

export OMP_NUM_THREADS=$SLURM_CPUS_PER_TASK

srun nbody_gflag