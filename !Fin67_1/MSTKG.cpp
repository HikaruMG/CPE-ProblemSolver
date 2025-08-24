#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DSU {
private:
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);  // Path Compression
        return parent[x];
    }

    bool union_set(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY])
                parent[rootY] = rootX;
            else if (rank[rootX] < rank[rootY])
                parent[rootX] = rootY;
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            return true;
        }
        return false;
    }
};

struct Edge {
    int u, v, weight;

    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

vector<Edge> kruskal(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());

    DSU dsu(V);
    vector<Edge> mst;

    for (const Edge& edge : edges) {
        if (dsu.union_set(edge.u, edge.v)) {
            mst.push_back(edge);
            if (mst.size() == V - 1) break;
        }
    }

    return mst;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges;
    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        edges.push_back({u, v, weight});
    }

    vector<Edge> mst = kruskal(V, edges);

    cout << "Minimum Spanning Tree (MST) Edges:\n";
    for (const Edge& edge : mst) {
        cout << edge.u << " - " << edge.v << " : " << edge.weight << endl;
    }

    return 0;
}
