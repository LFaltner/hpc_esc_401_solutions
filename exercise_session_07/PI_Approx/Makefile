CFLAGS=-O3 -ffast-math -mavx2
CC=mpicc

pi: pi.c
	${CC} ${CFLAGS} -o pi pi.c -lm
clean: 
	rm -f pi
