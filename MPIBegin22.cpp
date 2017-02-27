#include <windows.h>
#pragma hdrstop
#include "mpi.h"
#include "pt4.h"
void Solve()
{
    Task("MPIBegin22");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	double d;
	int n;

	pt >> n;
	if (n) 
		for (auto i = 0; i < size; ++i)
			if (i == rank)
				continue;
			else
			{
				pt >> d;
				MPI_Send(&d, 1, MPI_DOUBLE, i, 0, MPI_COMM_WORLD);
			}
	else
	{
		MPI_Recv(&d, 1, MPI_DOUBLE, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, MPI_STATUSES_IGNORE);
		pt << d;
	}

}
