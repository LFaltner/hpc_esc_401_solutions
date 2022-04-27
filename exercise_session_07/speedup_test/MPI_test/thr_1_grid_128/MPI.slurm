#!/bin/bash -l
#SBATCH --job-name="MPI_1_128"
#SBATCH --account="uzh8"
#SBATCH --time=04:00:00
#SBATCH --nodes=1
#SBATCH --ntasks-per-core=1
#SBATCH --ntasks-per-node=1
#SBATCH --cpus-per-task=1
#SBATCH --partition=normal
#SBATCH --constraint=mc
#SBATCH --hint=nomultithread
#SBATCH --output=MPI_1_128.log
#SBATCH --error=MPI_1_128.err

export OMP_NUM_THREADS=$SLURM_CPUS_PER_TASK

module load daint-mc
module load PrgEnv-gnu

srun ../main
