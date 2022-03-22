#include "graph_io.h"

graph* input_graph(const char* file_path)
{
    FILE* file;
    file = fopen(file_path, "r");
    if(file == NULL)
    {
        printf("Error opening file!");
        return;
    }

    int num_nodes;
    fscanf(file, "%d", &num_nodes);

    int x, y;
    int num_edges = 0;
    while(fscanf(file, "%d %d", &x, &y) != EOF)
    {
        num_edges++;
    }
    fseek(file, 1, SEEK_SET);

    graph* g = create_graph(num_nodes, num_edges);
    for(int i = 0; i < num_edges; i++)
    {
        fscanf(file, "%d %d", &x, &y);
        add_edge(g, x, y);
    }

    fclose(file);
    return g;
}

void output_graph(const char* file_path, graph* g)
{
    FILE* file;
    file = fopen(file_path, "w");
    if(file == NULL)
    {
        printf("Error opening file!");
        return;
    }

    fprintf(file, "digraph\n{\n");
    for(int i = 0; i < g->num_edges; i++)
    {
        fprintf(file, "\t%d -> %d\n", g->edges[i][0], g->edges[i][1]);
    }
    fprintf(file, "}\n");

    fclose(file);
}

void output_adj_mat(const char* file_path, int** mat, int size)
{
    FILE* file;
    file = fopen(file_path, "w");
    if(file == NULL)
    {
        printf("Error opening file!");
        return;
    }

    fprintf(file, "\n");
    fprintf(file, "Adjacency matrix: \n");
    for(int i = 0; i <= size; i++)
    {
        for(int j = 0; j <= size; j++)
        {
            if(i != 0 && j != 0)
                fprintf(file, "%d ", mat[i][j]);
            else if(i == 0 && j == 0)
                fprintf(file, "X ");
            else
                fprintf(file, "%d ", i == 0 ? j : i);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

void output_degrees(const char* file_path, int* deg, int size, char type)
{
    FILE* file;
    file = fopen(file_path, "a");
    if(file == NULL)
    {
        printf("Error opening file!");
        return;
    }

    fprintf(file, "\n");
    if(type == 'i')
        fprintf(file, "Indegrees: \n");
    else
        fprintf(file, "Outdegrees: \n");

    for(int i = 1; i <= size; i++)
    {
        fprintf(file, "deg(%d) = %d\n", i, deg[i]);
    }

    fclose(file);
}

void output_sums(const char* file_path, int in_sum, int out_sum)
{
    FILE* file;
    file = fopen(file_path, "a");
    if(file == NULL)
    {
        printf("Error opening file!");
        return;
    }

    fprintf(file, "\n");
    fprintf(file, "Insum: %d\n", in_sum);
    fprintf(file, "Outsum: %d\n", out_sum);
    fclose(file);
}

void output_requirement(const char* file_path, graph* g)
{
    int** mat = build_adj_mat(g);
    int* indegree = build_indegree(g);
    int* outdegree = build_outdegree(g);
    output_adj_mat(file_path, mat, g->num_nodes);
    output_degrees(file_path, indegree, g->num_nodes, 'i');
    output_degrees(file_path, outdegree, g->num_nodes, 'o');
    int is = get_indegree_sum(g);
    int os = get_outdegree_sum(g);
    output_sums(file_path, is, os);
    free(indegree);
    free(outdegree);
    destroy_adj_mat(mat, g->num_nodes);
}

void print_graph(graph* g)
{
    for(int i = 0; i < g->num_edges; i++)
    {
        printf("%d -> %d\n", g->edges[i][0], g->edges[i][1]);
    }
}

void print_adj_mat(int** mat, int size)
{
    for(int i = 0; i <= size; i++)
    {
        for(int j = 0; j <= size; j++)
        {
            if(i != 0 && j != 0)
                printf("%d ", mat[i][j]);
            else if(i == 0 && j == 0)
                printf("X ");
            else
                printf("%d ", i == 0 ? j : i);
        }
        printf("\n");
    }
}

void print_degrees(int* deg, int size, char type)
{
    if(type == 'i')
        printf("Indegrees: \n");
    else
        printf("Outdegrees: \n");

    for(int i = 1; i <= size; i++)
    {
        printf("deg(%d) = %d\n", i, deg[i]);
    }
}