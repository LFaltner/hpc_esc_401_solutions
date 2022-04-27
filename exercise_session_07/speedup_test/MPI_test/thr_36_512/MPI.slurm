#!/bin/bash -l
#SBATCH --job-name="MPI_36_512"
#SBATCH --account="uzh8"
#SBATCH --time=04:00:00
#SBATCH --nodes=1
#SBATCH --ntasks-per-core=1
#SBATCH --ntasks-per-node=36
#SBATCH --cpus-per-task=1
#SBATCH --partition=normal
#SBATCH --constraint=mc
#SBATCH --hint=nomultithread
#SBATCH --output=MPI_36_512.log
#SBATCH --error=MPI_36_512.err

export OMP_NUM_THREADS=$SLURM_CPUS_PER_TASK

module load daint-mc
module load PrgEnv-gnu

srun ../main
