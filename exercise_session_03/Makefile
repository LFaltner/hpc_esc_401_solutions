cpi			: cpi.o gettime.o
	gcc -o cpi cpi.o gettime.o

cpi_mpi		: cpi_mpi.o gettime.o
	gcc -o cpi_mpi cpi_mpi.o gettime.o

cpi.o		: cpi.c gettime.h
	gcc -O3 -c -o cpi.o cpi.c

cpi_mpi.o	: cpi_mpi.c gettime.h
	gcc -O3 -o cpi_mpi.o cpi_mpi.c

gettime.o	: gettime.c gettime.h
	gcc -O3 -c -o gettime.o gettime.c

clean:
	rm -f cpi cpi.o gettime.o cpi_mpi cpi_mpi.o

all: cpi cpi_mpi
