#include <windows.h>
#pragma hdrstop
#include "mpi.h"
#include "pt4.h"
void Solve()
{
    Task("MPIBegin38");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	auto k = size * (size + 3) / 2;
	int * a = new int[k];
	int * in = new int[rank + 2];
	int *c = new int[size];
	int *d = new int[size];

	for (int i = 0; i < size; ++i)
		c[i] = i + 2, d[i] = !i ? 0 : c[i - 1] + d[i - 1];	
		
	if (!rank)
		for (auto i = 0; i < k; ++i)
			pt >> a[i];

	MPI_Scatterv(a, c, d, MPI_INT, in, rank + 2, MPI_INT, 0, MPI_COMM_WORLD);
	for (int i = 0; i < rank + 2; ++i)
		pt << in[i];

	delete a;
	delete in;
	delete c;
	delete d;
}
