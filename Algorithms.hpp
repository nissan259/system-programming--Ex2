#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP
//orel55551234@gmail.com
//orel nissan
//322861527
#include "Graph.hpp"
#include <string>
#include <vector>

namespace ariel {
    class Algorithms {
    public:
        static bool isConnected(const Graph& graph);
        static std::string shortestPath(const Graph& graph, size_t start, size_t end);
        static std::string isBipartite(const Graph& graph);
        static std::string isContainsCycle(const Graph& graph);
        static std::string negativeCycle(const Graph& graph);

    private:
        static void dfs1(const Graph& graph, size_t vertex, std::vector<bool>& visited);
        static void dfs(const Graph& graph, size_t vertex, std::vector<bool>& visited, std::vector<size_t>& parent, bool& hasCycle, size_t& cycleStart, size_t& cycleEnd);
    };
}

#endif // ALGORITHMS_HPP