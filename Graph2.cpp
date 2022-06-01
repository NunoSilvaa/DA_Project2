//
// Created by nmls1 on 31/05/2022.
//

#include "Graph2.h"
//#include "MaxHeapPriorityQueue.h"
#include "MaxHeapPQ.h"
#include "MinHeapPQ.h"

Graph2::Graph2(int num, bool dir) : num_vertex(num), hasDir(dir), all_vertex(num+1) {
}

std::vector<Graph2::Node> Graph2::getAllVertexs() {
    return this->all_vertex;
}

Graph2::Node Graph2::findNode(int i) {
    return all_vertex[i];
}

void Graph2::addNode(int i) {
    Node node;
    node.pred = 0;
    node.visited = false;
    all_vertex.push_back(node);
}

void Graph2::addEdgeCapacity(int sourc, int dest, int c, int d) {
    if (sourc < 1 || sourc >= num_vertex || dest < 1 || dest > num_vertex) return;
    all_vertex[sourc].adj.push_back(Edge{dest,0 ,c, d});
    all_vertex[dest].residual.push_back(Edge{sourc, 0, 0, d});
    if (!hasDir) all_vertex[dest].adj.push_back(Edge{dest, 0, c, d});
}

void Graph2::maximizeCapacity(int ori) {
    for(int v = 1; v <= num_vertex; v++) {
        all_vertex[v].cap = 0;
        all_vertex[v].pred = 0/*nullptr*/;
    }
    all_vertex[ori].cap = INF;
    MaxHeapPQ<int, int> q(num_vertex, -1);
    // Adicionar todos os nodes
    //std::cout << q.getSize();
    for(int n = 1; n <= num_vertex; n++){
        q.insert(n, all_vertex[n].cap);
        //std::cout << n->cap << " ";
    }
    //std::cout << q.getSize();
    //q.print(); //all ok
    while( !q.empty() ) {
        //std::cout << " size:" << q.getSize() << " ";
        //std::cout << " One" << " ";
        q.print();
        int v = q.extractMax();
        //std::cout << " size2:" << q.getSize() << " ";
        //std::cout << all_vertex[v].cap << " ";
        for(auto e : all_vertex[v].adj) {
            //std::cout <<"vindex:" << v->queueIndex << " ";
            std::cout <<"max:" << all_vertex[v].cap << " ";
            std::cout <<"edgecap:" << e.capacity << " ";
            std::cout <<"destcap:" << all_vertex[e.dest].cap << " ";
            if(std::min(all_vertex[v].cap, e.capacity) > all_vertex[e.dest].cap){
                all_vertex[e.dest].cap = std::min(all_vertex[v].cap, e.capacity);
                all_vertex[e.dest].pred = v;
                std::cout << "newdestcap:" << all_vertex[e.dest].cap << " ";
                q.increaseKey(e.dest, all_vertex[e.dest].cap);
                //q.print();
            }
            //q.print();
        }
    }
    //q.print();
}

void Graph2::maxCapMinDist(int ori){
    for(int v = 1; v <= num_vertex; v++) {
        all_vertex[v].cap = 0;
        all_vertex[v].pred = 0/*nullptr*/;
        all_vertex[v].dist = INF;
    }
    all_vertex[ori].cap = INF;
    all_vertex[ori].dist = 0;
    MaxHeapPQ<int, int> q(num_vertex, -1);
    // Adicionar todos os nodes
    //std::cout << q.getSize();
    for(int n = 1; n <= num_vertex; n++){
        q.insert(n, all_vertex[n].cap);
        //std::cout << n->cap << " ";
    }
    //std::cout << q.getSize();
    //q.print(); //all ok
    while( !q.empty() ) {
        //std::cout << " size:" << q.getSize() << " ";
        //std::cout << " One" << " ";
        q.print();
        int v = q.extractMax();
        //std::cout << " size2:" << q.getSize() << " ";
        //std::cout << all_vertex[v].cap << " ";
        for(auto e : all_vertex[v].adj) {
            //std::cout <<"vindex:" << v->queueIndex << " ";
            std::cout <<"max:" << all_vertex[v].cap << " ";
            std::cout <<"edgecap:" << e.capacity << " ";
            std::cout <<"destcap:" << all_vertex[e.dest].cap << " ";
            if(std::min(all_vertex[v].cap, e.capacity) > all_vertex[e.dest].cap){
                all_vertex[e.dest].cap = std::min(all_vertex[v].cap, e.capacity);
                all_vertex[e.dest].pred = v;
                std::cout << "newdestcap:" << all_vertex[e.dest].cap << " ";
                all_vertex[e.dest].dist = all_vertex[v].dist + 1;
                q.increaseKey(e.dest, all_vertex[e.dest].cap);
                //q.print();
            }
            else if(std::min(all_vertex[v].cap, e.capacity) == all_vertex[e.dest].cap && all_vertex[v].dist + 1 < all_vertex[e.dest].dist){
                all_vertex[e.dest].pred = v;
                std::cout << "newdestcap:" << all_vertex[e.dest].cap << " ";
                all_vertex[e.dest].dist = all_vertex[v].dist + 1;
                q.increaseKey(e.dest, all_vertex[e.dest].cap);
            }
            //q.print();
        }
    }
}

