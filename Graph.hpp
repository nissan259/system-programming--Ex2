#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <stdexcept>
#include <iostream>

namespace ariel {

class Graph {
private:
    int rows;
    int cols;
    std::vector<std::vector<int>> matrix;

public:
    Graph(int rows, int cols);
    Graph();
    ~Graph();

    void loadGraph(const std::vector<std::vector<int>>& adjacencyMatrix);
    void printGraph() const;
    const std::vector<std::vector<int>>& getAdjacencyMatrix() const;
    void setAdjacencyMatrix(int i, int j, int val);

    // Accessor methods
    int getRows() const { return rows; }
    int getCols() const { return cols; }
    const std::vector<std::vector<int>>& getMatrix() const { return matrix; }
    std::vector<std::vector<int>>& getMatrix() { return matrix; }

    // Operator overloading
    Graph operator+() const; // Unary plus
    Graph operator-() const; // Unary minus
    Graph& operator+=(const Graph& other);
    Graph& operator-=(const Graph& other);
    Graph& operator--();    // Prefix decrement
    Graph operator--(int);  // Postfix decrement
    Graph& operator++();    // Prefix increment
    Graph operator++(int);  // Postfix increment
    Graph operator*(int scalar) const;
    Graph& operator*=(int scalar);
    Graph operator/(int scalar) const;
    Graph& operator/=(int scalar);
    Graph operator*(const Graph& other) const;
    Graph& operator*=(const Graph& other);

    bool operator==(const Graph& other) const;
    bool operator!=(const Graph& other) const;
    bool operator<(const Graph& other) const;
    bool operator<=(const Graph& other) const;
    bool operator>(const Graph& other) const;
    bool operator>=(const Graph& other) const;

    // Graph composition
    Graph composition(const Graph& other) const;
    // Graph complementation
    Graph complementation() const;
    // Graph complementation operator
    Graph operator~() const;

    // Friend functions
    friend std::ostream& operator<<(std::ostream& os, const Graph& graph);
    // Scalar division operator (scalar / graph)
    friend Graph operator/(int scalar, const Graph& graph);
    // Scalar multiplication operator (scalar * graph)
    friend Graph operator*(int scalar, const Graph& graph);
};

// Additional functions
bool valid_check(const Graph& c1, const Graph& c2);
Graph operator+(const Graph& c1, const Graph& c2);
Graph operator-(const Graph& c1, const Graph& c2);

} // namespace ariel

#endif // GRAPH_H
