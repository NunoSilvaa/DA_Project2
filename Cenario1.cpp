//
// Created by nmls1 on 22/05/2022.
//

#include "Cenario1.h"

Cenario1::Cenario1() {}

void Cenario1::maximizeCapacity(Graph2 &graph) {
    int ori=1, dest = 4;
    graph.maximizeCapacity(ori);
    std::vector<int> path = graph.path(ori, dest);
    for(int i = path.size() - 1; i >= 0; i--){
        std::cout << path[i] << " ";
    }
    std::cout << "max:" << graph.max_node_capacity(dest);
}

void Cenario1::maxCapMinDist(Graph2 &graph) {
    int ori = 1, dest = 4;
    //graph.maxCapMinDist(ori);
    //graph.minDistMaxCap(ori);
    /*std::vector<int> path = graph.path(ori, dest);
    for(int i = path.size() - 1; i >= 0; i--){
        std::cout << path[i] << " ";
    }
    std::cout << "max:" << graph.max_node_capacity(dest);*/
    graph.print_flow();
}