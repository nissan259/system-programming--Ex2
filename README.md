Graph Algorithms
Overview

Welcome to the Graph Algorithms project! This project provides a versatile Graph class implemented in C++. The class supports a variety of operations on graphs, including addition, subtraction, scalar multiplication, and more. Additionally, the project includes comprehensive functionality for graph composition, complementation, and various operator overloads to facilitate intuitive graph manipulations.
Features

    Graph Representation: Store graphs as adjacency matrices.
    Graph Operations: Support for addition, subtraction, scalar multiplication, and division.
    Operator Overloads: Overloaded operators for intuitive graph manipulations.
    Graph Composition and Complementation: Methods to compute the composition and complementation of graphs.
    Error Handling: Robust checks for valid operations and dimension mismatches.

Installation

To use this project, ensure you have a C++ compiler installed (such as g++) and the make utility. Clone the repository from GitHub:

sh

git clone https://github.com/nissan259/system-programming--Ex1.git
cd system-programming--Ex1

Building the Project

This project uses a Makefile for easy compilation. To build the project, simply run:

sh

make

This will compile the Graph class and generate the executable.
Running the Project

After building the project, you can run the executable. For example:

sh

./graph_executable

Replace graph_executable with the name of your compiled executable.
Usage

Here's a brief overview of how to use the Graph class:
Creating a Graph

cpp

#include "Graph.hpp"

int main() {
    ariel::Graph g(3, 3);
    g.setAdjacencyMatrix(0, 1, 1);
    g.setAdjacencyMatrix(1, 2, 1);
    g.printGraph();
    return 0;
}

Loading a Graph from an Adjacency Matrix

cpp

std::vector<std::vector<int>> adjMatrix = {
    {0, 1, 0},
    {1, 0, 1},
    {0, 1, 0}
};
g.loadGraph(adjMatrix);

Performing Operations

cpp

ariel::Graph g1(2, 2);
ariel::Graph g2(2, 2);

g1.setAdjacencyMatrix(0, 1, 1);
g2.setAdjacencyMatrix(1, 0, 1);

ariel::Graph g3 = g1 + g2;
g3.printGraph();

Operator Overloads

The Graph class supports various operator overloads for intuitive usage:

cpp

ariel::Graph g1(3, 3);
ariel::Graph g2 = -g1;  // Unary minus
ariel::Graph g3 = g1 * 2;  // Scalar multiplication
g1 += g2;  // Addition assignment

Cleaning Up

To remove the compiled files and clean the directory, run:

sh

make clean

Contributing

Contributions are welcome! Please fork the repository and submit pull requests for any enhancements or bug fixes.
License

This project is licensed under the MIT License. See the LICENSE file for more details.
Contact

For any questions or inquiries, please contact Orel Nissan at orel55551234@gmail.com.

This README file provides a comprehensive guide to understanding, installing, building, and using the Graph Algorithms project.