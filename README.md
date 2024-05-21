```markdown
# Graph Algorithms Project

This repository contains a C++ implementation of various graph algorithms. The project is designed to showcase the functionality of graph operations including loading graphs, manipulating adjacency matrices, and performing graph arithmetic operations.


## Introduction

The Graph Algorithms Project is implemented in C++ and provides a comprehensive set of functionalities for working with graphs. The main component of the project is the `Graph` class, which supports various operations such as graph loading, printing, arithmetic operations, and more.

## Setup and Compilation

To compile the project, use the following commands:

to run the test
make
/.test
if you want to run the demo
raplce the main's
and then
make
/.demo
This will compile the source files and produce an executable named `test`.

## Running the Tests

After compilation, run the tests using:

```sh
./test
```

You should see output indicating that all tests have passed:

```
[doctest] doctest version is "2.4.11"
[doctest] run with "--help" for options
===============================================================================
[doctest] test cases: 24 | 24 passed | 0 failed | 0 skipped
[doctest] assertions: 70 | 70 passed | 0 failed |
[doctest] Status: SUCCESS!
```

## Graph Class Overview

### Constructor and Destructor

- **Graph(int rows, int cols)**: Constructs a graph with the specified number of rows and columns.
- **Graph()**: Default constructor.
- **~Graph()**: Destructor.

### Graph Loading and Printing

- **void loadGraph(const std::vector<std::vector<int>>& adjacencyMatrix)**: Loads a graph from an adjacency matrix.
- **std::string printGraph() const**: Returns a string representation of the graph.

### Accessor Methods

- **int getRows() const**: Returns the number of rows.
- **int getCols() const**: Returns the number of columns.
- **const std::vector<std::vector<int>>& getMatrix() const**: Returns the adjacency matrix.
- **std::vector<std::vector<int>>& getMatrix()**: Returns a non-const reference to the adjacency matrix.

### Operator Overloading

- **Graph operator+() const**: Unary plus.
- **Graph operator-() const**: Unary minus.
- **Graph& operator+=(const Graph& other)**: Adds another graph to this graph.
- **Graph& operator-=(const Graph& other)**: Subtracts another graph from this graph.
- **Graph& operator--()**: Prefix decrement.
- **Graph operator--(int)**: Postfix decrement.
- **Graph& operator++()**: Prefix increment.
- **Graph operator++(int)**: Postfix increment.
- **Graph operator*(int scalar) const**: Multiplies the graph by a scalar.
- **Graph& operator*=(int scalar)**: Multiplies the graph by a scalar and assigns the result to this graph.
- **Graph operator/(int scalar) const**: Divides the graph by a scalar.
- **Graph& operator/=(int scalar)**: Divides the graph by a scalar and assigns the result to this graph.
- **Graph operator*(const Graph& other) const**: Multiplies this graph with another graph.
- **Graph& operator*=(const Graph& other)**: Multiplies this graph with another graph and assigns the result to this graph.

### Graph Composition and Complementation

- **Graph composition(const Graph& other) const**: Returns the composition of this graph with another graph.
- **Graph complementation() const**: Returns the complementation of this graph.
- **Graph operator~() const**: Complementation operator.

### Friend Functions

- **friend std::ostream& operator<<(std::ostream& os, const Graph& graph)**: Overloads the stream insertion operator for printing the graph.
- **friend Graph operator/(int scalar, const Graph& graph)**: Scalar division operator.
- **friend Graph operator*(int scalar, const Graph& graph)**: Scalar multiplication operator.

### Additional Functions

- **bool valid_check(const Graph& c1, const Graph& c2)**: Checks if two graphs have valid dimensions for operations.
- **Graph operator+(const Graph& c1, const Graph& c2)**: Adds two graphs.
- **Graph operator-(const Graph& c1, const Graph& c2)**: Subtracts one graph from another.

## Contact Information

- **Name**: Orel Nissan
- **ID****: 322861527
- **Email**: orel55551234@gmail.com


Feel free to copy and paste this README content into your GitHub repository.
