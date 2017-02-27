#include <windows.h>
#pragma hdrstop
#include "mpi.h"
#include "pt4.h"
void Solve()
{
    Task("MPIBegin54");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int sz = 2 * size;
	double * in = new double[sz];
	double * out = new double[2];
	int * counts = new int[size];

	for (int i = 0; i < sz; ++i)
		pt >> in[i];

	for (int i = 0; i < size; ++i)
		counts[i] = 2;

	MPI_Reduce_scatter(in, out, counts, MPI_DOUBLE, MPI_MAX, MPI_COMM_WORLD);

	pt << out[0] << out[1];

	delete in;
	delete out;
	delete counts;
}
