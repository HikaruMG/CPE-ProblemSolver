#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

vector<int> V, Depth;

int find(int u) {
    if (u != V[u])
        V[u] = find(V[u]);
    return V[u];
}

bool unionFind(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return false;
    if (Depth[u] < Depth[v]) swap(u, v);
    V[v] = u;
    if (Depth[u] == Depth[v]) Depth[u]++;
    return true;
}

int main() {
    int N, M;
    cin >> N >> M;
    V.resize(N + 1);
    Depth.resize(N + 1, 0);
    for (int i = 1; i <= N; i++) V[i] = i;

    vector<Edge> E(M);
    for (int i = 0; i < M; i++) {
        cin >> E[i].u >> E[i].v >> E[i].w;
    }
    sort(E.begin(), E.end());
    int MinWeight = 0;
    for (Edge& edge : E) {
        if (unionFind(edge.u, edge.v)) {
            MinWeight += edge.w;
        }
    }

    cout << MinWeight << endl;
    return 0;
}
