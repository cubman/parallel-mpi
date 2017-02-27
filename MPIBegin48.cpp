#include <windows.h>
#pragma hdrstop
#include "mpi.h"
#include "pt4.h"
void Solve()
{
    Task("MPIBegin48");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	int sz = size + 5;
	int *sbuf = new int[sz];
	int *rbuf = new int[sz];

	for (int i = 0; i < sz; ++i) 
		pt >> sbuf[i];

	MPI_Reduce(sbuf, rbuf, sz, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

	if (!rank) 
		for (int i = 0; i < sz; ++i) 
			pt << rbuf[i];
		
	delete sbuf;
	delete rbuf;
}
