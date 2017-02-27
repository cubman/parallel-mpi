#include <windows.h>
#pragma hdrstop
#include "mpi.h"
#include "pt4.h"
void Solve()
{
    Task("MPIBegin7");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Status s;
	int n;
	if (rank > 0) {
		pt >> n;
		MPI_Send(&n, 1, MPI_INT, 0,0, MPI_COMM_WORLD);
	}
	else
		for (auto i = 1; i < size; ++i)
		{
			MPI_Recv(&n, 1, MPI_INT, i, 0, MPI_COMM_WORLD, &s);
			pt << n;
		}
	

}
