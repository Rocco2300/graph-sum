#include <stdio.h>

#include "graph_utils.h"


int main()
{
    graph* g;
    g = create_graph(3, 2);
    add_edge(g, 1, 2);
    add_edge(g, 3, 1);
    print_graph(g);
    destroy_graph(g);
    // FILE* file;
    // file = fopen("ceva.txt", "r");
    // if(file == NULL)
    // {
    //     printf("Error opening file!");
    //     return 0;
    // }
    // int var;
    // fscanf(file, "%d", &var);
    // for(int i = 0; i < var; i++)
    // {
    //     int x, y;
    //     fscanf(file, "%d %d", &x, &y);
    //     printf("%d %d\n", x, y);
    // }
    // fclose(file);
    return 0;
}