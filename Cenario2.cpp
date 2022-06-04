//
// Created by nmls1 on 01/06/2022.
//

#include "Cenario2.h"

Cenario2::Cenario2() {}

void Cenario2::c1_1(Graph2 & graph) {
    int ori, dest;
    std::vector<std::pair<int, std::vector<int>>> allPaths;
    graph.edmondsKarp(1, 6,5, allPaths);
    for(auto e : allPaths){
        std::cout << "cap:" <<e.first << " (";
        for(int i = e.second.size()-1; i >= 0; i--){
            if(i == 0)
                std::cout << e.second[i] << ")";
            else
                std::cout << e.second[i] << "->";
        }
    }
    //std::cout << graph.bfs(1, 6) << " "/*graph.edmondsKarp(ori, dest)*/;
}