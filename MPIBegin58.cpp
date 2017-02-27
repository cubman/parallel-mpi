#include <windows.h>
#pragma hdrstop
#include "mpi.h"
#include "pt4.h"
struct Triple {
	int a, b, c;
};

void Solve()
{
    Task("MPIBegin58");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	MPI_Datatype MPI_INT_TRIPLE;
	MPI_Type_contiguous(3, MPI_INT, &MPI_INT_TRIPLE);
	MPI_Type_commit(&MPI_INT_TRIPLE);
	Triple* outArr = new Triple[size - 1];

	if (rank == 0)
	{
		for (int i = 0; i < size - 1; ++i)
			pt >> outArr[i].a >> outArr[i].b >> outArr[i].c;
		
		for (int i = 1; i < size; ++i)
			MPI_Send(outArr, size - 1, MPI_INT_TRIPLE, i, 0, MPI_COMM_WORLD);
	}
	else
	{
		MPI_Recv(outArr, size - 1, MPI_INT_TRIPLE, 0, 0, MPI_COMM_WORLD, MPI_STATUSES_IGNORE);
		for (int i = 0; i < size - 1; ++i)
			pt << outArr[i].a << outArr[i].b << outArr[i].c;
	}
	delete outArr;
}
