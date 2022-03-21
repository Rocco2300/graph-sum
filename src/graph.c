#include "graph.h"

#include <stdlib.h>

struct my_graph
{
    int num_nodes;
    int num_edges;
    int** edges;
};

graph* create_graph(int num_nodes, int num_edges)
{
    graph* g = malloc(sizeof(*g));
    if(g == NULL)
    {
        return NULL;
    }
    g->num_nodes = num_nodes;

    g->edges = calloc(num_edges, sizeof(int*));
    if(g->edges == NULL)
    {
        free(g);
        return NULL;
    }

    for(int i = 0; i < num_edges; i++)
    {
        g->edges[i] = calloc(2, sizeof(int));
        if(g->edges[i] == NULL)
        {
            destroy_graph(g);
            return NULL;
        }
    }
    return g;
}

void destroy_graph(graph* g)
{
    if(g->edges == NULL)
        return;
    
    for(int i = 0; i < g->num_edges; i++)
    {
        if(g->edges[i] != NULL)
            free(g->edges[i]);
    }
    free(g->edges);
}
