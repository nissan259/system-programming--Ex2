#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test graph addition")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {0, 2, 0},
            {2, 0, 2},
            {0, 2, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
            {0, 3, 3},
            {3, 0, 4},
            {3, 4, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 + g2;
    vector<vector<int>> expectedGraph = {
            {0, 5, 3},
            {5, 0, 6},
            {3, 6, 0}};
    CHECK(g3.printGraph() == "[0, 5, 3]\n[5, 0, 6]\n[3, 6, 0]");

    ariel::Graph g4 = g1 + g1;
    vector<vector<int>> expectedGraph2 = {
            {0, 4, 0},
            {4, 0, 4},
            {0, 4, 0}};
    CHECK(g4.printGraph() == "[0, 4, 0]\n[4, 0, 4]\n[0, 4, 0]");

    ariel::Graph g5;
    vector<vector<int>> graph2 = {
            {0, 2, 0, 0, 2},
            {2, 0, 2, 0, 0},
            {0, 2, 0, 2, 0},
            {0, 0, 2, 0, 2},
            {2, 0, 0, 2, 0}};
    g5.loadGraph(graph2);
    CHECK_THROWS(g1 + g5);
}



TEST_CASE("Invalid operations")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {0, 2, 0},
            {2, 0, 2},
            {0, 2, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
            {0, 3, 3, 3},
            {3, 0, 4, 3},
            {3, 4, 0, 3}};
    // g2.loadGraph(weightedGraph);
    ariel::Graph g5;
    vector<vector<int>> graph2 = {
            {0, 2, 0, 0, 2},
            {2, 0, 2, 0, 0},
            {0, 2, 0, 2, 0},
            {0, 0, 2, 0, 2},
            {2, 0, 0, 2, 0}};
    g5.loadGraph(graph2);
    CHECK_THROWS(g5 * g1);
    // CHECK_THROWS(g1 * g2);

    // Addition of two graphs with different dimensions
    ariel::Graph g6;
    vector<vector<int>> graph3 = {
            {0, 2, 0, 0, 2},
            {2, 0, 2, 0, 0},
            {0, 2, 0, 2, 0},
            {0, 0, 2, 0, 2},
            {2, 0, 0, 2, 0}};
    g6.loadGraph(graph3);
    CHECK_THROWS(g1 + g6);
}

TEST_CASE("Test unary plus operator")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {0, 2, 0},
            {2, 0, 2},
            {0, 2, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2 = +g1;
    CHECK(g2.printGraph() == "[0, 2, 0]\n[2, 0, 2]\n[0, 2, 0]");
}

TEST_CASE("Test += operator")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {0, 2, 0},
            {2, 0, 2},
            {0, 2, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
            {0, 3, 3},
            {3, 0, 4},
            {3, 4, 0}};
    g2.loadGraph(weightedGraph);
    g1 += g2;
    CHECK(g1.printGraph() == "[0, 5, 3]\n[5, 0, 6]\n[3, 6, 0]");

    ariel::Graph g3;
    vector<vector<int>> grpah1 = {
            {0, 24, 34, -4},
            {48, 0, 2, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}};

    g3.loadGraph(grpah1);
    ariel::Graph g4;
    vector<vector<int>> grpah2 = {
            {0, 2, 0, 0},
            {2, 0, 2, 0},
            {0, 2, 0, 2},
            {0, 0, 2, 0}};
    g4.loadGraph(grpah2);
    g3 += g4;
    CHECK(g3.printGraph() == "[0, 26, 34, -4]\n[50, 0, 4, 0]\n[0, 2, 0, 2]\n[0, 0, 2, 0]");

    // Addition of two graphs with different dimensions
    ariel::Graph g6;
    vector<vector<int>> graph3 = {
            {0, 2, 0, 0, 2},
            {2, 0, 2, 0, 0},
            {0, 2, 0, 2, 0},
            {0, 0, 2, 0, 2},
            {2, 0, 0, 2, 0}};
    g6.loadGraph(graph3);
    CHECK_THROWS(g1 += g6);
}

