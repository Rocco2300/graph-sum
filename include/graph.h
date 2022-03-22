#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>

typedef struct my_graph
{
    int num_nodes;
    int num_edges;
    int curr_num_edges;
    int** edges;
} graph;

graph* create_graph(int num_nodes, int num_edges);
void destroy_graph(graph* g);
void add_edge(graph* g, int first_node, int second_node);
void print_graph(graph* g);

#endif