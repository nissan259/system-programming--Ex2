#include "Algorithms.hpp"
#include <climits>
#include <queue>
#include <algorithm>
//orel55551234@gmail.com
//orel nissan
//322861527
using namespace std;
using namespace ariel;

namespace {
    const int INFINITY_INT = INT_MAX;
    const size_t UNDEFINED_SIZE_T = static_cast<size_t>(-1);

    bool allVisited(const vector<bool>& visited) {
        return all_of(visited.begin(), visited.end(), [](bool visitedFlag) { return visitedFlag; });
    }

    void addToPath(string& path, size_t current) {
        if (!path.empty()) {
            path.insert(0, "->");
        }
        path.insert(0, to_string(current));
    }

    void addToCycle(string& cycle, size_t current) {
        if (!cycle.empty()) {
            cycle.insert(0, "->");
        }
        cycle.insert(0, to_string(current));
    }

    bool containsNegativeCycle(size_t adjSize, const vector<vector<int>>& adjMatrix, vector<int>& distances) {
        for (size_t i = 0; i < adjSize; ++i) {
            for (size_t src = 0; src < adjSize; ++src) {
                for (size_t dest = 0; dest < adjSize; ++dest) {
                    if (adjMatrix[src][dest] != 0 && distances[src] + adjMatrix[src][dest] < distances[dest]) {
                        if (i == adjSize - 1) {
                            return true;
                        }
                        distances[dest] = distances[src] + adjMatrix[src][dest];
                    }
                }
            }
        }
        return false;
    }

    void processVertexQueue(size_t vertex, const vector<vector<int>>& adjMatrix, vector<int>& colors, queue<size_t>& vertexQueue) {
        for (size_t j = 0; j < adjMatrix.size(); ++j) {
            if (adjMatrix[vertex][j] != 0) {
                if (colors[j] == -1) {
                    colors[j] = 1 - colors[vertex];
                    vertexQueue.push(j);
                } else if (colors[j] == colors[vertex]) {
                    throw runtime_error("Graph is not bipartite");
                }
            }
        }
    }

    void populateBipartiteSets(const vector<int>& colors, string& result) {
        bool first = true;
        for (size_t i = 0; i < colors.size(); ++i) {
            if (colors[i] == 0) {
                if (!first) {
                    result += ", ";
                }
                result += to_string(i);
                first = false;
            }
        }
        result += "}, B={";
        first = true;
        for (size_t i = 0; i < colors.size(); ++i) {
            if (colors[i] == 1) {
                if (!first) {
                    result += ", ";
                }
                result += to_string(i);
                first = false;
            }
        }
        result += "}.";
    }
}

void Algorithms::dfs(const Graph& graph, size_t vertex, vector<bool>& visited, vector<size_t>& parent, bool& hasCycle, size_t& cycleStart, size_t& cycleEnd) {
    visited[vertex] = true;
    const auto& adjMatrix = graph.getAdjacencyMatrix();
    for (size_t i = 0; i < adjMatrix.size(); ++i) {
        if (adjMatrix[vertex][i] != 0) {
            if (!visited[i]) {
                parent[i] = vertex;
                dfs(graph, i, visited, parent, hasCycle, cycleStart, cycleEnd);
                if (hasCycle) {
                    return;
                }
            } else if (i != parent[vertex]) {
                hasCycle = true;
                cycleStart = i;
                cycleEnd = vertex;
                return;
            }
        }
    }
}

bool Algorithms::isConnected(const Graph& graph) {
    const auto& adjMatrix = graph.getAdjacencyMatrix();
    vector<bool> visited(adjMatrix.size(), false);

    // Perform DFS starting from vertex 0
    dfs1(graph, 0, visited);

    // Check if all vertices are visited using helper function
    return allVisited(visited);
}

string Algorithms::shortestPath(const Graph& graph, size_t start, size_t end) {
    const auto& adjMatrix = graph.getAdjacencyMatrix();
    vector<int> distances(adjMatrix.size(), INFINITY_INT);
    vector<size_t> parent(adjMatrix.size(), UNDEFINED_SIZE_T);
    distances[start] = 0;

    for (size_t i = 0; i < adjMatrix.size() - 1; ++i) {
        for (size_t src = 0; src < adjMatrix.size(); ++src) {
            for (size_t dest = 0; dest < adjMatrix.size(); ++dest) {
                if (adjMatrix[src][dest] != 0 && distances[src] != INFINITY_INT && distances[src] + adjMatrix[src][dest] < distances[dest]) {
                    distances[dest] = distances[src] + adjMatrix[src][dest];
                    parent[dest] = src;
                }
            }
        }
    }

    if (distances[end] == INFINITY_INT) {
        return "-1";
    }

    string path;
    size_t current = end;
    while (current != UNDEFINED_SIZE_T) {
        addToPath(path, current);
        current = parent[current];
    }

    return path;
}

string Algorithms::isBipartite(const Graph& graph) {
    const auto& adjMatrix = graph.getAdjacencyMatrix();
    vector<int> colors(adjMatrix.size(), -1);

    try {
        for (size_t i = 0; i < adjMatrix.size(); ++i) {
            if (colors[i] == -1) {
                colors[i] = 0;
                queue<size_t> vertexQueue;
                vertexQueue.push(i);

                while (!vertexQueue.empty()) {
                    size_t vertex = vertexQueue.front();
                    vertexQueue.pop();
                    processVertexQueue(vertex, adjMatrix, colors, vertexQueue);
                }
            }
        }
    } catch (const runtime_error&) {
        return "0";
    }

    string result = "The graph is bipartite: A={";
    populateBipartiteSets(colors, result);

    return result;
}

void Algorithms::dfs1(const Graph& graph, size_t vertex, vector<bool>& visited) {
    visited[vertex] = true;
    const auto& adjMatrix = graph.getAdjacencyMatrix();
    for (size_t i = 0; i < adjMatrix.size(); ++i) {
        if (adjMatrix[vertex][i] != 0 && !visited[i]) {
            dfs1(graph, i, visited);
        }
    }
}

string Algorithms::isContainsCycle(const Graph& graph) {
    const auto& adjMatrix = graph.getAdjacencyMatrix();
    vector<bool> visited(adjMatrix.size(), false);
    vector<size_t> parent(adjMatrix.size(), UNDEFINED_SIZE_T);
    bool hasCycle = false;
    size_t cycleStart = UNDEFINED_SIZE_T;
    size_t cycleEnd = UNDEFINED_SIZE_T;

    for (size_t i = 0; i < adjMatrix.size(); ++i) {
        if (!visited[i]) {
            dfs(graph, i, visited, parent, hasCycle, cycleStart, cycleEnd);
            if (hasCycle) {
                string cycle;
                size_t current = cycleEnd;
                while (current != cycleStart) {
                    addToCycle(cycle, current);
                    current = parent[current];
                }
                cycle.insert(0, to_string(cycleStart) + "->");
                cycle += to_string(cycleStart);
                return cycle;
            }
        }
    }

    return "-1";
}

string Algorithms::negativeCycle(const Graph& graph) {
    const auto& adjMatrix = graph.getAdjacencyMatrix();
    vector<int> distances(adjMatrix.size(), 0);

    if (containsNegativeCycle(adjMatrix.size(), adjMatrix, distances)) {
        return "The graph contains a negative cycle.";
    }

    return "The graph does not contain a negative cycle.";
}