TEST_CASE("Test unary minus operator")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {0, 2, 0},
            {2, 0, 2},
            {0, 2, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2 = -g1;
    CHECK(g2.printGraph() == "[0, -2, 0]\n[-2, 0, -2]\n[0, -2, 0]");

    ariel::Graph g3;
    vector<vector<int>> grpah1 = {
            {0, 24, 34, -4},
            {48, 0, 2, 0},
            {0, 88,

                    0, 0},
            {-230, 0, 0 - 10, 0}};
    g3.loadGraph(grpah1);
    ariel::Graph g4 = -g3;
    CHECK(g4.printGraph() == "[0, -24, -34, 4]\n[-48, 0, -2, 0]\n[0, -88, 0, 0]\n[230, 0, 10, 0]");
}

TEST_CASE("Test - operator")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {0, 2, 0},
            {2, 0, 2},
            {0, 2, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
            {0, 3, 3},
            {3, 0, 4},
            {3, 4, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 - g2;
    vector<vector<int>> expectedGraph = {
            {0, -1, -3},
            {-1, 0, -2},
            {-3, -2, 0}};
    CHECK(g3.printGraph() == "[0, -1, -3]\n[-1, 0, -2]\n[-3, -2, 0]");

    ariel::Graph g4 = g1 - g1;
    vector<vector<int>> expectedGraph2 = {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}};
    CHECK(g4.printGraph() == "[0, 0, 0]\n[0, 0, 0]\n[0, 0, 0]");

    // try to subtract two graphs with different dimensions
    ariel::Graph g5;
    vector<vector<int>> graph2 = {
            {0, 2, 0, 0, 2},
            {2, 0, 2, 0, 0},
            {0, 2, 0, 2, 0},
            {0, 0, 2, 0, 2},
            {2, 0, 0, 2, 0}};
    g5.loadGraph(graph2);
    CHECK_THROWS(g1 - g5);
}

TEST_CASE("Test -= operator")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {0, 2, 0},
            {2, 0, 2},
            {0, 2, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
            {0, 3, 3},
            {3, 0, 4},
            {3, 4, 0}};
    g2.loadGraph(weightedGraph);
    g1 -= g2;
    CHECK(g1.printGraph() == "[0, -1, -3]\n[-1, 0, -2]\n[-3, -2, 0]");

    ariel::Graph g3;
    vector<vector<int>> grpah1 = {
            {0, 24, 34, -4},
            {48, 0, 2, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}};
    g3.loadGraph(grpah1);
    ariel::Graph g4;
    vector<vector<int>> grpah2 = {
            {0, 2, 0, 0},
            {2, 0, 2, 0},
            {0, 2, 0, 2},
            {0, 0, 2, 0}};
    g4.loadGraph(grpah2);
    g3 -= g4;
    CHECK(g3.printGraph() == "[0, 22, 34, -4]\n[46, 0, 0, 0]\n[0, -2, 0, -2]\n[0, 0, -2, 0]");

    // try to subtract two graphs with different dimensions
    ariel::Graph g5;
    vector<vector<int>> graph2 = {
            {0, 2, 0, 0, 2},
            {2, 0, 2, 0, 0},
            {0, 2, 0, 2, 0},
            {0, 0, 2, 0, 2},
            {2, 0, 0, 2, 0}};
    g5.loadGraph(graph2);
    CHECK_THROWS(g1 -= g5);
}

