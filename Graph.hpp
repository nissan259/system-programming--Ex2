#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <iostream>

namespace ariel {

    class Graph {
    private:
        int rows;
        int cols;
        std::vector<std::vector<int>> matrix;

    public:
        // Constructor with dimensions
        Graph(int rows, int cols);

        // Default constructor
        Graph();

        // Destructor
        ~Graph();

        // Load graph from an adjacency matrix
        void loadGraph(const std::vector<std::vector<int>>& adjacencyMatrix);

        // Print the graph
        std::string printGraph() const;

        // Get adjacency matrix
        const std::vector<std::vector<int>>& getAdjacencyMatrix() const;

        // Set a specific value in the adjacency matrix
        void setAdjacencyMatrix(int row, int col, int val);

        // Getters
        int getRows() const { return rows; }
        int getCols() const { return cols; }

        // Unary operators
        Graph operator+() const;
        Graph operator-() const;

        // Compound assignment operators
        Graph& operator+=(const Graph& other);
        Graph& operator-=(const Graph& other);
        Graph& operator*=(int scalar);
        Graph& operator/=(int scalar);
        Graph& operator*=(const Graph& other);

        // Increment and decrement operators
        Graph& operator++();    // Prefix increment
        Graph operator++(int); // Postfix increment
        Graph& operator--();    // Prefix decrement
        Graph operator--(int); // Postfix decrement

        // Comparison operators
        bool operator==(const Graph& other) const;
        bool operator!=(const Graph& other) const;
        bool operator<(const Graph& other) const;
        bool operator<=(const Graph& other) const;
        bool operator>(const Graph& other) const;
        bool operator>=(const Graph& other) const;

        // Arithmetic operators
        Graph operator*(int scalar) const;
        Graph operator/(int scalar) const;
        Graph operator*(const Graph& other) const;

        // Complementation operator


        // Friend function for output
        friend std::ostream& operator<<(std::ostream& output, const Graph& graph);
    };

// Utility functions
    bool valid_check(const Graph& graph1, const Graph& graph2);

// Binary arithmetic operators
    Graph operator+(const Graph& graph1, const Graph& graph2);
    Graph operator-(const Graph& graph1, const Graph& graph2);

// Scalar arithmetic operators
    Graph operator*(int scalar, const Graph& graph);
    Graph operator/(int scalar, const Graph& graph);

} // namespace ariel

#endif // GRAPH_HPP