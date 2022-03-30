#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int N = 1000;

struct complex_vector{
	int real;
	int im;
};

void linear_combination(struct complex_vector *x, struct complex_vector *y, int a);


int main(int argc, char** argv){
	
	// initialization and memory allocation
	struct complex_vector *x = malloc(N * sizeof(struct complex_vector));
	struct complex_vector *y = malloc(N * sizeof(struct complex_vector));

	int a = 10;

	// filling the vectors with random values in range [1,100]
	srand(1);
	int i;
	for (i = 0; i < N; i++) {
    x[i].real = rand() % 100 + 1;
    x[i].im = rand() % 100 + 1;
    y[i].real = rand() % 100 + 1;
    y[i].im = rand() % 100 + 1;
}


	// use linear_combination function for calculation
	linear_combination(x , y, a);
	return 0;
}

void linear_combination(struct complex_vector *x, struct complex_vector *y, int a){
	struct complex_vector z;
	z.real = x->real + a * y->real;
	z.im = x->im + a * x->im;

	printf("z = %d + %di\n", z.real, z.im);
}
