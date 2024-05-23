#include "Graph.hpp"
#include <stdexcept>
#include <sstream>
#include <iostream>
#include <vector>

namespace ariel {

// Constructor with dimensions
/**
 * @brief Construct a new Graph object with specified dimensions.
 *
 * @param rows Number of rows in the graph's adjacency matrix.
 * @param cols Number of columns in the graph's adjacency matrix.
 */
    Graph::Graph(int rows, int cols)
            : rows(rows), cols(cols), matrix(static_cast<std::vector<int>::size_type>(rows), std::vector<int>(static_cast<std::vector<int>::size_type>(cols), 0)) {}

// Default constructor
/**
 * @brief Construct a new Graph object with default dimensions (0, 0).
 */
    Graph::Graph() : Graph(0, 0) {}

// Destructor
/**
 * @brief Destroy the Graph object.
 */
    Graph::~Graph() {}

// Load graph from an adjacency matrix
/**
 * @brief Load the graph from an adjacency matrix.
 *
 * @param adjacencyMatrix A 2D vector representing the adjacency matrix of the graph.
 */
    void Graph::loadGraph(const std::vector<std::vector<int>>& adjacencyMatrix) {
        if (adjacencyMatrix.empty()) {
            std::cerr << "Error: Empty adjacency matrix." << std::endl;
            return;
        }

        size_t newRows = adjacencyMatrix.size();
        size_t newCols = adjacencyMatrix[0].size();

        // Check for consistent row sizes in the input matrix
        for (const auto& row : adjacencyMatrix) {
            if (row.size() != newCols) {
                std::cerr << "Error: Dimension mismatch while loading the graph." << std::endl;
                return;
            }
        }

        // If dimensions have changed, resize the matrix
        if (newRows != static_cast<size_t>(rows) || newCols != static_cast<size_t>(cols)) {
            rows = static_cast<int>(newRows);
            cols = static_cast<int>(newCols);
            matrix.resize(static_cast<std::vector<int>::size_type>(rows), std::vector<int>(static_cast<std::vector<int>::size_type>(cols), 0));
        }

        // Copy the contents of the adjacencyMatrix to the matrix
        for (size_t i = 0; i < newRows; ++i) {
            for (size_t j = 0; j < newCols; ++j) {
                matrix[i][j] = adjacencyMatrix[i][j];
            }
        }
    }

// Print the graph
/**
 * @brief Print the graph's adjacency matrix as a string.
 *
 * @return std::string The string representation of the graph's adjacency matrix.
 */
    std::string Graph::printGraph() const {
        std::ostringstream oss;  // Declare the output string stream

        for (const auto& row : matrix) {
            oss << "[";
            for (std::size_t i = 0; i < row.size(); ++i) {
                oss << row[i];
                if (i < row.size() - 1) {
                    oss << ", ";
                }
            }
            oss << "]";
            if (&row != &matrix.back()) {
                oss << "\n";
            }
        }

        return oss.str();
    }

// Get adjacency matrix
/**
 * @brief Get the adjacency matrix of the graph.
 *
 * @return const std::vector<std::vector<int>>& Reference to the adjacency matrix.
 */
    const std::vector<std::vector<int>>& Graph::getAdjacencyMatrix() const {
        return matrix;
    }

// Set a specific value in the adjacency matrix
/**
 * @brief Set a specific value in the adjacency matrix.
 *
 * @param row The row index.
 * @param col The column index.
 * @param val The value to set.
 * @throws std::out_of_range If the index is out of range.
 */
    void Graph::setAdjacencyMatrix(int row, int col, int val) {
        if (row < 0 || static_cast<std::vector<int>::size_type>(row) >= matrix.size() || col < 0 || static_cast<std::vector<int>::size_type>(col) >= matrix[0].size()) {
            throw std::out_of_range("Index out of range");
        }
        matrix[static_cast<std::vector<int>::size_type>(row)][static_cast<std::vector<int>::size_type>(col)] = val;
    }

// Utility functions
/**
 * @brief Check if two graphs have the same dimensions.
 *
 * @param graph1 The first graph.
 * @param graph2 The second graph.
 * @return true If the graphs have the same dimensions.
 * @return false If the graphs have different dimensions.
 */
    bool valid_check(const Graph& graph1, const Graph& graph2) {
        return graph1.getRows() == graph2.getRows() && graph1.getCols() == graph2.getCols();
    }

// Unary plus
/**
 * @brief Unary plus operator for the graph.
 *
 * @return Graph The same graph.
 */
    Graph Graph::operator+() const {
        return *this;
    }

// Unary minus
/**
 * @brief Unary minus operator for the graph.
 *
 * @return Graph A new graph with all values negated.
 */
    Graph Graph::operator-() const {
        Graph result(rows, cols);
        for (std::vector<int>::size_type i = 0; i < matrix.size(); ++i) {
            for (std::vector<int>::size_type j = 0; j < matrix[i].size(); ++j) {
                result.matrix[i][j] = -matrix[i][j];
            }
        }
        return result;
    }

// Implement operator+=
/**
 * @brief Addition assignment operator for the graph.
 *
 * @param other The graph to add.
 * @return Graph& Reference to the updated graph.
 * @throws std::runtime_error If the graphs have different dimensions.
 */
    Graph& Graph::operator+=(const Graph& other) {
        if (rows != other.rows || cols != other.cols) {
            throw std::runtime_error("Condition failed: The graphs have different dimensions.");
        }

        for (std::vector<int>::size_type i = 0; i < matrix.size(); ++i) {
            for (std::vector<int>::size_type j = 0; j < matrix[i].size(); ++j) {
                matrix[i][j] += other.matrix[i][j];
            }
        }

        return *this;
    }

// Implement operator-=
/**
 * @brief Subtraction assignment operator for the graph.
 *
 * @param other The graph to subtract.
 * @return Graph& Reference to the updated graph.
 * @throws std::runtime_error If the graphs have different dimensions.
 */
    Graph& Graph::operator-=(const Graph& other) {
        if (!valid_check(*this, other)) {
            throw std::runtime_error("Condition failed: The graphs have different dimensions.");
        }

        for (std::vector<int>::size_type i = 0; i < matrix.size(); ++i) {
            for (std::vector<int>::size_type j = 0; j < matrix[i].size(); ++j) {
                matrix[i][j] -= other.matrix[i][j];
            }
        }
        return *this;
    }

// Implement prefix decrement operator--
/**
 * @brief Prefix decrement operator for the graph.
 *
 * @return Graph& Reference to the updated graph with all non-diagonal elements decremented by 1.
 */
    Graph& Graph::operator--() {
        for (std::vector<int>::size_type i = 0; i < rows; ++i) {
            for (std::vector<int>::size_type j = 0; j < cols; ++j) {
                if (i != j) {
                    --matrix[i][j];
                }
            }
        }
        return *this;
    }

// Implement prefix increment operator++
/**
 * @brief Prefix increment operator for the graph.
 *
 * @return Graph& Reference to the updated graph with all non-diagonal elements incremented by 1.
 */
    Graph& Graph::operator++() {
        for (std::vector<int>::size_type i = 0; i < rows; ++i) {
            for (std::vector<int>::size_type j = 0; j < cols; ++j) {
                if (i != j) {
                    ++matrix[i][j];
                }
            }
        }
        return *this;
    }

// Implement postfix decrement operator-- (int)
/**
 * @brief Postfix decrement operator for the graph.
 *
 * @return Graph The graph before the decrement.
 */
    Graph Graph::operator--(int) {
        Graph temp = *this;
        --(*this);
        return temp;
    }

// Implement postfix increment operator++ (int)
/**
 * @brief Postfix increment operator for the graph.
 *
 * @return Graph The graph before the increment.
 */
    Graph Graph::operator++(int) {
        Graph temp = *this;
        ++(*this);
        return temp;
    }

// Implement operator+
/**
 * @brief Addition operator for two graphs.
 *
 * @param graph1 The first graph.
 * @param graph2 The second graph.
 * @return Graph The result of adding the two graphs.
 * @throws std::runtime_error If the graphs have different dimensions.
 */
    Graph operator+(const Graph& graph1, const Graph& graph2) {
        if (!valid_check(graph1, graph2)) {
            throw std::runtime_error("Condition failed: The graphs have different dimensions.");
        }

        Graph result = graph1;
        result += graph2;
        return result;
    }

// Implement operator-
/**
 * @brief Subtraction operator for two graphs.
 *
 * @param graph1 The first graph.
 * @param graph2 The second graph.
 * @return Graph The result of subtracting the second graph from the first graph.
 */
    Graph operator-(const Graph& graph1, const Graph& graph2) {
        Graph result = graph1;
        result -= graph2;
        return result;
    }

// Implement operator*
/**
 * @brief Scalar multiplication operator for the graph.
 *
 * @param scalar The scalar value.
 * @return Graph The result of multiplying the graph by the scalar.
 */
    Graph Graph::operator*(int scalar) const {
        Graph result(rows, cols);
        for (std::vector<int>::size_type i = 0; i < matrix.size(); ++i) {
            for (std::vector<int>::size_type j = 0; j < matrix[i].size(); ++j) {
                result.matrix[i][j] = matrix[i][j] * scalar;
            }
        }

        return result;
    }

// Implement operator*=
/**
 * @brief Scalar multiplication assignment operator for the graph.
 *
 * @param scalar The scalar value.
 * @return Graph& Reference to the updated graph.
 */
    Graph& Graph::operator*=(int scalar) {
        for (std::vector<int>::size_type i = 0; i < matrix.size(); ++i) {
            for (std::vector<int>::size_type j = 0; j < matrix[i].size(); ++j) {
                matrix[i][j] *= scalar;
            }
        }
        return *this;
    }

// Implement operator/=
/**
 * @brief Scalar division assignment operator for the graph.
 *
 * @param scalar The scalar value.
 * @return Graph& Reference to the updated graph.
 * @throws std::runtime_error If the scalar value is zero.
 */
    Graph& Graph::operator/=(int scalar) {
        if (scalar == 0) {
            throw std::runtime_error("Division by zero.");
        }
        for (std::vector<int>::size_type i = 0; i < matrix.size(); ++i) {
            for (std::vector<int>::size_type j = 0; j < matrix[i].size(); ++j) {
                matrix[i][j] /= scalar;
            }
        }
        return *this;
    }

// Scalar division operator
/**
 * @brief Scalar division operator for the graph.
 *
 * @param scalar The scalar value.
 * @return Graph The result of dividing the graph by the scalar.
 * @throws std::runtime_error If the scalar value is zero.
 */
    Graph Graph::operator/(int scalar) const {
        if (scalar == 0) {
            throw std::runtime_error("Division by zero.");
        }
        Graph result(*this);
        result /= scalar;
        return result;
    }

// Implement operator*(Graph)
/**
 * @brief Matrix multiplication operator for two graphs.
 *
 * @param other The other graph.
 * @return Graph The result of multiplying the two graphs.
 * @throws std::invalid_argument If the graphs are not square or their dimensions do not match.
 */
    Graph Graph::operator*(const Graph& other) const {
        // Check if either matrix is empty
        if (this->matrix.empty() || other.matrix.empty()) {
            return Graph(); // Return an empty graph if either matrix is empty
        }

        // Check if both matrices are square
        if (this->matrix.size() != this->matrix[0].size() || other.matrix.size() != other.matrix[0].size()) {
            throw std::invalid_argument("Both matrices must be square for multiplication.");
        }

        // Check if the dimensions of the matrices match for multiplication
        if (this->matrix.size() != other.matrix.size()) {
            throw std::invalid_argument("The dimensions of the matrices do not match for multiplication.");
        }

        Graph result;
        size_t numRows = this->matrix.size();
        result.matrix.resize(numRows, std::vector<int>(numRows, 0));

        for (size_t i = 0; i < numRows; ++i) {
            for (size_t j = 0; j < numRows; ++j) {
                for (size_t k = 0; k < numRows; ++k) {
                    result.matrix[i][j] += this->matrix[i][k] * other.matrix[k][j];
                }
            }
        }

        // Set diagonal elements to zero
        for (size_t i = 0; i < numRows; ++i) {
            result.matrix[i][i] = 0;
        }

        return result;
    }

// Implement operator*=
/**
 * @brief Matrix multiplication assignment operator for the graph.
 *
 * @param other The other graph.
 * @return Graph& Reference to the updated graph.
 */
    Graph& Graph::operator*=(const Graph& other) {
        *this = *this * other;
        return *this;
    }

/**
 * @brief Equality operator for two graphs.
 *
 * @param other The other graph.
 * @return true If the graphs are equal.
 * @return false If the graphs are not equal.
 */
    bool Graph::operator==(const Graph& other) const {
        if (!valid_check(*this, other)) {
            return false;
        }

        // Check if the graphs have the same edges and weights
        bool same_edges_and_weights = true;
        for (std::vector<int>::size_type i = 0; i < matrix.size(); ++i) {
            for (std::vector<int>::size_type j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] != other.matrix[i][j]) {
                    same_edges_and_weights = false;
                    break;
                }
            }
            if (!same_edges_and_weights) {
                break;
            }
        }

        if (same_edges_and_weights) {
            return true;
        }

        // Check if G1 is not greater than G2 and G2 is not greater than G1
        bool g1_not_greater = true;
        bool g2_not_greater = true;
        for (std::vector<int>::size_type i = 0; i < matrix.size(); ++i) {
            for (std::vector<int>::size_type j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] > other.matrix[i][j]) {
                    g1_not_greater = false;
                }
                if (other.matrix[i][j] > matrix[i][j]) {
                    g2_not_greater = false;
                }
                if (!g1_not_greater && !g2_not_greater) {
                    return false;
                }
            }
        }

        return g1_not_greater && g2_not_greater;
    }

