#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int N, M, S, T;
vector<int> side;
vector<vector<int>> graph1, graph2; // กราฟแยกสำหรับฝั่ง 1 และ 2

// BFS หาระยะทางสั้นที่สุด
int bfs(int start, int end, vector<vector<int>>& graph) {
    if (start == end) return 0;
    vector<int> dist(N + 1, INF);
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : graph[u]) {
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist[end] == INF ? -1 : dist[end];
}

int main() {
    // รับ input
    cin >> N >> M >> S >> T;
    side.resize(N + 1);
    graph1.resize(N + 1);
    graph2.resize(N + 1);
    
    for (int i = 1; i <= N; i++) {
        cin >> side[i];
    }
    
    vector<pair<int, int>> edges(M);
    vector<pair<int, int>> bridges;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
        if (side[u] == side[v]) {
            if (side[u] == 1) {
                graph1[u].push_back(v);
                graph1[v].push_back(u);
            } else {
                graph2[u].push_back(v);
                graph2[v].push_back(u);
            }
        } else {
            if (side[u] == 1) {
                bridges.push_back({u, v});
            } else {
                bridges.push_back({v, u});
            }
        }
    }
    
    if (bridges.size() < 2) {
        cout << -1 << endl;
        return 0;
    }
    
    // คำนวณระยะทางจาก S ในฝั่ง 1
    vector<int> dist_from_S(N + 1, INF);
    queue<int> q;
    dist_from_S[S] = 0;
    q.push(S);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : graph1[u]) {
            if (dist_from_S[v] == INF) {
                dist_from_S[v] = dist_from_S[u] + 1;
                q.push(v);
            }
        }
    }
    
    // คำนวณระยะทางจาก T ในฝั่ง 2
    vector<int> dist_from_T(N + 1, INF);
    q = queue<int>();
    dist_from_T[T] = 0;
    q.push(T);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : graph2[u]) {
            if (dist_from_T[v] == INF) {
                dist_from_T[v] = dist_from_T[u] + 1;
                q.push(v);
            }
        }
    }
    
    int min_dist = INF;
    // ลองทุกคู่ของสะพาน
    for (int i = 0; i < bridges.size(); i++) {
        for (int j = 0; j < bridges.size(); j++) {
            if (i == j) continue;
            
            int u1 = bridges[i].first;  // ฝั่ง 1
            int v1 = bridges[i].second; // ฝั่ง 2
            int u2 = bridges[j].first;  // ฝั่ง 1
            int v2 = bridges[j].second; // ฝั่ง 2
            
            int d1 = dist_from_S[u1];  // S -> สะพานไป (ฝั่ง 1)
            int d2 = dist_from_T[v1];  // สะพานไป -> T (ฝั่ง 2)
            int d3 = dist_from_T[v2];  // T -> สะพานกลับ (ฝั่ง 2)
            int d4 = dist_from_S[u2];  // สะพานกลับ -> S (ฝั่ง 1)
            
            if (d1 == INF || d2 == INF || d3 == INF || d4 == INF) {
                continue;
            }
            
            int total = d1 + 1 + d2 + d3 + 1 + d4;
            min_dist = min(min_dist, total);
        }
    }
    
    cout << (min_dist == INF ? -1 : min_dist) << endl;
    return 0;
}