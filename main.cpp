#include <iostream>
#include "populate_graph.h"
#include "Cenario1.h"
#include "Cenario2.h"

int main() {
    populate_graph pf;
    Cenario1 c1;
    Cenario2 c2;

    Graph2 g = pf.read_tests();
    //c1.maximizeCapacity(g);
    //c1.maxCapMinDist(g);
    c2.c1_1(g);
    return 0;
}