/**
 * @brief Inequality operator for two graphs.
 *
 * @param other The other graph.
 * @return true If the graphs are not equal.
 * @return false If the graphs are equal.
 */
    bool Graph::operator!=(const Graph& other) const {
        return !(*this == other);
    }

/**
 * @brief Less than operator for two graphs.
 *
 * @param other The other graph.
 * @return true If this graph is less than the other graph.
 * @return false Otherwise.
 */
    bool Graph::operator<(const Graph& other) const {
        if (rows < other.rows || (rows == other.rows && cols < other.cols)) {
            return true;
        }

        for (std::vector<int>::size_type i = 0; i < matrix.size(); ++i) {
            for (std::vector<int>::size_type j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] < other.matrix[i][j]) {
                    return true;
                } else if (matrix[i][j] > other.matrix[i][j]) {
                    return false;
                }
            }
        }
        return false;
    }

/**
 * @brief Less than or equal operator for two graphs.
 *
 * @param other The other graph.
 * @return true If this graph is less than or equal to the other graph.
 * @return false Otherwise.
 */
    bool Graph::operator<=(const Graph& other) const {
        return *this < other || *this == other;
    }

/**
 * @brief Greater than operator for two graphs.
 *
 * @param other The other graph.
 * @return true If this graph is greater than the other graph.
 * @return false Otherwise.
 */
    bool Graph::operator>(const Graph& other) const {
        return !(*this <= other);
    }

