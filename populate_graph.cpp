//
// Created by nmls1 on 22/05/2022.
//

#include <fstream>
#include "populate_graph.h"
#include "iostream"

populate_graph::populate_graph() {}

Graph2 populate_graph::read_tests(){
    int ori;
    int dest;
    int cap;
    int dur;

    std::ifstream fin("../Tests/intest2.txt");

    fin >> num_nodes >> num_branches;

    Graph2 g(num_nodes+1, true);

    while (fin >> ori >> dest >> cap >> dur){
        g.addEdgeCapacity(ori, dest, cap, dur);
    }

    fin.close();

    return g;

    //std::cout << info_vector.size();
}


