#include <windows.h>
#pragma hdrstop
#include "mpi.h"
#include "pt4.h"
void Solve()
{
    Task("MPIBegin15");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	int N;
	double a;
	MPI_Status s;
	if (rank) {
		pt >> N;
		if (N) {
			MPI_Send(&N, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
			for (auto i = 0; i < N; ++i) {
				pt >> a;
				MPI_Send(&a, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
			}
			MPI_Send(&rank, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
		}
	}
	else
	{
		MPI_Recv(&N, 1, MPI_INT, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, &s);
		
		for (int i = 0; i < N; ++i)
		{
			MPI_Recv(&a, 1, MPI_DOUBLE, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, &s);
			pt << a;
		}
		MPI_Recv(&N, 1, MPI_INT, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, &s);
		pt << N;
	}
}