TEST_CASE("Test pre-increment operator")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {0, 2, 0},
            {2, 0, 2},
            {0, 2, 0}};
    g1.loadGraph(graph);
    ++g1;
    CHECK(g1.printGraph() == "[0, 3, 1]\n[3, 0, 3]\n[1, 3, 0]");

    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
            {0, 3, 3},
            {3, 0, 4},
            {3, 4, 0}};

    g2.loadGraph(weightedGraph);
    ++g2;
    CHECK(g2.printGraph() == "[0, 4, 4]\n[4, 0, 5]\n[4, 5, 0]");

    // try to increment a graph with negative values
    ariel::Graph g3;
    vector<vector<int>> grpah1 = {
            {0, 24, 34, -4},
            {48, 0, 2, 0},
            {0, -16, 0, 0},
            {460, -20, 0, 0}};
    g3.loadGraph(grpah1);
    ++g3;
    CHECK(g3.printGraph() == "[0, 25, 35, -3]\n[49, 0, 3, 1]\n[1, -15, 0, 1]\n[461, -19, 1, 0]");
}

TEST_CASE("Test post-increment operator")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {0, 2, 0},
            {2, 0, 2},
            {0, 2, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2 = g1++;
    CHECK(g2.printGraph() == "[0, 2, 0]\n[2, 0, 2]\n[0, 2, 0]");
    CHECK(g1.printGraph() == "[0, 3, 1]\n[3, 0, 3]\n[1, 3, 0]");

    ariel::Graph g3;
    vector<vector<int>> weightedGraph = {
            {0, 3, 3},
            {3, 0, 4},
            {3, 4, 0}};
    g3.loadGraph(weightedGraph);
    ariel::Graph g4 = g3++;
    CHECK(g4.printGraph() == "[0, 3, 3]\n[3, 0, 4]\n[3, 4, 0]");
    CHECK(g3.printGraph() == "[0, 4, 4]\n[4, 0, 5]\n[4, 5, 0]");

    // try to increment a graph with negative values
    ariel::Graph g5;
    vector<vector<int>> grpah1 = {
            {0, 24, 34, -4},
            {48, 0, 2, 0},
            {0, -16, 0, 0},
            {460, -20, 0, 0}};
    g5.loadGraph(grpah1);
    ariel::Graph g6 = g5++;
    CHECK(g6.printGraph() == "[0, 24, 34, -4]\n[48, 0, 2, 0]\n[0, -16, 0, 0]\n[460, -20, 0, 0]");
    CHECK(g5.printGraph() == "[0, 25, 35, -3]\n[49, 0, 3, 1]\n[1, -15, 0, 1]\n[461, -19, 1, 0]");
}

TEST_CASE("Test pre-decrement operator")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {0, 4, 1},
            {4, 0, 4},
            {1, 4, 0}};
    g1.loadGraph(graph);
    --g1;
    CHECK(g1.printGraph() == "[0, 3, 0]\n[3, 0, 3]\n[0, 3, 0]");

    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
            {0,

                    4, 4},
            {4, 0, 5},
            {4, 5, 0}};
    g2.loadGraph(weightedGraph);
    --g2;
    CHECK(g2.printGraph() == "[0, 3, 3]\n[3, 0, 4]\n[3, 4, 0]");

    // try to decrement a graph with negative values
    ariel::Graph g3;
    vector<vector<int>> grpah1 = {
            {0, 25, 35, -3},
            {49, 0, 3, 1},
            {1, -15, 0, 1},
            {461, -19, 1, 0}};
    g3.loadGraph(grpah1);
    --g3;
    CHECK(g3.printGraph() == "[0, 24, 34, -4]\n[48, 0, 2, 0]\n[0, -16, 0, 0]\n[460, -20, 0, 0]");
}

