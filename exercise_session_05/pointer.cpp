#include <iostream>
using std::cout;
using std::endl;
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int** M = new int *[2];
	M[0] = new int[5];
	M[1] = new int[5];
	for (int i=0;i<5;i++){
	M[0][i] = i;
	M[1][i] = 5+i;
	}
	
	// print M
	printf("M:\n");
	for(int i = 0; i < 2; i++) {
    for(int j = 0; j < 5; j++) {
        printf("%d ", M[i][j]);
    }
    printf("\n");
} 

	// transform M to generate M2
	int** M2 = new int *[2];
	*M2 = new int[5];
	*(M2+1) = new int[5];
	for (int i=0;i<5;i++){
	*(*M2+i) = *(*(M+1)+4-i);
	*(*(M2+1)+i) = *(*M+4-i);
	}

	// print M2
	printf("\nM2:\n");
	for(int i = 0; i < 2; i++) {
    for(int j = 0; j < 5; j++) {
        printf("%d ", M2[i][j]);
    }
    printf("\n");
} 

	return 0;
}
