#include <windows.h>
#pragma hdrstop
#include "mpi.h"
#include "pt4.h"
void Solve()
{
    Task("MPIBegin5");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	int N;

	pt >> N;
	double sum = 0, a = 0;

	for (auto i = 0; i < N; ++i, sum += a)
		pt >> a;

		pt << (rank % 2 ? sum / N : sum);


}