TEST_CASE("Test post-decrement operator")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {0, 4, 1},
            {4, 0, 4},
            {1, 4, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2 = g1--;
    CHECK(g2.printGraph() == "[0, 4, 1]\n[4, 0, 4]\n[1, 4, 0]");
    CHECK(g1.printGraph() == "[0, 3, 0]\n[3, 0, 3]\n[0, 3, 0]");

    ariel::Graph g3;
    vector<vector<int>> weightedGraph = {
            {0, 4, 4},
            {4, 0, 5},
            {4, 5, 0}};
    g3.loadGraph(weightedGraph);
    ariel::Graph g4 = g3--;
    CHECK(g4.printGraph() == "[0, 4, 4]\n[4, 0, 5]\n[4, 5, 0]");
    CHECK(g3.printGraph() == "[0, 3, 3]\n[3, 0, 4]\n[3, 4, 0]");

    // try to decrement a graph with negative values
    ariel::Graph g5;
    vector<vector<int>> grpah1 = {
            {0, 25, 35, -3},
            {49, 0, 3, 1},
            {1, -15, 0, 1},
            {461, -19, 1, 0}};
    g5.loadGraph(grpah1);
    ariel::Graph g6 = g5--;
    CHECK(g6.printGraph() == "[0, 25, 35, -3]\n[49, 0, 3, 1]\n[1, -15, 0, 1]\n[461, -19, 1, 0]");
    CHECK(g5.printGraph() == "[0, 24, 34, -4]\n[48, 0, 2, 0]\n[0, -16, 0, 0]\n[460, -20, 0, 0]");
}

// test for multiplication of a graph by a scalar
TEST_CASE("Test * operator")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {0, 4, 1},
            {4, 0, 4},
            {1, 4, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2 = g1 * 3;
    CHECK(g2.printGraph() == "[0, 12, 3]\n[12, 0, 12]\n[3, 12, 0]");

    ariel::Graph g3;
    vector<vector<int>> weightedGraph = {
            {0, 4, 4},
            {4, 0, 5},
            {4, 5, 0}};
    g3.loadGraph(weightedGraph);
    ariel::Graph g4 = g3 * 4;
    CHECK(g4.printGraph() == "[0, 16, 16]\n[16, 0, 20]\n[16, 20, 0]");

    // Multiply a graph with negative values
    ariel::Graph g5;
    vector<vector<int>> grpah1 = {
            {0, 25, 35, -3},
            {49, 0, 3, 1},
            {1, -15, 0, 1},
            {461, -19, 1, 0}};
    g5.loadGraph(grpah1);
    ariel::Graph g6 = g5 * -3;
    CHECK(g6.printGraph() == "[0, -75, -105, 9]\n[-147, 0, -9, -3]\n[-3, 45, 0, -3]\n[-1383, 57, -3, 0]");

    // try to multiply a graph with 0
    ariel::Graph g7;
    vector<vector<int>> grpah2 = {
            {0, 25, 35, -3},
            {49, 0, 3, 1},
            {1, -15, 0, 1},
            {461, -19, 1, 0}};
    g7.loadGraph(grpah2);
    ariel::Graph g8 = g7 * 0;
    CHECK(g8.printGraph() == "[0, 0, 0, 0]\n[0, 0, 0, 0]\n[0, 0, 0, 0]\n[0, 0, 0, 0]");
}

TEST_CASE("Test *= operator")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {0, 4, 1},
            {4, 0, 4},
            {1, 4, 0}};
    g1.loadGraph(graph);
    g1 *= 3;
    CHECK(g1.printGraph() == "[0, 12, 3]\n[12, 0, 12]\n[3, 12, 0]");

    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
            {0, 4, 4},
            {4, 0, 5},
            {4, 5, 0}};
    g2.loadGraph(weightedGraph);
    g2 *= 4;
    CHECK(g2.printGraph() == "[0, 16, 16]\n[16, 0, 20]\n[16, 20, 0]");
    // Multiply a graph with negative values
    ariel::Graph g3;
    vector<vector<int>> grpah1 = {
            {0, 25, 35, -3},
            {49, 0, 3, 1},
            {1, -15, 0, 1},
            {461, -19, 1, 0}};
    g3.loadGraph(grpah1);
    g3 *= -3;
    CHECK(g3.printGraph() == "[0, -75, -105, 9]\n[-147, 0, -9, -3]\n[-3, 45, 0, -3]\n[-1383, 57, -3, 0]");

    // try to multiply a graph with 0
    ariel::Graph g4;
    vector<vector<int>> grpah2 = {
            {0, 25, 35, -3},
            {49, 0, 3, 1},
            {1, -15, 0, 1},
            {461, -19, 1, 0}};
    g4.loadGraph(grpah2);
    g4 *= 0;
    CHECK(g4.printGraph() == "[0, 0, 0, 0]\n[0, 0, 0, 0]\n[0, 0, 0, 0]\n[0, 0, 0, 0]");
}

