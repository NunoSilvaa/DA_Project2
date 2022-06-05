//
// Created by nmls1 on 31/05/2022.
//

#include "Graph2.h"
//#include "MaxHeapPriorityQueue.h"
#include "MaxHeapPQ.h"
#include "MinHeapPQ.h"
#include "algorithm"

Graph2::Graph2(int num, bool dir) : num_vertex(num), hasDir(dir), all_vertex(num+1) {
}

std::vector<Graph2::Node> Graph2::getAllVertexs() {
    return this->all_vertex;
}

int Graph2::getMaxFlow(int dest){
    int maxFlow = 0;
    for(Node i : all_vertex){
        for(Edge e : i.adj){
            if(e.dest == dest){
                maxFlow += e.flow;
            }
        }
    }
    return maxFlow;
    //return maxFlow;
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
    all_vertex[sourc].adj.push_back(Edge{sourc, dest,0 ,c, d, true});
    all_vertex[dest].residual.push_back(new Edge{dest, sourc, 0, c, d, true});
    //if (!hasDir) all_vertex[dest].adj.push_back(Edge{dest, 0, c, d});
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
            std::cout << "\tdest: " << e->dest << " flow: " << e->flow << std::endl;
        }
    }
}

bool Graph2::bfs(int ori, int dest) {
    for(int i = 1; i < num_vertex; i++){
        //std::cout << i <<" ";
        all_vertex[i].visited = false;
    }
    all_vertex[ori].visited = true;
    std::queue<int> q;
    q.push(ori);
    while(!q.empty() && !all_vertex[dest].visited){
        int cur = q.front();
        q.pop();
        //std::cout << cur <<" ";
        for(auto e : all_vertex[cur].adj){
            //std::cout << e.capacity <<" ";
            //std::cout << e.flow <<" ";
            if(!all_vertex[e.dest].visited && (e.capacity - e.flow) > 0){
                all_vertex[e.dest].visited = true;
                all_vertex[e.dest].pred = cur;
                all_vertex[e.dest].predEdge = e;
                q.push(e.dest);
            }
        }
    }
    return all_vertex[dest].visited;
    /*std::queue<int> q;
    all_vertex[ori].visited = true;
    q.push(ori);
    std::vector<Edge*> path(num_vertex-1, nullptr);
    std::cout << num_vertex;
    while(!q.empty()) {
        //std::cout << q.size();
        int v = q.front();
        q.pop();
        //std::cout << "v" << v << " ";
        //std::cout << "dest:" << dest << " ";
        if(v == dest)
            break;
        for(auto e : all_vertex[v].adj){
            //std::cout << "e.dest: " << e.dest << " ";
            int cap = e.capacity - e.flow;
            if( cap > 0 && !all_vertex[e.dest].visited){
                all_vertex[e.dest].visited = true;
                path[e.dest] = &e;
                q.push(e.dest);
            }
        }
    }
    //std::cout <<"hey";
    if(path[dest] == nullptr) return 0;
    //std::cout << path.size();

    int bottleNeck = INF;
    for(Edge e = new Edge{path[dest]}; e->from != 1; e = path[e->from]){
        std::cout << e->from;
        bottleNeck = std::min(bottleNeck, (e->capacity - e->flow));
    }
    std::cout << "bottleNeck:" << bottleNeck;
    for(Edge *e = path[dest]; e != nullptr; e = path[e->from]){
        e->flow += bottleNeck;
        e->residualEdge->flow -= bottleNeck;
    }
    std::cout << "bottleNeck:" << bottleNeck;
    return bottleNeck;*/


    /*for(int i = 1; i <= num_vertex; i++){
        all_vertex[i].pred = 0;
        all_vertex[i].cap = 0;
    }
    std::queue<int> q;
    all_vertex[ori].cap = INF;
    q.push(ori);
    for(auto e : all_vertex[2].residual){
        std::cout << "flow2:" << e.flow << " ";
    }
    while(!q.empty()){
        int v = q.front();
        //std::cout << "v:" << v<< " ";
        q.pop();
        Edge* maxEdge = new Edge{0,0,0, 0, true};
        for(auto e : all_vertex[v].residual){
            if(e->visited){
                int w = e->dest;
                //std::cout << "second:" << e->flow << " \n";
                if(maxEdge->flow < e->flow){
                    maxEdge = e;
                }
                q.push(w);
            }
        }
        all_vertex[v].pred = maxEdge->dest;
        //std::cout << "v:" << v <<  all_vertex[v].pred << " ";
    }*/
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

    /*for (int v=1; v<=num_vertex; v++) all_vertex[v].visited = false;
    queue<int> q; // queue of unvisited nodes
    q.push(ori);
    all_vertex[ori]. visited = true;
    while (!q.empty()) { // while there are still unvisited nodes
        int u = q.front();
        q.pop();
        //std::cout << u << " "; // show node order
        for (auto e: all_vertex[u].adj) {
            int w = e.dest;
            if (e.capacity - e.flow > 0 && !all_vertex[w].visited) {
                all_vertex[w].pred = u;
                std::cout << "flow" << e.flow << " ";
                int new_flow = std::min(e.capacity, e.capacity - e.flow);
                all_vertex[w].visited = true;
                if (w != dest)
                    q.push(w);
                else
                    return new_flow;
            }
        }
    }*/
}

