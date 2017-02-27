#include <windows.h>
#pragma hdrstop
#include "mpi.h"
#include "pt4.h"
void Solve()
{
    Task("MPIBegin56");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int sz = size + 5;
	double *sbuf = new double[sz];
	double *rbuf = new double[sz];

	for (int i = 0; i < sz; ++i)
		pt >> sbuf[i];

	MPI_Scan(sbuf, rbuf, sz, MPI_DOUBLE, MPI_PROD, MPI_COMM_WORLD);
	for (int i = 0; i < sz; ++i)
		pt << rbuf[i];

	delete sbuf;
	delete rbuf;
}
