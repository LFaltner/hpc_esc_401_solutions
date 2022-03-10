#!/bin/bash -l
#SBATCH --job-name="cpi_omp"
#SBATCH --account="uzh8"
#SBATCH --mail-type=ALL
#SBATCH --mail-user=lukas.faltner@uzh.ch
#SBATCH --time=00:05:00
#SBATCH --nodes=1
#SBATCH --ntasks-per-core=1
#SBATCH --ntasks-per-node=1
#SBATCH --cpus-per-task=36
#SBATCH --partition=debug
#SBATCH --constraint=mc
#SBATCH --hint=nomultithread
#SBATCH --error=error_cpi_omp.log
#SBATCH --output=output_cpi_omp.log

export OMP_NUM_THREADS=$SLURM_CPUS_PER_TASK

srun cpi_omp
