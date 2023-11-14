#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void Dijkstra(vector<vector<pair<int, int>>>& graph, int src) {
    vector<int> distances(graph.size(), INT_MAX);
    distances[src] = 0;

    set<pair<int, int>> nodes;
    nodes.insert({0, src});

    while (!nodes.empty()) {
        int dist = nodes.begin()->first;
        int currentNode = nodes.begin()->second;
        nodes.erase(nodes.begin());

        if (dist != distances[currentNode]) {
            continue;
        }

        for (const auto& edge : graph[currentNode]) {
            int neighbor = edge.first;
            int distanceToNeighbor = edge.second;

            if (distances[currentNode] + distanceToNeighbor < distances[neighbor]) {
                distances[neighbor] = distances[currentNode] + distanceToNeighbor;
                nodes.insert({distances[neighbor], neighbor});
            }
        }
    }

    for (int i = 0; i < distances.size(); i++) {
        cout << "Shortest distance from node " << src << " to node " << i << " is: " << distances[i] << endl;
    }
}

int main() {
    vector<vector<pair<int, int>>> graph(6);

    graph[0].push_back({1, 10});
    graph[0].push_back({2, 3});
    graph[0].push_back({3, 1});

    graph[1].push_back({2, 2});
    graph[1].push_back({4, 5});

    graph[2].push_back({3, 4});
    graph[2].push_back({4, 2});

    graph[3].push_back({4, 8});

    graph[4].push_back({5, 6});

    Dijkstra(graph, 0);

    return 0;
}
