#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// โครงสร้างข้อมูลสำหรับขอบ (Edge)
struct Edge {
    int u, v; // โหนดสองโหนดที่เชื่อมกัน
    ll cost;  // ค่าใช้จ่าย
    bool operator<(const Edge& other) const {
        return cost < other.cost; // เรียงลำดับตามค่าใช้จ่ายน้อยไปมาก
    }
};

// Disjoint Set Union (DSU) สำหรับการหา MST
class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; i++) parent[i] = i;
    }
    
    int find(int u) {
        if (parent[u] != u) parent[u] = find(parent[u]);
        return parent[u];
    }
    
    bool unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return false; // อยู่ในเซตเดียวกันแล้ว
        if (rank[pu] < rank[pv]) swap(pu, pv);
        parent[pv] = pu;
        if (rank[pu] == rank[pv]) rank[pu]++;
        return true;
    }
};

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    vector<Edge> edges(M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d %lld", &edges[i].u, &edges[i].v, &edges[i].cost);
    }
    
    // เรียงลำดับขอบตามค่าใช้จ่าย
    sort(edges.begin(), edges.end());
    
    // หา MST ด้วย Kruskal's Algorithm
    DSU dsu(N);
    vector<Edge> mst;
    ll mst_cost = 0;
    int edges_used = 0;
    
    for (int i = 0; i < M; i++) {
        if (dsu.unite(edges[i].u, edges[i].v)) {
            mst.push_back(edges[i]);
            mst_cost += edges[i].cost;
            edges_used++;
        }
    }
    
    // ตรวจสอบว่า MST สร้างได้ครบหรือไม่
    if (edges_used != N - 1) {
        printf("-1\n");
        return 0;
    }
    
    // หาขอบที่ถูกที่สุดที่ไม่ได้อยู่ใน MST เพื่อเพิ่ม cycle
    ll min_extra_cost = -1;
    for (int i = 0; i < M; i++) {
        if (dsu.find(edges[i].u) == dsu.find(edges[i].v)) { // ขอบนี้สร้าง cycle
            if (find(mst.begin(), mst.end(), edges[i]) == mst.end()) { // ไม่ได้อยู่ใน MST
                if (min_extra_cost == -1 || edges[i].cost < min_extra_cost) {
                    min_extra_cost = edges[i].cost;
                }
            }
        }
    }
    
    if (min_extra_cost == -1) {
        printf("-1\n");
    } else {
        printf("%lld\n", mst_cost + min_extra_cost);
    }
    
    return 0;
}