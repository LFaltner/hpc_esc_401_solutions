#include "mpi.h"
#include <stdio.h>
#include <math.h>

int main(int argc, char** argv) {
    // variable declaration
    long int n_terms = 1000000000;
    double partial_pi=0.0, term, pi;

    // Initialize the MPI environment
    MPI_Init(NULL, NULL);

    // Get the number of processes and rank of the process
    int size, my_rank;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

	// Applying the Leibniz Formula
	for(long int i=0; i < n_terms; i++)
	{
	term = pow(-1, i) / (2 * i + 1);
	partial_pi += term;
	}
	
	// Reduction step
	MPI_Reduce(&partial_pi, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
	
	if (my_rank == 0)
	{
		pi = 4 * partial_pi;
		printf("\nApproximation for PI = %.15lf\n", pi);
	}
	
    // Finalize the MPI environment.
    MPI_Finalize();
}
