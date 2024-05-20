#include "Graph.hpp"

namespace ariel {

// Constructor with dimensions
Graph::Graph(int rows, int cols)
    : rows(rows), cols(cols), matrix(static_cast<std::vector<int>::size_type>(rows), std::vector<int>(static_cast<std::vector<int>::size_type>(cols), 0)) {}

// Default constructor
Graph::Graph() : Graph(0, 0) {}

// Destructor
Graph::~Graph() {}

// Load graph from an adjacency matrix
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
void Graph::printGraph() const {
    int numVertices = static_cast<int>(matrix.size());
    int numEdges = 0;

    for (const auto& row : matrix) {
        for (int val : row) {
            if (val != 0) {
                numEdges++;
            }
        }
    }

    std::cout << "Graph with " << numVertices << " vertices and " << numEdges << " edges." << std::endl;
}

// Get adjacency matrix
const std::vector<std::vector<int>>& Graph::getAdjacencyMatrix() const {
    return matrix;
}

// Set a specific value in the adjacency matrix
void Graph::setAdjacencyMatrix(int i, int j, int val) {
    if (i < 0 || static_cast<std::vector<int>::size_type>(i) >= matrix.size() || j < 0 || static_cast<std::vector<int>::size_type>(j) >= matrix[0].size()) {
        throw std::out_of_range("Index out of range");
    }
    matrix[static_cast<std::vector<int>::size_type>(i)][static_cast<std::vector<int>::size_type>(j)] = val;
}

// Utility functions
bool valid_check(const Graph& c1, const Graph& c2) {
    return c1.getRows() == c2.getRows() && c1.getCols() == c2.getCols();
}

// Unary plus
Graph Graph::operator+() const {
    return *this;
}

// Unary minus
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
Graph& Graph::operator--() {
    for (std::vector<int>::size_type i = 0; i < matrix.size(); ++i) {
        for (std::vector<int>::size_type j = 0; j < matrix[i].size(); ++j) {
            --matrix[i][j];
        }
    }
    return *this;
}

// Implement prefix increment operator++
Graph& Graph::operator++() {
    for (std::vector<int>::size_type i = 0; i < matrix.size(); ++i) {
        for (std::vector<int>::size_type j = 0; j < matrix[i].size(); ++j) {
            ++matrix[i][j];
        }
    }
    return *this;
}

// Implement postfix decrement operator-- (int)
Graph Graph::operator--(int) {
    Graph temp = *this;
    --(*this);
    return temp;
}

// Implement postfix increment operator++ (int)
Graph Graph::operator++(int) {
    Graph temp = *this;
    ++(*this);
    return temp;
}

// Implement operator+
Graph operator+(const Graph& c1, const Graph& c2) {
    if (!valid_check(c1, c2)) {
        throw std::runtime_error("Condition failed: The graphs have different dimensions.");
    }

    Graph result = c1;
    result += c2;
    return result;
}

// Implement operator-
Graph operator-(const Graph& c1, const Graph& c2) {
    Graph result = c1;
    result -= c2;
    return result;
}

// Implement operator*
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
Graph& Graph::operator*=(int scalar) {
    for (std::vector<int>::size_type i = 0; i < matrix.size(); ++i) {
        for (std::vector<int>::size_type j = 0; j < matrix[i].size(); ++j) {
            matrix[i][j] *= scalar;
        }
    }
    return *this;
}

// Implement operator/=
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
Graph Graph::operator/(int scalar) const {
    if (scalar == 0) {
        throw std::runtime_error("Division by zero.");
    }
    Graph result(*this);
    result /= scalar;
    return result;
}

// Implement operator*(Graph)
Graph Graph::operator*(const Graph& other) const {
    if (cols != other.rows) {
        throw std::invalid_argument("The number of columns in the first matrix must be equal to the number of rows in the second matrix.");
    }

    Graph result(rows, other.cols);

    for (std::vector<int>::size_type i = 0; i < matrix.size(); ++i) {
        for (std::vector<int>::size_type j = 0; j < other.matrix[0].size(); ++j) {
            int sum = 0;
            for (std::vector<int>::size_type k = 0; k < matrix[i].size(); ++k) {
                sum += matrix[i][k] * other.matrix[k][j];
            }
            result.matrix[i][j] = sum;
        }
    }

    // Ensure the diagonal elements are zero
    for (std::vector<int>::size_type i = 0; i < result.matrix.size(); ++i) {
        for (std::vector<int>::size_type j = 0; j < result.matrix[i].size(); ++j) {
            if (i == j) {
                result.matrix[i][j] = 0;
            }
        }
    }

    return result;
}

// Implement operator*=(Graph)
Graph& Graph::operator*=(const Graph& other) {
    *this = *this * other;
    return *this;
}

bool Graph::operator==(const Graph& other) const {
    if (!valid_check(*this, other)) {
        return false;
    }

    for (std::vector<int>::size_type i = 0; i < matrix.size(); ++i) {
        for (std::vector<int>::size_type j = 0; j < matrix[i].size(); ++j) {
            if (matrix[i][j] != other.matrix[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool Graph::operator!=(const Graph& other) const {
    return !(*this == other);
}

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

bool Graph::operator<=(const Graph& other) const {
    return *this < other || *this == other;
}

bool Graph::operator>(const Graph& other) const {
    return !(*this <= other);
}

bool Graph::operator>=(const Graph& other) const {
    return !(*this < other);
}

// Implement graph composition
Graph Graph::composition(const Graph& other) const {
    if (cols != other.rows) {
        throw std::runtime_error("Graph dimensions do not match for composition.");
    }

    Graph result(rows, other.cols);
    for (std::vector<int>::size_type i = 0; i < matrix.size(); ++i) {
        for (std::vector<int>::size_type j = 0; j < other.matrix[0].size(); ++j) {
            int sum = 0;
            for (std::vector<int>::size_type k = 0; k < matrix[i].size(); ++k) {
                sum += matrix[i][k] * other.matrix[k][j];
            }
            result.matrix[i][j] = sum;
        }
    }
    return result;
}

// Implement graph complementation
Graph Graph::complementation() const {
    Graph result(rows, cols);
    for (std::vector<int>::size_type i = 0; i < matrix.size(); ++i) {
        for (std::vector<int>::size_type j = 0; j < matrix[i].size(); ++j) {
            result.matrix[i][j] = (matrix[i][j] == 0 ? 1 : 0);
        }
    }
    return result;
}

// Implement graph complementation operator
Graph Graph::operator~() const {
    return complementation();
}

// Friend function to print graph
std::ostream& operator<<(std::ostream& os, const Graph& graph) {
    for (const auto& row : graph.matrix) {
        os << "[";
        bool first = true;
        for (int val : row) {
            if (!first) {
                os << ", ";
            }
            os << val;
            first = false;
        }
        os << "]" << std::endl; // Make sure to print a newline after each row
    }
    return os;
}

// Scalar division operator (scalar / graph)
Graph operator/(int scalar, const Graph& graph) {
    Graph result(graph);
    if (scalar == 0) {
        throw std::runtime_error("Division by zero.");
    }
    for (std::vector<int>::size_type i = 0; i < result.matrix.size(); ++i) {
        for (std::vector<int>::size_type j = 0; j < result.matrix[i].size(); ++j) {
            if (result.matrix[i][j] == 0) {
                throw std::runtime_error("Division by zero.");
            }
            result.matrix[i][j] = scalar / result.matrix[i][j];
        }
    }
    return result;
}

// Scalar multiplication operator (scalar * graph)
Graph operator*(int scalar, const Graph& graph) {
    return graph * scalar;
}

} // namespace ariel
 