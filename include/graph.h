#ifndef GRAPH_H
#define GRAPH_H

typedef struct my_graph graph;

graph* create_graph(int num_nodes, int num_edges);
void destroy_graph(graph* g);
void add_edge(graph* g, int first_node, int second_node);
void print_graph(graph* g);

#endif