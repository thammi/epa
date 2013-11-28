#include "list.h"

#include <string.h>

int list_add_edge(adj_list *lists, int from, int to) {
	adj_node *new_node = malloc(sizeof(adj_node));

	new_node->neighbour = to;
	new_node->next = lists->nodes[from];

	lists->nodes[from] = new_node;

	return 1;
}

int list_remove_edge(adj_list *lists, int from, int to) {
	adj_node **cur_ptr = &lists->nodes[from];

	while(*cur_ptr) {
		adj_node *cur = *cur_ptr;

		if(cur->neighbour == to) {
			*cur_ptr = cur->next;
			free(cur);

			return 1;
		}

		cur_ptr = &cur->next;
	}

	return 0;
}

int list_test_edge(adj_list *lists, int from, int to) {
	adj_node *cur = lists->nodes[from];

	while(cur) {
		if(cur->neighbour == to) {
			return 1;
		}

		cur = cur->next;
	}

	return 0;
}

adj_list *create_adj_list(size_t size, int n) {
	adj_list *list = malloc(sizeof(adj_list));
	list->size = size;

	size_t nodes_size = sizeof(*list->nodes) * size;

	list->nodes = malloc(nodes_size);
	memset(list->nodes, 0, nodes_size);

	const int p = n / 2;
	const int q = (n - 1) / 2;

	for(int i = 0; i < size; ++i) {
		for(int j = 0; j < size; ++j) {
			if(!(j + p < i || i + q < j)) {
				list_add_edge(list, i, j);
			}
		}
	}

	return list;
}

void free_adj_list(adj_list *list) {
	for(int i = 0; i < list->size; ++i) {
		adj_node *cur = list->nodes[i];

		while(cur) {
			adj_node *next = cur->next;
			free(cur);
			cur = next;
		}
	}

	free(list->nodes);
	free(list);
}

size_t list_mem(adj_list *list) {
	int count = 0;

	for(int x = 0; x < list->size; ++x) {
		for(int y = 0; y < list->size; ++y) {
			if(list_test_edge(list, x, y)) {
				++count;
			}
		}
	}

	return sizeof(*list) + list->size * sizeof(list->nodes) + count * sizeof(**list->nodes);
}

