#include <windows.h>
#pragma hdrstop
#include "mpi.h"
#include "pt4.h"
void Solve()
{
    Task("MPIBegin24");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	int n;
	MPI_Status s;
	pt >> n;

	double * d = new double[n];
	for (auto i = 0; i < n; ++i)
		pt >> d[i];
	double b[5];

	MPI_Sendrecv(d, n, MPI_DOUBLE, rank ^ 1, 0, b, 5, MPI_DOUBLE, rank ^ 1, 0, MPI_COMM_WORLD, &s);
	MPI_Get_count(&s, MPI_DOUBLE, &n);

	for (int i = 0; i < n; ++i)
		pt << b[i];

	delete[]d;
}
