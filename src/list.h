#ifndef LIST_H
#define LIST_H 

#include <stdlib.h>

typedef struct adj_node {
	int neighbour;
	struct adj_node *next;
} adj_node;

typedef struct {
	adj_node **nodes;
	size_t size;
} adj_list;

int list_add_edge(adj_list *lists, int from, int to);
int list_remove_edge(adj_list *lists, int from, int to);
int list_test_edge(adj_list *lists, int from, int to);

adj_list *create_adj_list(size_t size, int n);
void free_adj_list(adj_list *list);

size_t list_mem(adj_list *list);

#endif /* LIST_H */
