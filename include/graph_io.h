#ifndef GRAPH_IO_H
#define GRAPH_IO_H

#include "graph_utils.h"

graph* input_graph(const char* file_path);
void output_graph(const char* file_path, graph* g);

void output_adj_mat(const char* file_path, int** mat, int size);
void output_degrees(const char* file_path, int* deg, int size, char type);
void output_sums(const char* file_path, int in_sum, int out_sum);
void output_requirement(const char* file_path, graph* g);

// For debugging
void print_graph(graph* g);
void print_adj_mat(int** mat, int size);
void print_degrees(int* deg, int size, char type);

#endif