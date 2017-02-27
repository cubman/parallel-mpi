#include <windows.h>
#pragma hdrstop
#include "mpi.h"
#include "pt4.h"
void Solve()
{
    Task("MPIBegin50");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	int sz = size + 5;
	std::pair<int, int> *sbuf = new std::pair<int, int>[sz];
	std::pair<int, int> *rbuf = new std::pair<int, int>[sz];

	for (int i = 0; i < sz; ++i) {
		pt >> sbuf[i].first;
		sbuf[i].second = rank;
	}

	MPI_Reduce(sbuf, rbuf, sz, MPI_2INT, MPI_MAXLOC, 0, MPI_COMM_WORLD);

	if (!rank) {
		for (int i = 0; i < sz; ++i)
			pt << rbuf[i].first;
		for (int i = 0; i < sz; ++i)
			pt << rbuf[i].second;
	}
		

	delete sbuf;
	delete rbuf;
}
