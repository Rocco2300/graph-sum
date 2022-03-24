#include <stdio.h>

#include "graph_io.h"
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        printf("No input file!\n");
        printf("Usage: %s input_file\n", argv[0]);
        system("PAUSE");
        return EXIT_FAILURE;
    }

    const char* input_path = argv[1];

    graph* g;
    g = input_graph(input_path);
    output_requirement("ouput.txt", g);
    output_graph("output.dot", g);
    system("dot -Tsvg output.dot > output.png");
    destroy_graph(g);

    return EXIT_SUCCESS;
}