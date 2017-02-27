#include <windows.h>
#pragma hdrstop
#include "mpi.h"
#include "pt4.h"
void Solve()
{
    Task("MPIBegin33");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int d[5];
	int * res = new int(5 * size);

	pt >> d[0] >> d[1] >> d[2] >> d[3] >> d[4];
	MPI_Gather(d, 5, MPI_INT, res, 5, MPI_INT, 0, MPI_COMM_WORLD);
	if (!rank)
		for (auto i = 0; i < 5 * size; ++i)
			pt << res[i];

}
