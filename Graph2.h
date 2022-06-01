//
// Created by nmls1 on 30/05/2022.
//

#ifndef PROJETODA_2_GRAPH2_H
#define PROJETODA_2_GRAPH2_H
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <list>
#include <algorithm>
#include "info.h"
//#include "MutablePriorityQueue.h"
#include "MaxHeapPriorityQueue.h"


#define INF (INT_MAX/2)

/************************* Vertex  **************************/

class Graph2{
    struct Edge {
        int dest;      // destination vertex
        int flow; // edge weight
        int capacity, duration;
    };

    struct Node {
        std::list<Edge> adj;
        int pred;
        int cap;
        int dur;
        int dist;
        bool visited;
    };

    int num_vertex;
    bool hasDir;
    std::vector<Node> all_vertex;

public:
    Graph2(int nodes, bool dir = false);

    std::vector<Node> getAllVertexs();
    Node findNode(int i);
    void addNode(int i);
    void addEdgeCapacity(int sourc, int dest, int c, int d);
    std::vector<int>path(int ori, int dest);
    int max_node_capacity(int n);
    void maxCapMinDist(int ori);
    void minDistMaxCap(int ori);
    //bool addVertex(const T &in);
    Node initSingleSourceCapacity(int origin);
    void maximizeCapacity(int ori);
    std::vector<Node> printCapacity(Node &source, Node &goal);
    bool operator<(Node & node) const;
    void print_flow();

};
#endif //PROJETODA_2_GRAPH2_H