/*void Graph2::calculate_flow(){
    for(int i = 1; i <= num_vertex; i++){
        for(auto e : all_vertex[i].residual){
            if(e->visited){
                int v = e->dest;
                //std::cout << "v:" << v << " ";
                for(auto j : all_vertex[v].adj){
                    int w = j.dest;
                    //std::cout << "w:" << w << " ";
                    if(v != w) {
                        //std::cout << "i: " << i << " ";
                        //std::cout << "cap:" << j.capacity;
                        e->flow = j.capacity - j.flow;
                        //std::cout << "first:" << e->flow << " \n";
                    }
                }
            }
        }
    }
}*/

/*bool Graph2::path_checker(int ori, int dest, std::vector<Edge*> &edges){
    while(dest != ori+1){
        std::cout << "pred:" << all_vertex[dest].pred << " ";
        std::cout << "ori:" << ori << " ";
        std::cout << "dest:" << dest << " ";
        if(all_vertex[dest].pred == 0){
            return false;
        }
        else{
            for(auto i : all_vertex[dest].residual) {
                //std::cout << i->dest << " ";
                if (i->dest == all_vertex[dest].pred) {
                    edges.push_back(i);
                    break;
                }
            }
            dest = all_vertex[dest].pred;
            //std::cout <<"dest2:" << dest<< " ";
        }
        //std::cout <<"dest3:" << dest<< " ";
    }
    return true;
}*/

int Graph2::findMaxFlowEK(int ori, int dest){
    int maxFlow;
    int cur = dest;
    list<int>path = {};
    path.push_back(cur);
    while(cur != ori){
        if(all_vertex[cur].predEdge.dest == cur){
            maxFlow = std::min(maxFlow, all_vertex[cur].predEdge.capacity - all_vertex[cur].predEdge.flow);
            cur = all_vertex[cur].pred;
            path.push_back(cur);
        }
        else{
            maxFlow = std::min(maxFlow, all_vertex[cur].predEdge.flow);
            cur = all_vertex[cur].predEdge.dest;
            path.push_back(cur);
        }
    }
    std::pair<list<int>,int> pathFlow;
    path.reverse();
    pathFlow.first = path;
    pathFlow.second = maxFlow;
    allPaths.push_back(pathFlow);
    return maxFlow;
}

void Graph2::updateFlows(int ori, int dest, int flow){
    int cur = dest;
    while(cur != ori){
        if(all_vertex[cur].predEdge.dest == cur){
            all_vertex[cur].predEdge.flow += flow;
            cur = all_vertex[cur].pred;
        }
        else{
            all_vertex[cur].predEdge.flow -= flow;
            cur = all_vertex[cur].predEdge.dest;
        }
    }
}

void Graph2::updateAdj(){
    for(int i = 1; i < num_vertex; i++){
        //std::cout << i <<" ";
        for(Edge &e : all_vertex[i].adj){
            for(int j = 1; j < num_vertex; j++){
                if(all_vertex[j].predEdge.dest == e.dest && all_vertex[j].predEdge.from == e.from){
                    e.flow = all_vertex[j].predEdge.flow;
                }
            }
        }
    }
}

