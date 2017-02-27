#include <windows.h>
#pragma hdrstop
#include "mpi.h"
#include "pt4.h"
void Solve()
{
    Task("MPIBegin26");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	double d;
	int n;
	if (rank) {
		pt >> d >> n;
		MPI_Send(&d, 1, MPI_DOUBLE, 0, n, MPI_COMM_WORLD);
	}
	else
		for (auto i = 1; i < size; ++i)
		{
			MPI_Recv(&d, 1, MPI_DOUBLE, MPI_ANY_SOURCE, i, MPI_COMM_WORLD, MPI_STATUSES_IGNORE);
			pt << d;
		}
}
