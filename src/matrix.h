#ifndef MATRIX_H
#define MATRIX_H 

#include <stdlib.h>

typedef struct {
	char *data;
	size_t size;
} adj_matrix;

int matrix_add_edge(adj_matrix *matrix, int from, int to);
int matrix_remove_edge(adj_matrix *matrix, int from, int to);
int matrix_test_edge(adj_matrix *matrix, int from, int to);

adj_matrix *create_adj_matrix(size_t size, int n);
void free_adj_matrix(adj_matrix *matrix);

#endif /* MATRIX_H */
