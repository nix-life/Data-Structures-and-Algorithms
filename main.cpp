#include <algorithm>
#include <iostream>
#include <limits>
#include <queue>
#include <stdexcept>
#include <utility>
#include <vector>

class WeightedGraph {
private:
    struct Edge {
        int to;
        int weight;
    };

    std::vector<std::vector<Edge>> adjacencyList;

    void validateVertex(int vertex) const {
        if (vertex < 0 || vertex >= static_cast<int>(adjacencyList.size())) {
            throw std::out_of_range("Vertex is out of range");
        }
    }

public:
    static constexpr int INF = std::numeric_limits<int>::max();

    explicit WeightedGraph(int vertices)
        : adjacencyList(vertices) {
        if (vertices < 0) {
            throw std::invalid_argument("Number of vertices cannot be negative");
        }
    }

    void addDirectedEdge(int from, int to, int weight) {
        validateVertex(from);
        validateVertex(to);

        if (weight < 0) {
            throw std::invalid_argument("Dijkstra's algorithm does not support negative edge weights");
        }

        adjacencyList[from].push_back({to, weight});
    }

    void addUndirectedEdge(int vertexA, int vertexB, int weight) {
        addDirectedEdge(vertexA, vertexB, weight);
        addDirectedEdge(vertexB, vertexA, weight);
    }

    std::vector<int> dijkstra(int start, std::vector<int>& previous) const {
        validateVertex(start);

        const int vertexCount = static_cast<int>(adjacencyList.size());
        std::vector<int> distances(vertexCount, INF);
        previous.assign(vertexCount, -1);

        using QueueNode = std::pair<int, int>; // distance, vertex
        std::priority_queue<QueueNode, std::vector<QueueNode>, std::greater<QueueNode>> priorityQueue;

        distances[start] = 0;
        priorityQueue.push({0, start});

        while (!priorityQueue.empty()) {
            const auto [currentDistance, currentVertex] = priorityQueue.top();
            priorityQueue.pop();

            if (currentDistance > distances[currentVertex]) {
                continue;
            }

            for (const Edge& edge : adjacencyList[currentVertex]) {
                if (distances[currentVertex] > INF - edge.weight) {
                    continue;
                }

                const int newDistance = distances[currentVertex] + edge.weight;
                if (newDistance < distances[edge.to]) {
                    distances[edge.to] = newDistance;
                    previous[edge.to] = currentVertex;
                    priorityQueue.push({newDistance, edge.to});
                }
            }
        }

        return distances;
    }

    std::vector<int> shortestPath(int start, int end) const {
        validateVertex(end);

        std::vector<int> previous;
        std::vector<int> distances = dijkstra(start, previous);

        if (distances[end] == INF) {
            return {};
        }

        std::vector<int> path;
        for (int current = end; current != -1; current = previous[current]) {
            path.push_back(current);
        }

        std::reverse(path.begin(), path.end());
        return path;
    }
};

void printPath(const std::vector<int>& path) {
    if (path.empty()) {
        std::cout << "No path";
        return;
    }

    for (int i = 0; i < static_cast<int>(path.size()); i++) {
        std::cout << path[i];
        if (i + 1 < static_cast<int>(path.size())) {
            std::cout << " -> ";
        }
    }
}

int main() {
    WeightedGraph graph(6);

    graph.addUndirectedEdge(0, 1, 7);
    graph.addUndirectedEdge(0, 2, 9);
    graph.addUndirectedEdge(0, 5, 14);
    graph.addUndirectedEdge(1, 2, 10);
    graph.addUndirectedEdge(1, 3, 15);
    graph.addUndirectedEdge(2, 3, 11);
    graph.addUndirectedEdge(2, 5, 2);
    graph.addUndirectedEdge(3, 4, 6);
    graph.addUndirectedEdge(4, 5, 9);

    const int start = 0;
    std::vector<int> previous;
    std::vector<int> distances = graph.dijkstra(start, previous);

    std::cout << "Shortest distances from vertex " << start << ":\n";
    for (int vertex = 0; vertex < static_cast<int>(distances.size()); vertex++) {
        std::cout << "Vertex " << vertex << ": ";
        if (distances[vertex] == WeightedGraph::INF) {
            std::cout << "unreachable\n";
        } else {
            std::cout << distances[vertex] << "\n";
        }
    }

    const int end = 4;
    std::cout << "\nShortest path from " << start << " to " << end << ": ";
    printPath(graph.shortestPath(start, end));
    std::cout << "\n";

    return 0;
}
