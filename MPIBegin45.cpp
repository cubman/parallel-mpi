#include <windows.h>
#pragma hdrstop
#include "mpi.h"
#include "pt4.h"
void Solve()
{
    Task("MPIBegin45");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	int k = size * (size + 1) / 2;
	int sz = (rank + 1) * size;
	int *sbuf = new int[k];
	int *rbuf = new int[sz];
	int *scounts = new int[size];
	int *rcounts = new int[size];
	int *sdispls = new int[size];
	int *rdispls = new int[size];

	for (int i = 0; i < size; ++i)
	{
		scounts[i] = i + 1;
		rcounts[i] = rank + 1;
		rdispls[i] = (rank + 1) * i;
		sdispls[i] = !i ? 0 : scounts[i - 1] + sdispls[i - 1];
	}

	for (int i = 0; i < k; i++)
		pt >> sbuf[i];

	MPI_Alltoallv(sbuf, scounts, sdispls, MPI_INT, rbuf, rcounts, rdispls, MPI_INT, MPI_COMM_WORLD);

	for (int i = 0; i < sz; ++i)
		pt << rbuf[i];

	delete sbuf;
	delete rbuf;
	delete scounts;
	delete rcounts;
	delete sdispls;
	delete rdispls;
}
