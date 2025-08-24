#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, pair<int, int>> Vertex; // {ระยะทาง, {เมือง, prioritys}}
const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int C, V;
    while (cin >> C >> V) { 
        vector<vector<ll>> Route(C+1, vector<ll>(2, INF));
        vector<vector<pair<int, ll>>> adj(C + 1); //adj[เมือง] = {{เมืองปลายทาง, ค่าผ่านทาง}, ...}
        priority_queue<Vertex, vector<Vertex>, greater<Vertex>> pq;
        for (int i = 0; i < V; i++) {
            int u, v, W;
            cin >> u >> v >> W;
            adj[u].push_back({v, W});
            adj[v].push_back({u, W}); 
        }
        Route[1][0] = 0; // ระยะทาง 0, prioritys คู่
        pq.push({0, {1, 0}});

        while (!pq.empty()) {
            ll d = pq.top().first;            // ระยะทางสะสม
            int u = pq.top().second.first;    // เมืองปัจจุบัน
            int prioritys = pq.top().second.second; // prioritys ปัจจุบัน
            pq.pop();

            if (d > Route[u][prioritys]) {
                continue; // ถ้าระยะทางเก่ากว่า ข้ามไป
            }
            for (auto i : adj[u]) { // สำรวจเมืองที่เชื่อมต่อ
                ll v = i.first;      // เมืองปลายทาง
                ll w = i.second;      // ค่าผ่านทาง
                int temp_prioritys = 1-prioritys; // สลับ prioritys (คู่ -> คี่, คี่ -> คู่)
                ll temp_Route = d+w;         // ระยะทางใหม่

                if (temp_Route<Route[v][temp_prioritys]) {

                    Route[v][temp_prioritys] = temp_Route;

                    pq.push({temp_Route, {v,temp_prioritys}});
                }
            }
        }
        if (Route[C][0] == INF) cout << -1 << "\n";
        else cout << Route[C][0] << "\n";
    }

    return 0;
}