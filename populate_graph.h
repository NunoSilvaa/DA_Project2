//
// Created by nmls1 on 22/05/2022.
//

#ifndef PROJETODA_2_POPULATE_GRAPH_H
#define PROJETODA_2_POPULATE_GRAPH_H

#include "vector"
#include "Graph.h"
#include "info.h"


class populate_graph {
    int num_nodes;
    int num_branches;
    std::vector<info> info_vector;
    Graph<int> g;
public:
    populate_graph();

    void read_tests();
    void build_graph();

    int maximize_group(int ori, int dest);
};


#endif //PROJETODA_2_POPULATE_GRAPH_H
