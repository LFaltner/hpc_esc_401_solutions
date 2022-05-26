#!/bin/bash -l
#SBATCH --job-name="axpy_openacc"
#SBATCH --account="uzg2"
#SBATCH --time=00:05:00
#SBATCH --nodes=1
#SBATCH --ntasks-per-core=1
#SBATCH --ntasks-per-node=1
#SBATCH --cpus-per-task=1
#SBATCH --partition=debug
#SBATCH --constraint=gpu
#SBATCH --hint=nomultithread

export OMP_NUM_THREADS=$SLURM_CPUS_PER_TASK
export CRAY_CUDA_MPS=1

srun -n 1 ./axpy.openacc 2
srun -n 1 ./axpy.openacc 6
srun -n 1 ./axpy.openacc 10
srun -n 1 ./axpy.openacc 14