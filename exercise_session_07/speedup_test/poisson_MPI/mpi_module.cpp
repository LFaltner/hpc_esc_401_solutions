#include "mpi.h"
#include <stdio.h>
#include "init.h"

int start_MPI(int* my_rank, int* size){
	printf("Setting MPI environment\n");
	MPI_Init(NULL,NULL);
	MPI_Comm_size(MPI_COMM_WORLD,size);
	MPI_Comm_rank(MPI_COMM_WORLD,my_rank);

	return 0;
}

int close_MPI(){
	MPI_Finalize();
	return 0;
}

int mpi_get_domain(int nx, int ny, int my_rank, int size, int* min_x, int* max_x, int* min_y, int* max_y){
	/*
	define corners or local domains
	*/

	// y values are the same for every rank
	*min_y = 0;
	*max_y = ny;

	// define x boundaries - the last rank will compute the remenants of the division
	*min_x = nx / size * my_rank;
	if (my_rank == size - 1)
	{
		*max_x = nx;
	}
	else
	{
		*max_x = nx / size * (my_rank + 1);
	}

	
    // printf("in mpi_get_domain() in mpi_module.cpp,  define corners of the local domains\n");

	printf("I am rank %d and my domain is: xmin, xmax, ymin, ymax: %d %d %d %d\n",my_rank,*min_x,*max_x,*min_y,*max_y);
	return 0;
}


int halo_comm(params p, int my_rank, int size, double** u, double* fromLeft, double* fromRight) {
	// no comm necessary if only 1 thread is used
	if (size == 1)
	{
		return 0;
	}

	/*this function, vectors fromLeft and fromRight should be received from the neighbours of my_rank process*/
	for (int j=0;j<(p.ymax - p.ymin);j++) {fromLeft[j] = 0; fromRight[j] = 0;} //initialize fromLeft and fromRight

	/* define columns to be sent to right neighbour and to the left neighbour,
    also receive one both form left and right neighbour*/
	 
	/*Compute the ranks of left/right neighbours 
    Compute first rank (= rank 0)*/
    
	int left_rank, right_rank;

    if (my_rank == 0)
    {
        left_rank = size - 1;  // last rank = size - 1 as numbering starts with 0
        right_rank = 1;
    }

    // Compute last rank (= rank size -1 )
    else if (my_rank == size - 1)
    {
        left_rank = size - 2;
        right_rank  = 0;
    }

    // Compute ranks in between
    else
    {
        left_rank = my_rank - 1;
        right_rank = my_rank + 1;
    }

    int diff_x = p.xmax - p.xmin;

    MPI_Datatype column_type;
    MPI_Type_vector(p.ymax - p.ymin, 1, 1, MPI_DOUBLE, &column_type);
    MPI_Type_commit(&column_type);

    MPI_Request requests[4];
    MPI_Status status[4];
  
    for (int i = 0; i < 4; ++i)
    {
        requests[i] = MPI_REQUEST_NULL;
    }

    //  send to right and left, receive from right and left, then wait for all requests to finish
    //  first and last rank need to be treated differently
    if (my_rank == 0)
    {
    	MPI_Isend(&u[diff_x - 1 ][0], 1, column_type, right_rank, 0, MPI_COMM_WORLD, &requests[0]);
    	MPI_Irecv(fromRight, 1, column_type, right_rank, 0, MPI_COMM_WORLD, &requests[1]);
    }

    else if (my_rank == size - 1)
    {
    	MPI_Isend(&u[0][0], 1, column_type, left_rank, 0, MPI_COMM_WORLD, &requests[2]);
    	MPI_Irecv(fromLeft, 1, column_type, left_rank, 0, MPI_COMM_WORLD, &requests[3]);
    }
    else
    {
    	MPI_Isend(&u[diff_x - 1 ][0], 1, column_type, right_rank, 0, MPI_COMM_WORLD, &requests[0]);
    	MPI_Irecv(fromRight, 1, column_type, right_rank, 0, MPI_COMM_WORLD, &requests[1]);
    	MPI_Isend(&u[0][0], 1, column_type, left_rank, 0, MPI_COMM_WORLD, &requests[2]);
    	MPI_Irecv(fromLeft, 1, column_type, left_rank, 0, MPI_COMM_WORLD, &requests[3]);
    }
	
	MPI_Waitall(4, requests, status);

    MPI_Type_free(&column_type);

	return 0;
}


int ALLREDUCE(double* loc_diff, double* loc_sumdiff){

	MPI_Allreduce(loc_diff, loc_sumdiff, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
	return 0;

	}

