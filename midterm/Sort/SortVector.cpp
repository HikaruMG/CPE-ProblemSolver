#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> pii;

vector<int> dijkstra(vector<vector<pii>>& adj, int V, int src) {
    vector<int> dist(V + 1, INT_MAX);
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
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    int V = 5;
    vector<vector<pii>> adj(V + 1);

    // ใช้ tuple<int, int, int> สำหรับ edges
    vector<tuple<int, int, int>> edges = {{1, 2, 4}, {1, 3, 8}, {2, 3, 2}};

    // สร้าง Adjacency List (ใช้ get<> แทน structured binding)
    for (auto& edge : edges) {
        int u = get<0>(edge);
        int v = get<1>(edge);
        int w = get<2>(edge);
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // หาเส้นทางที่สั้นที่สุดจากจุด 1
    vector<int> dist = dijkstra(adj, V, 1);

    cout << "Shortest distances from vertex 1:\n";
    for (int i = 1; i <= V; i++) {
        if (dist[i] == INT_MAX) {
            cout << "Vertex " << i << ": Unreachable" << endl;
        } else {
            cout << "Vertex " << i << ": " << dist[i] << endl;
        }
    }

    return 0;
}