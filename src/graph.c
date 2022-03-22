#include "graph.h"

#include <stdio.h>
#include <stdlib.h>

struct my_graph
{
    int num_nodes;
    int num_edges;
    int curr_num_edges;
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
    g->num_edges = num_edges;
    g->curr_num_edges = 0;

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

void add_edge(graph* g, int first_edge, int second_edge)
{
    if(first_edge <= 0 || first_edge > g->num_nodes ||
        second_edge <= 0 || second_edge > g->num_nodes) 
    {
        printf("Node outside of bounds!\n");
        return;
    }

    g->edges[g->curr_num_edges][0] = first_edge;
    g->edges[g->curr_num_edges][1] = second_edge;
    g->curr_num_edges++;
}

void print_graph(graph* g)
{
    for(int i = 0; i < g->num_edges; i++)
    {
        printf("%d -> %d\n", g->edges[i][0], g->edges[i][1]);
    }
}