#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int N = 1000;

struct complex_vector{
	double real;
	double im;
};


int main(int argc, char** argv){
	
	// initialization and memory allocation
	struct complex_vector *x = malloc(N * sizeof(struct complex_vector));
	struct complex_vector *y = malloc(N * sizeof(struct complex_vector));

	double *a = malloc(sizeof(double));

	// filling the vectors with random values

	// define function for calculation

}