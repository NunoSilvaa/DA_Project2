//
// Created by nmls1 on 01/06/2022.
//

#include "Cenario2.h"

Cenario2::Cenario2() {}

void Cenario2::c2_1_2_2(Graph2 & graph) {
    int ori, dest, size, plus;
    if(graph.edmondsKarpGroupSize(ori, dest, size)){
        std::cout << "maxFlow: " << graph.getMaxFlow(dest) << "\n";
        graph.printAllPaths();
    }
    std::cout << "How many people do you want to add? ";
    std::cin >> plus;
    if(graph.edmondsKarpGroupSize(ori, dest, size + plus)){
        std::cout << "maxFlow: " << graph.getMaxFlow(dest) << "\n";
        graph.printAllPaths();
    }
    /*for(auto e : allPaths){
        std::cout << "cap:" <<e.first << " (";
        for(int i = e.second.size()-1; i >= 0; i--){
            if(i == 0)
                std::cout << e.second[i] << ")";
            else
                std::cout << e.second[i] << "->";
        }
    }*/
    //std::cout << graph.bfs(1, 6) << " "/*graph.edmondsKarp(ori, dest)*/;
}

void Cenario2::c2_2(Graph2 & graph) {
    int ori=1, dest=6, size=10, plus;
    if(graph.edmondsKarpGroupSize(ori, dest, size)){
        //std::cout << "maxFlow: " << graph.getMaxFlow(dest) << "\n";
        graph.printAllPaths();
        std::cout << graph.reuniteGroup(ori, dest, size);
    }
}