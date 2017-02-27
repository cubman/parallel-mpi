#include <windows.h>
#pragma hdrstop
#include "mpi.h"
#include "pt4.h"
void Solve()
{
    Task("MPIBegin31");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	double d[5];
	if (!rank) 
		pt >> d[0] >> d[1] >> d[2] >> d[3] >> d[4];

		MPI_Bcast(d, 5, MPI_DOUBLE, 0, MPI_COMM_WORLD);
	if (rank)
		pt << d[0] << d[1] << d[2] << d[3] << d[4];
	
}
