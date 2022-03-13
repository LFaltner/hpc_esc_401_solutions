#!/bin/bash -l
#SBATCH --job-name="cpi_mpi"
#SBATCH --account="uzh8"
#SBATCH --mail-type=ALL
#SBATCH --mail-user=lukas.faltner@uzh.ch
#SBATCH --time=00:01:00
#SBATCH --nodes=1
#SBATCH --ntasks-per-core=1
#SBATCH --ntasks-per-node=36
#SBATCH --cpus-per-task=1
#SBATCH --partition=debug
#SBATCH --constraint=mc
#SBATCH --hint=nomultithread
#SBATCH --error=error_cpi_mpi.log
#SBATCH --output=output_cpi_mpi.log


srun cpi_mpi
