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
//#include "MutablePriorityQueue.h"
#include "MaxHeapPriorityQueue.h"


#define INF (INT_MAX/2)

/************************* Vertex  **************************/

class Graph2{
    struct Edge {
        int from;
        int dest;      // destination vertex
        int flow; // edge weight
        int capacity, duration;
        //Edge* residualEdge;
        bool visited = true;
        /*Edge(int from, int dest, int flow, int capacity, int duration, bool visited){
            this->from = from;
            this->dest = dest;
            this->flow = flow;
            this->capacity = capacity;
            this->duration = duration;
            this->visited = visited;
        };*/
    };

    struct Node {
        std::list<Edge> adj;
        std::list<Edge*> residual;
        int pred;
        int cap;
        int dur;
        int dist;
        Edge predEdge = Edge{0,0,0,0,0, true};
        bool visited;
    };

    int num_vertex;
    //int maxFlow;
    std::list<std::pair<std::list<int>,int>> allPaths = {};
    bool hasDir;
    std::vector<Node> all_vertex;

public:
    Graph2(int nodes, bool dir = false);

    std::vector<Node> getAllVertexs();
    int getMaxFlow(int dest);
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
    bool bfs(int ori, int dest);
    int findMaxFlowEK(int ori, int dest);
    void updateFlows(int ori, int dest, int flow);
    void updateAdj();
    void edmondsKarp(int ori, int dest);
    bool edmondsKarpGroupSize(int ori, int dest, int size);
    void calculate_flow();
    bool path_checker(int ori, int dest, std::vector<Edge*> &edges);
    void printAllPaths();
    int reuniteGroup(int ori, int dest, int size);

};
#endif //PROJETODA_2_GRAPH2_H
