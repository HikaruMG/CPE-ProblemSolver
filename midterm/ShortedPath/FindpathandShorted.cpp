#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <tuple>
using namespace std;

typedef pair<int, int> pii;

void printPath(vector<int>& parent, int v) {
    if (v == -1) return;
    printPath(parent, parent[v]);
    cout << v << " ";
}

void dijkstraWithPath(vector<vector<pii>>& adj, int V, int src) {
    vector<int> dist(V + 1, INT_MAX);
    vector<int> parent(V + 1, -1);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Shortest paths from vertex " << src << ":\n";
    for (int i = 1; i <= V; i++) {
        if (dist[i] == INT_MAX) {
            cout << "Vertex " << i << ": Unreachable" << endl;
        } else {
            cout << "Vertex " << i << ": Distance = " << dist[i] << ", Path = ";
            printPath(parent, i);
            cout << endl;
        }
    }
}

int main() {
    int V = 5, E = 7;
    vector<vector<pii>> adj(V + 1);
    vector<tuple<int, int, int>> edges = {
        {1, 2, 4}, {1, 3, 8}, {2, 3, 2}, {2, 4, 5},
        {3, 4, 1}, {3, 5, 3}, {4, 5, 7}
    };

    for (auto& edge : edges) {
        int u = get<0>(edge);
        int v = get<1>(edge);
        int w = get<2>(edge);
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dijkstraWithPath(adj, V, 1);
    return 0;
}