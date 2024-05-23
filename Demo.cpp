/*
 * Demo program for Exercise 3.
 * Author: Benjamin Saldman.
 */

#include "Graph.hpp"
#include "Algorithms.hpp"
using ariel::Algorithms;

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

int main()
{
    ariel::Graph graph1;
    // 3x3 matrix that represents a connected graph.
    vector<vector<int>> graphData1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    graph1.loadGraph(graphData1); // Load the graph to the object.

    cout << graph1; // Should print the matrix of the graph: [0, 1, 0], [1, 0, 1], [0, 1, 0]

    // 3x3 matrix that represents a weighted connected graph.
    vector<vector<int>> graphData2 = {
            {0, 1, 1},
            {1, 0, 2},
            {1, 2, 0}};
    ariel::Graph graph2;
    graph2.loadGraph(graphData2); // Load the graph to the object.

    ariel::Graph graph3 = graph1 + graph2; // Add the two graphs together.
    cout << graph3;           // Should print the matrix of the graph: [0, 2, 1], [2, 0, 3], [1, 3, 0]

    const int multiplyFactor = -2;
    graph1 *= multiplyFactor;        // Multiply the graph by -2.
    cout << graph1; // Should print the matrix of the graph: [0, -2, 0], [-2, 0, -2], [0, -2, 0]

    const int divideFactor = -2;
    graph1 /= divideFactor;
    ariel::Graph graph4 = graph1 * graph2; // Multiply the two graphs together.
    cout << graph4;           // Should print the multiplication of the matrices of graph1 and graph2: [0, 0, 2], [1, 0, 1], [1, 0, 0]

    // 5x5 matrix that represents a connected graph.
    vector<vector<int>> graphData3 = {
            {0, 1, 0, 0, 1},
            {1, 0, 1, 0, 0},
            {0, 1, 0, 1, 0},
            {0, 0, 1, 0, 1},
            {1, 0, 0, 1, 0}};
    ariel::Graph graph5;
    graph5.loadGraph(graphData3); // Load the graph to the object.
    try
    {
        ariel::Graph graph6 = graph5 * graph1; // Multiply the two graphs together.
    }
    catch (const std::invalid_argument &e)
    {
        cout << e.what() << endl; // Should print "The number of columns in the first matrix must be equal to the number of rows in the second matrix."
    }
}