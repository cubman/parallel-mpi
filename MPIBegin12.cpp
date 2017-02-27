#include <windows.h>
#pragma hdrstop
#include "mpi.h"
#include "pt4.h"
void Solve()
{
    Task("MPIBegin12");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Status s;
	double d;
	if (rank == 0) {
		int bufSize = sizeof(double) * size + MPI_BSEND_OVERHEAD;
		void *buffer = (void *)malloc(bufSize);
		MPI_Buffer_attach(buffer, bufSize);

		for (auto i = size - 1; i > 0; --i)
		{
			pt >> d;
			MPI_Bsend(&d, 1, MPI_DOUBLE, i, 0, MPI_COMM_WORLD);
		}

		MPI_Buffer_detach(buffer, &bufSize);
		free(buffer);
	}
	else {
		MPI_Recv(&d, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, &s);
		pt << d;
	}
}