TEST_CASE("Test / operator")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {0, 8, 4},
            {8, 0, 8},
            {4, 8, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2 = g1 / 4;
    CHECK(g2.printGraph() == "[0, 2, 1]\n[2, 0, 2]\n[1, 2, 0]");

    ariel::Graph g3;
    vector<vector<int>> weightedGraph = {
            {0, 12, 12},
            {12, 0, 15},
            {12, 15, 0}};
    g3.loadGraph(weightedGraph);
    ariel::Graph g4 = g3 / 5;
    CHECK(g4.printGraph() == "[0, 2, 2]\n[2, 0, 3]\n[2, 3, 0]");



    // Divide a graph with negative values
    ariel::Graph g5;
    vector<vector<int>> grpah1 = {
            {0, -78, -108, 6},
            {-150, 0, -12, -6},
            {-6, 42, 0, -6},
            {-1386, 54, -6, 0}};
    g5.loadGraph(grpah1);
    ariel::Graph g6 = g5 / -3;
    CHECK(g6.printGraph() == "[0, 26, 36, -2]\n[50, 0, 4, 2]\n[2, -14, 0, 2]\n[462, -18, 2, 0]");

    // try to divide a graph with 0
    ariel::Graph g7;
    vector<vector<int>> grpah2 = {
            {0, 25, 35, -3},
            {49, 0, 3, 1},
            {1, -15, 0, 1},
            {461, -19, 1, 0}};
    g7.loadGraph(grpah2);
    ariel::Graph g8 = g7 / 1;
    CHECK(g8.printGraph() == "[0, 25, 35, -3]\n[49, 0, 3, 1]\n[1, -15, 0, 1]\n[461, -19, 1, 0]");

    // try to divide a graph with a scalar that is 0
    ariel::Graph g9;
    vector<vector<int>> grpah3 = {
            {0, 25, 35, -3},
            {49, 0, 3, 1},
            {1, -15, 0, 1},
            {461, -19, 1, 0}};
    g9.loadGraph(grpah3);
    CHECK_THROWS(g9 / 0);
}

TEST_CASE("Test /= operator")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {0, 8, 4},
            {8, 0, 8},
            {4, 8, 0}};
    g1.loadGraph(graph);
    g1 /= 4;
    CHECK(g1.printGraph() == "[0, 2, 1]\n[2, 0, 2]\n[1, 2, 0]");

    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
            {0, 12, 12},
            {12, 0, 15},
            {12, 15, 0}};
    g2.loadGraph(weightedGraph);
    g2 /= 5;
    CHECK(g2.printGraph() == "[0, 2, 2]\n[2, 0, 3]\n[2, 3, 0]");

    // Divide a graph with negative values
    ariel::Graph g3;
    vector<vector<int>> grpah1 = {
            {0, -78, -108, 6},
            {-150, 0, -12, -6},
            {-6, 42, 0, -6},
            {-1386, 54, -6, 0}};
    g3.loadGraph(grpah1);
    g3 /= -3;
    CHECK(g3.printGraph() == "[0, 26, 36, -2]\n[50, 0, 4, 2]\n[2, -14, 0, 2]\n[462, -18, 2, 0]");

    // try to divide a graph with 0
    ariel::Graph g4;
    vector<vector<int>> grpah2 = {
            {0, 25, 35, -3},
            {49, 0, 3, 1},
            {1, -15, 0, 1},
            {461, -19, 1, 0}};
    g4.loadGraph(grpah2);
    g4 /= 1;
    CHECK(g4.printGraph() == "[0, 25, 35, -3]\n[49, 0, 3, 1]\n[1, -15, 0, 1]\n[461, -19, 1, 0]");
}
TEST_CASE("== operator")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {0, 2, 0},
            {2, 0, 2},
            {0, 2, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
            {0, 3, 3},
            {3, 0, 4},
            {3, 4, 0}};
    g2.loadGraph(weightedGraph);
    CHECK(g1 == g1);
    CHECK(g1 != g2);

    ariel::Graph g3;
    vector<vector<int>> graph1 = {
            {0, 2, 0},
            {2, 0, 2},
            {0, 2, 0}};
    g3.loadGraph(graph);
    CHECK(g1 == g3);
}

