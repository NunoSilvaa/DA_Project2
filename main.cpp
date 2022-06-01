#include <iostream>
#include "populate_graph.h"
#include "Cenario1.h"

int main() {
    populate_graph pf;
    Cenario1 c1;

    Graph2 g = pf.read_tests();
    //c1.maximizeCapacity(g);
    c1.maxCapMinDist(g);
    return 0;
}
