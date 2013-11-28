#include "matrix.h"

#include <string.h>

int matrix_add_edge(adj_matrix *matrix, int from, int to) {
	const size_t i = from * matrix->size + to;
	matrix->data[i/8] |= 1 << i % 8;
	return 1;
}

int matrix_remove_edge(adj_matrix *matrix, int from, int to) {
	const size_t i = from * matrix->size + to;
	matrix->data[i/8] &= ~(1 << i % 8);
	return 1;
}

int matrix_test_edge(adj_matrix *matrix, int from, int to) {
	const size_t i = from * matrix->size + to;
	return matrix->data[i/8] & (1 << i % 8);
}

adj_matrix *create_adj_matrix(size_t size, int n) {
	adj_matrix *matrix = malloc(sizeof(adj_matrix));
	matrix->size = size;

	size_t data_size = size * size / 8;

	matrix->data = malloc(data_size);
	memset(matrix->data, 0, data_size);

	const int p = n / 2;
	const int q = (n - 1) / 2;

	for(int i = 0; i < size; ++i) {
		for(int j = 0; j < size; ++j) {
			if(!(j + p < i || i + q < j)) {
				matrix_add_edge(matrix, i, j);
			}
		}
	}

	return matrix;
}

void free_adj_matrix(adj_matrix *matrix) {
	free(matrix->data);
	free(matrix);
}