TEST_CASE("Test < operator")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
            {0, 2, 0},
            {2, 0, 2},
            {0, 2, 0}};
    g1.loadGraph(graph1);
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
            {0, 2, 0},
            {2, 0, 2},
            {0, 2, 0}};
    g2.loadGraph(graph2);
    CHECK_FALSE(g1 < g2);

    ariel::Graph g3;
    vector<vector<int>> graph3 = {
            {0, 2, 2},
            {2, 0, 2},
            {2, 2, 0}};
    g3.loadGraph(graph3);
    ariel::Graph g4;
    vector<vector<int>> graph4 = {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 2, 2},
            {0, 0, 2, 0, 2},
            {0, 0, 2, 2, 0}};
    g4.loadGraph(graph4);
    CHECK(g3 < g4);

    // Test if one graph has more edges than the other
    ariel::Graph g5;
    vector<vector<int>> graph5 = {
            {0, 2, 0},
            {2, 0, 2},
            {0, 2, 0}};
    g5.loadGraph(graph5);
    ariel::Graph g6;
    vector<vector<int>> graph6 = {
            {0, 2, 0},
            {2, 0, 2},
            {0, 0, 0}};
    g6.loadGraph(graph6);
    CHECK_FALSE(g5 < g6);

    // Test if one graph has more vertices than the other
    ariel::Graph g7;
    vector<vector<int>>

            graph7 = {
            {0, 2, 0},
            {2, 0, 2},
            {0, 2, 0}};
    g7.loadGraph(graph7);
    ariel::Graph g8;
    vector<vector<int>> graph8 = {
            {0, 2, 0, 0},
            {2, 0, 0, 0},
            {0, 0, 0, 2},
            {0, 0, 2, 0}};
    g8.loadGraph(graph8);
    CHECK(g7 < g8);
}

TEST_CASE("Test != operator")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
            {0, 2, 0},
            {2, 0, 2},
            {0, 2, 0}};
    g1.loadGraph(graph1);
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
            {0, 2, 0},
            {2, 0, 2},
            {0, 2, 0}};
    g2.loadGraph(graph2);
    CHECK_FALSE(g1 != g2);

    ariel::Graph g3;
    vector<vector<int>> graph3 = {
            {0, 2, 0},
            {2, 0, 2},
            {0, 2, 0}};
    g3.loadGraph(graph3);
    ariel::Graph g4;
    vector<vector<int>> graph4 = {
            {0, 2, 0, 0, 2},
            {2, 0, 2, 0, 0},
            {0, 2, 0, 2, 0},
            {0, 0, 2, 0, 2},
            {2, 0, 0, 2, 0}};
    g4.loadGraph(graph4);
    CHECK(g3 != g4);

    ariel::Graph g5;
    vector<vector<int>> graph5 = {
            {0, 2, 0},
            {2, 0, 2},
            {0, 2, 0}};
    g5.loadGraph(graph5);
    ariel::Graph g6;
    vector<vector<int>> graph6 = {
            {0, 2, 0},
            {2, 0, 2},
            {0, 0, 0}};
    g6.loadGraph(graph6);
    CHECK(g5 != g6);
}

