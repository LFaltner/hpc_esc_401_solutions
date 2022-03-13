CFLAGS=-Wall -O3 -fopenmp
LDFLAGS=-fopenmp
CC=gcc

cpi		: cpi.o gettime.o

cpi_mpi		: cpi_mpi.o gettime.o

cpi.o		: cpi.c gettime.h

cpi_mpi.o	: cpi_mpi.c gettime.h

gettime.o	: gettime.c gettime.h

sum 		: sum.o gettime.o -lm

sum.o		: sum.c gettime.h

sum_omp		: sum_omp.o gettime.o -lm

sum_omp.o	: sum_omp.c gettime.h

clean:
	rm -f cpi cpi.o gettime.o cpi_mpi cpi_mpi.o sum sum.o sum_omp sum_omp.o

all: cpi cpi_mpi sum
