#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"
#include <sstream>

using namespace std;

TEST_CASE("Test graph addition") {
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph);

    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}
    };
    g2.loadGraph(weightedGraph);

    ariel::Graph g3 = g1 + g2;
    vector<vector<int>> expectedGraph = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}
    };

    std::ostringstream oss;
    oss << g3;
    CHECK(oss.str() == "[0, 2, 1]\n[2, 0, 3]\n[1, 3, 0]\n");
}

TEST_CASE("Test graph multiplication") {
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph);

    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}
    };
    g2.loadGraph(weightedGraph);

    ariel::Graph g4 = g1 * g2;
    vector<vector<int>> expectedGraph = {
        {0, 0, 2},
        {1, 0, 1},
        {1, 0, 0}
    };

    std::ostringstream oss;
    oss << g4;
    CHECK(oss.str() == "[0, 0, 2]\n[1, 0, 1]\n[1, 0, 0]\n"); // Remove the extra ')'
}

TEST_CASE("Invalid operations") {
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph);

    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1, 1},
        {1, 0, 2, 1},
        {1, 2, 0, 1}
    };
//     g2.loadGraph(weightedGraph);

    ariel::Graph g5;
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}
    };
    g5.loadGraph(graph2);

    CHECK_THROWS(g5 * g1);
//     CHECK_THROWS(g1 * g2);

    // Addition of two graphs with different dimensions
    ariel::Graph g6;
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}
    };
    g6.loadGraph(graph3);

    CHECK_THROWS(g1 + g6);
}
TEST_CASE("Test empty graph") {
    ariel::Graph g;
    std::ostringstream oss;
    oss << g;
    CHECK(oss.str() == "");
}

TEST_CASE("Test single element graph") {
    ariel::Graph g(1, 1);
    g.setAdjacencyMatrix(0, 0, 1);
    std::ostringstream oss;
    oss << g;
    CHECK(oss.str() == "[1]\n");
}

TEST_CASE("Test graph equality") {
    ariel::Graph g1, g2;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph);
    g2.loadGraph(graph);
    CHECK(g1 == g2);
}

TEST_CASE("Test graph inequality") {
    ariel::Graph g1, g2;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 0},
        {1, 0, 0}
    };
    g1.loadGraph(graph1);
    g2.loadGraph(graph2);
    CHECK(g1 != g2);
}

TEST_CASE("Test graph comparison operators") {
    ariel::Graph g1, g2, g3;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 0},
        {1, 0, 0}
    };
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {0, 0, 1, 0}
    };
    g1.loadGraph(graph1);
    g2.loadGraph(graph2);
    g3.loadGraph(graph3);
    CHECK(g1 < g2);
    CHECK(g3 > g1);
}

TEST_CASE("Test graph unary plus") {
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g.loadGraph(graph);
    ariel::Graph g1 = +g;
    std::ostringstream oss;
    oss << g1;
    CHECK(oss.str() == "[0, 1, 0]\n[1, 0, 1]\n[0, 1, 0]\n");
}

TEST_CASE("Test graph unary minus") {
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g.loadGraph(graph);
    ariel::Graph g1 = -g;
    std::ostringstream oss;
    oss << g1;
    CHECK(oss.str() == "[0, -1, 0]\n[-1, 0, -1]\n[0, -1, 0]\n");
}

TEST_CASE("Test graph prefix increment") {
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g.loadGraph(graph);
    ariel::Graph g1 = ++g;
    std::ostringstream oss;
    oss << g1;
    CHECK(oss.str() == "[1, 2, 1]\n[2, 1, 2]\n[1, 2, 1]\n");
}

TEST_CASE("Test graph postfix increment") {
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g.loadGraph(graph);
    ariel::Graph g1 = g++;
    std::ostringstream oss;
    oss << g1;
    CHECK(oss.str() == "[0, 1, 0]\n[1, 0, 1]\n[0, 1, 0]\n");
}

TEST_CASE("Test graph prefix decrement") {
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g.loadGraph(graph);
    ariel::Graph g1 = --g;
    std::ostringstream oss;
    oss << g1;
    CHECK(oss.str() == "[-1, 0, -1]\n[0, -1, 0]\n[-1, 0, -1]\n");
}

TEST_CASE("Test graph postfix decrement") {
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g.loadGraph(graph);
    ariel::Graph g1 = g--;
    std::ostringstream oss;
    oss << g1;
    CHECK(oss.str() == "[0, 1, 0]\n[1, 0, 1]\n[0, 1, 0]\n");
}

TEST_CASE("Test graph scalar multiplication") {
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g.loadGraph(graph);
    ariel::Graph g1 = g * 2;
    std::ostringstream oss;
    oss << g1;
    CHECK(oss.str() == "[0, 2, 0]\n[2, 0, 2]\n[0, 2, 0]\n");
}

TEST_CASE("Test graph scalar division") {
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}
    };
    g.loadGraph(graph);
    ariel::Graph g1 = g / 2;
    std::ostringstream oss;
    oss << g1;
    CHECK(oss.str() == "[0, 1, 0]\n[1, 0, 1]\n[0, 1, 0]\n");
}

TEST_CASE("Test graph composition") {
    ariel::Graph g1, g2;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}
    };
    g1.loadGraph(graph1);
    g2.loadGraph(graph2);
    ariel::Graph g3 = g1.composition(g2);
    std::ostringstream oss;
    oss << g3;
    CHECK(oss.str() == "[1, 0, 2]\n[1, 3, 1]\n[1, 0, 2]\n");
}

TEST_CASE("Test graph complementation") {
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g.loadGraph(graph);
    ariel::Graph g1 = ~g;
    std::ostringstream oss;
    oss << g1;
    CHECK(oss.str() == "[1, 0, 1]\n[0, 1, 0]\n[1, 0, 1]\n");
}

TEST_CASE("Test scalar division by graph") {
    ariel::Graph g;
    vector<vector<int>> graph = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    g.loadGraph(graph);
    ariel::Graph g1 = 10 / g;
    std::ostringstream oss;
    oss << g1;
    CHECK(oss.str() == "[10, 5, 3]\n[2, 2, 1]\n[1, 1, 1]\n");
}

TEST_CASE("Test scalar multiplication with graph") {
    ariel::Graph g;
    vector<vector<int>> graph = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    g.loadGraph(graph);
    ariel::Graph g1 = 2 * g;
    std::ostringstream oss;
    oss << g1;
    CHECK(oss.str() == "[2, 4, 6]\n[8, 10, 12]\n[14, 16, 18]\n");
}
TEST_CASE("Demo program test case") {
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);

    std::ostringstream oss;
    oss << g1;
    CHECK(oss.str() == "[0, 1, 0]\n[1, 0, 1]\n[0, 1, 0]\n");

    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    ariel::Graph g2;
    g2.loadGraph(weightedGraph);

    ariel::Graph g3 = g1 + g2;
    oss.str(""); // Clear the string stream
    oss << g3;
    CHECK(oss.str() == "[0, 2, 1]\n[2, 0, 3]\n[1, 3, 0]\n");

    g1 *= -2;
    oss.str(""); // Clear the string stream
    oss << g1;
    CHECK(oss.str() == "[0, -2, 0]\n[-2, 0, -2]\n[0, -2, 0]\n");

    g1 /= -2;
    ariel::Graph g4 = g1 * g2;
    oss.str(""); // Clear the string stream
    oss << g4;
    CHECK(oss.str() == "[0, 0, 2]\n[1, 0, 1]\n[1, 0, 0]\n");
}

