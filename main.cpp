#define CATCH_CONFIG_RUNNER
#include "graph.h"


int main(int argc, char* argv[]) {
    graph g;
    g.parse1(argv[1]);
    g.parse2(argv[2], argv[3]);

    return 0;
}