void Graph2::minDistMaxCap(int ori) {
    MinHeapPQ<int, int> q(num_vertex, -1);
    for(int v = 1; v <= num_vertex; v++) {
        all_vertex[v].cap = 0;
        all_vertex[v].pred = 0/*nullptr*/;
        all_vertex[v].dist = INF;
        all_vertex[v].visited = false;
    }
    all_vertex[ori].cap = INF;
    all_vertex[ori].dist = 0;
    all_vertex[ori].pred = ori;
    // Adicionar todos os nodes
    //std::cout << q.getSize();
    for(int n = 1; n <= num_vertex; n++){
        q.insert(n, all_vertex[n].dist);
        //std::cout << n->cap << " ";
    }
    //std::cout << q.getSize();
    //q.print(); //all ok
    while( !q.empty() ) {
        //std::cout << " size:" << q.getSize() << " ";
        //std::cout << " One" << " ";
        //q.print();
        int v = q.extractMin();
        //std::cout << " size2:" << q.getSize() << " ";
        //std::cout << all_vertex[v].cap << " ";
        if(!all_vertex[v].visited){
            all_vertex[v].visited = true;
            for(auto e : all_vertex[v].adj) {
                if (!all_vertex[e.dest].visited && all_vertex[v].dist + 1 < all_vertex[e.dest].dist) {
                    all_vertex[e.dest].cap = std::min(all_vertex[v].cap, e.capacity);
                    all_vertex[e.dest].pred = v;
                    //std::cout << "newdestcap:" << all_vertex[e.dest].cap << " ";
                    all_vertex[e.dest].dist = all_vertex[v].dist + 1;
                    q.decreaseKey(e.dest, all_vertex[e.dest].dist);
                    //q.print();
                } else if (!all_vertex[e.dest].visited && all_vertex[v].dist + 1 == all_vertex[e.dest].dist && std::min(all_vertex[v].cap, e.capacity) > all_vertex[e.dest].cap) {
                    all_vertex[e.dest].pred = v;
                    all_vertex[e.dest].cap = std::min(all_vertex[v].cap, e.capacity);
                    //std::cout << "newdestcap:" << all_vertex[e.dest].cap << " ";
                    all_vertex[e.dest].dist = all_vertex[v].dist + 1;
                    q.decreaseKey(e.dest, all_vertex[e.dest].dist);
                }
            }
            //q.print();
        }
    }
}

std::vector<int> Graph2::path(int ori, int dest) {
    std::vector<int> nodesPassed;
    while(dest != ori){
        nodesPassed.push_back(dest);
        dest = all_vertex[dest].pred;
    }
    nodesPassed.push_back(ori);
    return nodesPassed;
}

int Graph2::max_node_capacity(int n){
    return all_vertex[n].cap;
}

void Graph2::print_flow() {
    for (int i = 1; i <= num_vertex; i++) {
        std::cout << i << "\nNormal:\n";
        //std::cout << all_vertex[i].cap;
        for (auto e: all_vertex[i].adj) {
            std::cout << "\tdest: " << e.dest << " flow: " << e.flow << std::endl;
        }
        std::cout << i << "\nRes:\n";
        for (auto e: all_vertex[i].residual) {
            std::cout << "\tdest: " << e.dest << " flow: " << e.flow << std::endl;
        }
    }
}

int Graph2::bfs(int ori, int dest) {
    /*for (int v=1; v<=num_vertex; v++) all_vertex[v].visited = false;
    queue<pair<int, int>> q; // queue of unvisited nodes
    q.push({ori, INF});
    all_vertex[ori].visited = true;
    while (!q.empty()) { // while there are still unvisited nodes
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();
        //cout << u << " "; // show node order
        for (auto e : all_vertex[cur].adj) {
            all_vertex[e.dest].pred = cur;
            int new_flow = std::min(flow, e.capacity);
            if(e.dest == dest)
                return new_flow;
            q.push({e.dest, new_flow});
        }
    }*/

    for (int v=1; v<=num_vertex; v++) all_vertex[v].visited = false;
    queue<int> q; // queue of unvisited nodes
    q.push(ori);
    all_vertex[ori]. visited = true;
    while (!q.empty()) { // while there are still unvisited nodes
        int u = q.front();
        q.pop();
        cout << u << " "; // show node order
        for (auto e: all_vertex[u].residual) {
            int w = e.dest;
            if (all_vertex[w].cap - e.flow > 0 && !all_vertex[w].visited) {
                all_vertex[w].pred = u;
                int new_flow = std::min(all_vertex[u].cap, all_vertex[w].cap - e.flow);
                all_vertex[w].visited = true;
                if (w != dest)
                    q.push(w);
                else
                    return new_flow;
            }
        }
    }
}

int Graph2::edmondsKarp(int ori, int dest){
    int maxFlow = 0;
    int newFlow;
    for (int i = 1; i < num_vertex; i++){
        for (auto e : all_vertex[i].residual){
            e.flow = 0;
            e.capacity = all_vertex[e.dest].cap;
        }
    }
    while(1) {
        newFlow = bfs(ori, dest);
        if(newFlow == 0){
            break;
        }
        maxFlow += newFlow;
        int v = dest;
        while (v != ori) {
            int u = all_vertex[v].pred;
            all_vertex[u].residual[v].flow = all_vertex[u].residual[v].flow + maxFlow;
            all_vertex[v].residual[u].flow = all_vertex[v].residual[u].flow - maxFlow;
            v = u;
        }
    }
    return maxFlow;
}