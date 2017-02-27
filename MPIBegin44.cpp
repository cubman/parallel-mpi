#include <windows.h>
#pragma hdrstop
#include "mpi.h"
#include "pt4.h"
void Solve()
{
	Task("MPIBegin44");
	int flag;
	MPI_Initialized(&flag);
	if (flag == 0)
		return;
	int rank, size;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	int * a = new int[3 * size];
	int * buf = new int[3 * size];
	for (auto i = 0; i < 3 * size; ++i)
		pt >> a[i];
	MPI_Alltoall(a, 3, MPI_INT, buf, 3, MPI_INT, MPI_COMM_WORLD);

	for (auto i = 0; i < 3 * size; ++i)
		pt << buf[i];
	delete a;
	delete buf;
}
