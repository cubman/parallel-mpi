#include <windows.h>
#pragma hdrstop
#include "mpi.h"
#include "pt4.h"
void Solve()
{
    Task("MPIBegin3");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	int a;
	double b;
	if (!(rank % 2)) {
		pt >> a;
		pt << 2 * a;
	}
	else
	{
		pt >> b;
		pt << 2 * b;
	}
}
