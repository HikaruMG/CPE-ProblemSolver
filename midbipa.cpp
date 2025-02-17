#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(vector<vector<int>>& adj, vector<int>& degree, int n, int k) {
    vector<int> color(n + 1, -1); // -1: not visited, 0: team A, 1: team B

    for (int i = 1; i <= n; ++i) {
        if (degree[i] >= k) continue; // Skip nodes with degree >= k
        if (color[i] == -1) { // If not visited
            queue<int> q;
            q.push(i);
            color[i] = 0; // Assign team A

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (degree[v] >= k) continue; // Skip nodes with degree >= k
                    if (color[v] == -1) {
                        color[v] = 1 - color[u]; // Assign opposite team
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        return false; // Conflict found
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> adj(n + 1);
    vector<int> degree(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        degree[a]++;
        degree[b]++;
    }

    if (k == n) {
        // Special case: no restrictions on nodes with high degree
        vector<int> color(n + 1, -1);
        queue<int> q;

        for (int i = 1; i <= n; ++i) {
            if (color[i] == -1) {
                q.push(i);
                color[i] = 0;

                while (!q.empty()) {
                    int u = q.front();
                    q.pop();

                    for (int v : adj[u]) {
                        if (color[v] == -1) {
                            color[v] = 1 - color[u];
                            q.push(v);
                        } else if (color[v] == color[u]) {
                            cout << "no\n";
                            return 0;
                        }
                    }
                }
            }
        }
        cout << "yes\n";
    } else {
        if (isBipartite(adj, degree, n, k)) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }

    return 0;
}