void Graph2::edmondsKarp(int ori, int dest){
    //std::cout << num_vertex;
    for(auto v : all_vertex){
        for(auto e : v.adj){
            e.flow = 0;
        }
        for(auto e : v.residual){
            e->flow = 0;
        }
    }
    while(bfs(ori, dest)){
        int maxFlow = findMaxFlowEK(ori, dest);
        updateFlows(ori, dest , maxFlow);
        updateAdj();
    }
    /*int flow = 1;
    while(flow != 0){
        for(int i = 1; i <= num_vertex; i++){
            all_vertex[i].visited = false;
        }
        flow = bfs(ori, dest);
        maxFlow += flow;
        //std::cout << maxFlow << " ";
    }*/
    /*for(auto i : all_vertex){
        for(auto j : i.adj){
            j.flow = 1;
        }
        for(auto j : i.residual){
            j->flow = 1;
        }
    }
    std::vector<Edge*> g;
    std::pair<int, std::vector<int>> path;
    calculate_flow();
    bfs(dest);
    while(path_checker(ori, dest, g)){
        std::cout << "gsize: " << g.size() << " ";
        int c = INF;
        int cap = INF;
        bool flag = false;
        path.second.push_back(dest);
        //std::cout << "Hey";
        for(auto e : g){
            path.second.push_back(e->dest);
            c = std::min(c, e->flow);
            cap = std::min(cap, e->capacity);
            //std::cout << "c:" <<c << " ";
            //std::cout << "cap:" <<cap << " ";
            //std::cout << "e.flow:" <<e->flow << " ";
            //std::cout << "e.cap:" <<e->capacity << " ";
        }
        int t = dest;
        while(t != ori +1){
            for(auto e : g){
                for(auto i : all_vertex[e->dest].adj){
                    if(i.dest == t){
                        i.flow += c;
                        if(i.flow < e->capacity){
                            e->flow = e->capacity - i.flow;
                        }
                        else{
                            e->flow = 0;
                            e->visited = false;
                            flag = true;
                        }
                        t = e->dest;
                        //std::cout << "t:" << t << " ";
                        //std::cout << "ori:" << ori << " ";
                    }
                }
            }
        }
        //std::cout << "hey:";
        if(flag){
            path.first = cap;
            //std::cout << "cap:" << cap << " ";
            allPaths.push_back(path);
            //std::cout << "size:" << size << " ";
            size -= cap;
            flag = false;
            //std::cout << "size:" << size << " ";
            if(size <= 0) return;
        }
        if(!flag)
            std::cout << 1;
        path.second.clear();
        calculate_flow();
        bfs(dest);
        g.clear();
        std::cout << "gsize2: " << g.size() << " ";
    }*/
    /*int maxFlow = 0;
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
    return maxFlow;*/
}

bool Graph2::edmondsKarpGroupSize(int ori, int dest, int size){
    for(auto v : all_vertex){
        for(auto e : v.adj){
            e.flow = 0;
        }
        for(auto e : v.residual){
            e->flow = 0;
        }
    }
    while(bfs(ori, dest)){
        int maxFlow = findMaxFlowEK(ori, dest);
        updateFlows(ori, dest , maxFlow);
        updateAdj();

        if(getMaxFlow(dest) >= size)
            break;
    }
    if(getMaxFlow(dest) < size){
        std::cout << "Group is too big!!\n";
        return false;
    }
    return true;

}

void Graph2::printAllPaths(){
    for(std::pair<std::list<int>,int> pair : allPaths){
        for(int i : pair.first){
            std::cout << "->" << i;
        }
        std::cout << " | Flow - " << pair.second << "\n";
    }
}

int Graph2::reuniteGroup(int ori, int dest, int size){
    //std::list<int>nodesR = {};
    //int timesGroupReunites = 0;
    /*for(std::pair<std::list<int>,int> pair : allPaths){
        for(std::pair<std::list<int>,int> pair2 : allPaths){
            //std::cout << pair.first << " ";
            if(pair.first != pair2.first && pair.second + pair2.second == size){
                //timesGroupReunites += 1;
                std::cout << pair.second << " ";
                for(auto n : pair.first){
                    nodesR.push_back(n);
                }
                for(auto n : pair2.first){
                    if(std::find(nodesR.begin(), nodesR.end(), n) != nodesR.end())
                        return n;
                }
            }
        }
    }*/
    int minTime = INF;
    for(std::pair<std::list<int>,int> pair : allPaths){
        int time = 0;
        int pred = INF;
        for(auto n : pair.first){
            if(pred != INF) {
                for (Edge e: all_vertex[pred].adj){
                    if(e.dest == n)
                        time += e.duration;
                }
                pred = n;
            }
            else{
                pred = n;
            }
        }
        if(minTime > time){
            minTime = time;
        }
    }
    return minTime;
}

