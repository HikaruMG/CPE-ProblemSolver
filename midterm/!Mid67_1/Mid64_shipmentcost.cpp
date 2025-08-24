#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9; // ค่า infinity

// ฟังก์ชัน BFS หาระยะทางจากจุดเริ่มต้นไปยังทุกจุด
vector<int> bfs(int start, int n, vector<vector<int>>& adj) {
    vector<int> dist(n + 1, INF); // เก็บระยะทาง
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : adj[u]) {
            if (dist[v] == INF) { // ยังไม่เคยไป
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}

int main() {
    // รับข้อมูลนำเข้า
    int n, m, s, t;
    scanf("%d %d %d %d", &n, &m, &s, &t);
    
    // สร้างกราฟแบบ adjacency list
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a); // กราฟสองทิศทาง
    }
    
    // รับตำแหน่งคลังสินค้า
    vector<int> storage(s);
    for (int i = 0; i < s; i++) {
        scanf("%d", &storage[i]);
    }
    
    // รับตำแหน่งโรงงาน
    vector<int> factory(t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &factory[i]);
    }
    
    // เก็บระยะทางสั้นที่สุดไปยังโรงงานแต่ละแห่ง
    vector<int> ans(t, INF);
    
    // กรณี S <= 5: รัน BFS จากคลังสินค้า
    if (s <= 5) {
        vector<vector<int>> dist_from_storage(s); // เก็บระยะทางจากคลังสินค้าแต่ละแห่ง
        for (int i = 0; i < s; i++) {
            dist_from_storage[i] = bfs(storage[i], n, adj);
        }
        
        // หาระยะทางสั้นที่สุดสำหรับโรงงานแต่ละแห่ง
        for (int j = 0; j < t; j++) {
            for (int i = 0; i < s; i++) {
                ans[j] = min(ans[j], dist_from_storage[i][factory[j]]);
            }
        }
    }
    // กรณี T <= 5: รัน BFS จากโรงงาน
    else if (t <= 5) {
        vector<vector<int>> dist_from_factory(t); // เก็บระยะทางจากโรงงานแต่ละแห่ง
        for (int i = 0; i < t; i++) {
            dist_from_factory[i] = bfs(factory[i], n, adj);
        }
        
        // หาระยะทางสั้นที่สุดจากคลังสินค้าไปโรงงาน
        for (int j = 0; j < t; j++) {
            for (int i = 0; i < s; i++) {
                ans[j] = min(ans[j], dist_from_factory[j][storage[i]]);
            }
        }
    }
    
    // แสดงผลลัพธ์
    for (int i = 0; i < t; i++) {
        printf("%d\n", ans[i]);
    }
    
    return 0;
}