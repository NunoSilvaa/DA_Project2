//
// Created by nmls1 on 22/05/2022.
//

#include <fstream>
#include "populate_graph.h"
#include "iostream"
#include "info.h"

populate_graph::populate_graph() {}

void populate_graph::read_tests(){
    int ori;
    int dest;
    int cap;
    int dur;
    info information;

    std::ifstream fin("../Tests/intest.txt");

    fin >> num_nodes >> num_branches;

    while (fin >> ori >> dest >> cap >> dur){
        information.setOrigin(ori);
        information.setDestiny(dest);
        information.setCapacity(cap);
        information.setDuration(dur);
        info_vector.push_back(information);
    }

    fin.close();

    //std::cout << info_vector.size();
}

void populate_graph::build_graph() {
    for(int i = 0; i < num_nodes; i++){
        g.addVertex(i);
    }
    for(int i = 0; i < info_vector.size(); i++){
        g.addEdgeCapacity(info_vector[i].getOrigin(), info_vector[i].getDestiny(), info_vector[i].getCapacity(), info_vector[i].getDuration());
    }
}

int populate_graph::maximize_group(int ori, int dest){
    //std::cout << g.getNumVertex();
    g.maximizeCapacity(ori);
}

