#include <stdio.h>

#include "graph_utils.h"
#include "graph_io.h"

int main()
{
    graph* g;
    g = input_graph("input.txt");
    output_graph("graph.dot", g);
    // int** mat = build_adj_mat(g);
    // int* indegree = build_indegree(g);
    // int* outdegree = build_outdegree(g);
    // print_graph(g);
    // output_adj_mat("ceva.txt", mat, 3);
    // output_degrees("ceva.txt", indegree, 3, 'i');
    // output_degrees("ceva.txt", outdegree, 3, 'o');
    // int is = get_indegree_sum(g);
    // int os = get_outdegree_sum(g);
    // output_sums("ceva.txt", is, os);
    // free(indegree);
    // free(outdegree);
    // destroy_adj_mat(mat, 3);
    destroy_graph(g);
    return 0;
}