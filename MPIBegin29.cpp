#include <windows.h>
#pragma hdrstop
#include "mpi.h"
#include "pt4.h"
void Solve()
{
	Task("MPIBegin29");
	int flag;
	MPI_Initialized(&flag);
	if (flag == 0)
		return;
	int rank, size;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	void * d = nullptr;
	int n, t, b;
	double a;
	MPI_Status s;
	if (rank) {
		pt >> t >> n;
		MPI_Send(&n, 1, MPI_INT, 0, t, MPI_COMM_WORLD);

		for (auto i = 0; i < n; ++i) {
			if (t)
				pt >> a;
			else
				pt >> b;
			MPI_Send(t ? &a : (void *)&b, 1, t ? MPI_DOUBLE : MPI_INT, 0, t, MPI_COMM_WORLD);
		}
	}
	else
		for (int i = 1; i < size; ++i)
		{
			MPI_Recv(&n, 1, MPI_INT, i, MPI_ANY_TAG, MPI_COMM_WORLD, &s);
			MPI_Probe(i, MPI_ANY_TAG, MPI_COMM_WORLD, &s);
			for (int j = 0; j < n; ++j)
				if (s.MPI_TAG)
				{
					MPI_Recv(&a, 1, MPI_DOUBLE, i, MPI_ANY_TAG, MPI_COMM_WORLD, &s);
					pt << a;
				}
				else
				{
					MPI_Recv(&b, 1, MPI_INT, i, MPI_ANY_TAG, MPI_COMM_WORLD, &s);
					pt << b;
				}
		}
}
