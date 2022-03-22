#include "graph_utils.h"

int** build_adj_mat(graph* g)
{
    int** mat;
    mat = calloc(g->num_nodes, sizeof(int*));

    if(mat == NULL)
    {
        free(mat);
        return;
    }

    for(int i = 0; i < g->num_nodes; i++)
    {
        mat[i] = calloc(g->num_nodes, sizeof(int));
        if(mat[i] == NULL)
            destroy_adj_mat(mat, g->num_nodes);
    }
    return mat;
}

void destroy_adj_mat(int** mat, int size)
{
    if(mat == NULL)
        return;

    for(int i = 0; i < size; i++)
    {
        if(mat[i] != NULL)
            free(mat[i]);
    }
    free(mat);
}

int* get_indegree(graph* g)
{
    int* rez = calloc(g->num_nodes + 1, sizeof(int));

    if(rez == NULL)
        return NULL;

    for(int i = 0; i < g->num_edges; i++)
    {
        rez[g->edges[i][1]]++;
    }

    return rez;
}

int* get_outdegree(graph* g)
{
    int* rez = calloc(g->num_nodes + 1, sizeof(int));

    if(rez == NULL)
        return NULL;

    for(int i = 0; i < g->num_edges; i++)
    {
        rez[g->edges[i][0]]++;
    }

    return rez;
}

int get_indegree_sum(graph* g)
{
    int sum = 0;
    int* degrees = get_indegree(g);

    for(int i = 1; i <= g->num_nodes; i++)
    {
        sum += degrees[i];
    }

    free(degrees);
    return sum;
}

int get_outdegree_sum(graph* g)
{
    int sum = 0;
    int* degrees = get_outdegree(g);

    for(int i = 1; i <= g->num_nodes; i++)
    {
        sum += degrees[i];
    }

    free(degrees);
    return sum;
}