TEST_CASE("Test <= operator")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
            {0, 2, 0},
            {2, 0, 2},
            {0, 2, 0}};
    g1.loadGraph(graph1);
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
            {0, 2, 0},
            {2, 0, 2},
            {0, 2, 0}};
    g2.loadGraph(graph2);
    CHECK(g1 <= g2);

    ariel::Graph g3;
    vector<vector<int>> graph3 = {
            {0, 2, 0},
            {2, 0, 2},
            {0, 2, 0}};
    g3.loadGraph(graph3);
    ariel::Graph g4;
    vector<vector<int>> graph4 = {
            {0, 2, 0, 0, 2},
            {2, 0, 2, 0, 0},
            {0, 0, 0, 2, 0},
            {0, 0, 0, 0, 2},
            {2, 0, 0, 2, 0}};
    g4.loadGraph(graph4);
    CHECK(g3 <= g4);

    ariel::Graph g5;
    vector<vector<int>> graph5 = {
            {0, 2, 0},
            {2, 0, 2},
            {0, 2, 0}};
    g5.loadGraph(graph5);
    ariel::Graph g6;
    vector<vector<int>> graph6 = {
            {0, 2, 0},
            {2, 0, 2},
            {0, 0, 0}};
    g6.loadGraph(graph6);
    CHECK_FALSE(g5 <= g6);
}
TEST_CASE("Test graph multiplication with identity matrix")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {0, 1, 2},
            {3, 0, 4},
            {5, 6, 0}};
    g1.loadGraph(graph);
    ariel::Graph identityGraph;
    vector<vector<int>> identityMatrix = {
            {1, 0, 0},
            {0, 1, 0},
            {0, 0, 1}};
    identityGraph.loadGraph(identityMatrix);
    ariel::Graph result = g1 * identityGraph;
    CHECK(result.printGraph() == "[0, 1, 2]\n[3, 0, 4]\n[5, 6, 0]");
}

TEST_CASE("Test graph multiplication with zero matrix")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {0, 1, 2},
            {3, 0, 4},
            {5, 6, 0}};
    g1.loadGraph(graph);
    ariel::Graph zeroGraph;
    vector<vector<int>> zeroMatrix = {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}};
    zeroGraph.loadGraph(zeroMatrix);
    ariel::Graph result = g1 * zeroGraph;
    CHECK(result.printGraph() == "[0, 0, 0]\n[0, 0, 0]\n[0, 0, 0]");
}

TEST_CASE("Test graph multiplication with larger matrices")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
            {0, 1, 2, 3},
            {4, 0, 5, 6},
            {7, 8, 0, 9},
            {10, 11, 12, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
            {0, 13, 14, 15},
            {16, 0, 17, 18},
            {19, 20, 0, 21},
            {22, 23, 24, 0}};
    g2.loadGraph(graph2);

    ariel::Graph result = g1 * g2;
    CHECK(result.printGraph() == "[0, 109, 89, 60]\n[227, 0, 200, 165]\n[326, 298, 0, 249]\n[404, 370, 327, 0]");
}

TEST_CASE("Test graph multiplication with non-square matrices") {
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
            {0, 1, 2},
            {3, 0, 4}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
            {0, 5},
            {6, 0},
            {7, 8}};
    g2.loadGraph(graph2);

    CHECK_THROWS_WITH(g1 * g2, "Both matrices must be square for multiplication.");
}

TEST_CASE("Test graph multiplication with empty matrices")
{
    ariel::Graph emptyGraph1;
    ariel::Graph emptyGraph2;
    ariel::Graph result = emptyGraph1 * emptyGraph2;
    CHECK(result.printGraph() == emptyGraph1.printGraph());
}