/**
 * @brief Greater than or equal operator for two graphs.
 *
 * @param other The other graph.
 * @return true If this graph is greater than or equal to the other graph.
 * @return false Otherwise.
 */
    bool Graph::operator>=(const Graph& other) const {
        return !(*this < other);
    }

// Friend function to print graph
/**
 * @brief Output stream operator to print the graph.
 *
 * @param output The output stream.
 * @param graph The graph to print.
 * @return std::ostream& Reference to the output stream.
 */
    std::ostream& operator<<(std::ostream& output, const Graph& graph) {
        for (const auto& row : graph.matrix) {
            output << "[";
            bool first = true;
            for (int val : row) {
                if (!first) {
                    output << ", ";
                }
                output << val;
                first = false;
            }
            output << "]" << std::endl; // Make sure to print a newline after each row
        }
        return output;
    }

// Scalar division operator (scalar / graph)
/**
 * @brief Scalar division operator for a scalar and a graph.
 *
 * @param scalar The scalar value.
 * @param graph The graph to divide.
 * @return Graph The result of dividing the scalar by the graph.
 * @throws std::runtime_error If the scalar value is zero.
 */
    Graph operator/(int scalar, const Graph& graph) {
        if (scalar == 0) {
            throw std::runtime_error("Division by zero: scalar is zero.");
        }

        Graph result(graph);
        std::vector<std::vector<int>> adjacencyMatrix = result.getAdjacencyMatrix();

        for (std::vector<int>::size_type i = 0; i < adjacencyMatrix.size(); ++i) {
            for (std::vector<int>::size_type j = 0; j < adjacencyMatrix[i].size(); ++j) {
                if (adjacencyMatrix[i][j] != 0) {
                    adjacencyMatrix[i][j] = scalar / adjacencyMatrix[i][j];
                }
            }
        }

        result.loadGraph(adjacencyMatrix);
        return result;
    }

// Scalar multiplication operator (scalar * graph)
/**
 * @brief Scalar multiplication operator for a scalar and a graph.
 *
 * @param scalar The scalar value.
 * @param graph The graph to multiply.
 * @return Graph The result of multiplying the scalar by the graph.
 */
    Graph operator*(int scalar, const Graph& graph) {
        return graph * scalar;
    }

} // namespace ariel
