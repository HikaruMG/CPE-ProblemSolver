#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

struct Edge {
    int next, weight;
};

void solve() {
    int n, m, S, T;
    cin >> n >> m >> S >> T;
    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    vector<int> dist(n, numeric_limits<int>::max());
    dist[S] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, S});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (const auto& edge : graph[u]) {
            int v = edge.next;
            int w = edge.weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[T] == numeric_limits<int>::max()) {
        cout << "unreachable" << endl;
    } else {
        cout << dist[T] << endl;
    }
}

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
