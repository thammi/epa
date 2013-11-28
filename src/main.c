#include <stdio.h>
#include <time.h>
#include <time.h>

#include "list.h"
#include "matrix.h"

#define GRAPH_SIZE		1000
#define BENCH_FACT		50

void benchmark(int n) {
	// matrix

	clock_t matrix_start = clock();

	adj_matrix *matrix[BENCH_FACT];
	
	for(int i = 0; i < BENCH_FACT; ++i) {
		matrix[i] = create_adj_matrix(GRAPH_SIZE, n);
	}

	double matrix_time = (clock() - matrix_start) / (double) CLOCKS_PER_SEC / BENCH_FACT;

	for(int i = 0; i < BENCH_FACT; ++i) {
		free_adj_matrix(matrix[i]);
	}

	// list

	clock_t list_start = clock();

	adj_list *list[BENCH_FACT];
	
	for(int i = 0; i < BENCH_FACT; ++i) {
		list[i] = create_adj_list(GRAPH_SIZE, n);
	}

	double list_time = (clock() - list_start) / (double) CLOCKS_PER_SEC / BENCH_FACT;

	for(int i = 0; i < BENCH_FACT; ++i) {
		free_adj_list(list[i]);
	}

	// print

	printf("%d;%.4f;%.4f\n", n, matrix_time, list_time);
}

int main(int argc, char *args[]) {
	printf("n;matrix;list\n");

	benchmark(1);

	for(int i = 49; i < 2000; i += 50) {
		benchmark(i);
	}

	return 0;
}

