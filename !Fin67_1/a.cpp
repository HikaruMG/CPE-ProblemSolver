#include <bits/stdc++.h>
using namespace std;

vector<int> parent, ranks;
void initUnionFind(int n) {
    parent.resize(n);
    ranks.resize(n,0);
    for (int a = 0; a < n; ++a) {
        parent[a] = a;
    }
}

int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

bool unions (int u, int v) {
    int pu = find(u), pv = find(v);
    if (pu == pv) return false;
    if (ranks[pu] < ranks[pv]) swap(pu, pv);
    parent[pv] = pu;
    if (ranks[pu] == ranks[pv]) ranks[pu]++;
    return true;
}

int main() {
    int N, Q;
    cin >> N >> Q;

    DisjointSet ds(N); // สร้าง DSU สำหรับ N ฟองนม

    for (int i = 0; i < Q; i++) {
        char type;
        int x, y;
        cin >> type >> x >> y;

        if (type == 'c') {
            ds.unite(x, y); // รวมฟองนม x และ y
        } else if (type == 'q') {
            if (ds.same(x, y)) {
                cout << "yes\n"; // ถ้าอยู่ก้อนเดียวกัน
            } else {
                cout << "no\n";  // ถ้าไม่อยู่ก้อนเดียวกัน
            }
        }
    }

    return 0;
}