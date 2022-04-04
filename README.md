# Graph Sum

# Overview

This is a university assignment in which we had to calculate all the indegrees
and outdegrees, sum them and ouput them to a file, together with the adjecency matrix.

This program takes as input the edge list from a file.

As an addition I also added a way to see the graph using graphviz.

# Dependencies

-make

# Usage

First build the project using make:
```
cd graph-sum
make
```

Then you can use it:
```
graph_sum input_file
```

The input file on the first line has to have the number of nodes, and 
then as many edges as you want, entered as pairs of nodes, the node numbers have to
be smaller than the total number of nodes.

The ouput is stored in output.txt, and the graphviz outputs the visible graph
in output.png.

