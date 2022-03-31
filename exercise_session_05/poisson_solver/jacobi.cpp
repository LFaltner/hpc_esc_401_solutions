#include "jacobi.h"
#include <math.h>

/**
 * @brief      Computes norm of the difference between two matrices
 *
 * @param[in]  p     Parameters
 * @param      mat1  The matrix 1
 * @param      mat2  The matrix 2
 *
 * @return     Returns \sqrt{\sum(mat1_{ij} - mat2_{ij})^2/(nx*ny)}
 */
double norm_diff(params p, double** mat1, double** mat2){
    int sumOfSqMat1 = 0;
    int sumOfSqMat2 = 0;

    for(int i=0; i<p.nx ;i++){
        for(int j=0; j<p.ny; j++){
      sumOfSqMat1 += (mat1[i][j] * mat1[i][j]); 
      sumOfSqMat2 += (mat2[i][j] * mat2[i][j]);
    }
  }    
    double res = sqrt((sumOfSqMat1 - sumOfSqMat2)^2/(p.nx*p.ny));
    return res;
}

/**
 * @brief      Compute a Jacobi iteration to solve Poisson equation. This function updates
 *             u_new and u_old in-place.
 *
 * @param[in]  p      Parameters
 * @param      u_new  The new solution
 * @param      u_old  The old solution
 * @param      f      The source term
 */
void jacobi_step(params p, double** u_new, double** u_old, double** f){
    double dx = 1.0/(double(p.nx - 1));
    double dy = 1.0/(double(p.ny - 1));

    for (int i=0; i<p.nx; i++){
        for (int j=0; j<p.ny; j++){
            u_old[i][j] = u_new[i][j];
        }
    }
    printf("Function jacobi_step (jacobi.cpp l.26): not implemented.\n");
}
