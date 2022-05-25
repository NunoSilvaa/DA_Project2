#include <iostream>
#include "populate_graph.h"

int main() {
    populate_graph pf;

    pf.read_tests();
    pf.build_graph();
    pf.maximize_group(1,5);
    return 0;
}
