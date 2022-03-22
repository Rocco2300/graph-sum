#ifndef GRAPH_UTILS_H
#define GRAPH_UTILS_H

#include "graph.h"

int** build_adj_mat(graph* g);
void destroy_adj_mat(int** mat, int size);
int* get_indegree(graph* g);
int* get_outdegree(graph* g);
int get_indegree_sum(graph* g);
int get_outdegree_sum(graph* g);

#endif