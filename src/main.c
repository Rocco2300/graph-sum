#include <stdio.h>

#include "graph_io.h"

int main(int argc, char* argv[])
{
    if(argc == 1)
    {
        printf("No input file!\n");
        printf("Usage: \n");
        printf("%s [options] input_file [output_file]\n", argv[0]);
    }
    else if(argc == 2)
    {
        const char* input_path = argv[1];

        graph* g;
        g = input_graph(input_path);
        output_requirement("ouput.txt", g);
    }

    return 0;
}