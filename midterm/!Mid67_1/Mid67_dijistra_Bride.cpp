#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const long long INF = 1e18; // กำหนดค่าที่ใช้แทนอันนันต์

// โครงสร้างสำหรับเก็บข้อมูลของเส้นทางในกราฟ
struct Edge {
    int to, weight;
};

// ฟังก์ชัน Dijkstra เพื่อคำนวณระยะทางจากจุดเริ่มต้นในกราฟ
void dijkstra(int start, vector<long long> &dist, const vector<vector<Edge>> &graph) {
    int n = graph.size();
    // priority queue แบบ min-heap เพื่อเลือก node ที่มีระยะทางน้อยที่สุด
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        pair<long long, int> top = pq.top();
        pq.pop();
        long long d = top.first;  // ระยะทาง
        int u = top.second;       // node ปัจจุบัน
        
        // หากค่า d ไม่ตรงกับระยะทางที่คำนวณไว้ให้ข้ามไป
        if (d != dist[u]) continue;
        
        // อัปเดตระยะทางของเพื่อนบ้าน
        for (auto &edge : graph[u]) {
            int v = edge.to;
            long long nd = d + edge.weight;
            if (nd < dist[v]) {
                dist[v] = nd;
                pq.push({nd, v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, S, T;
    cin >> N >> M >> S >> T;
    vector<int> side(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> side[i];
    }
    
    // สร้างกราฟสำหรับฝั่ง 1 และฝั่ง 2 (เฉพาะถนนที่ไม่ใช่สะพาน)
    vector<vector<Edge>> graph1(N + 1), graph2(N + 1);
    // เก็บสะพานในรูปแบบ (u, v) โดย u อยู่ฝั่ง 1 และ v อยู่ฝั่ง 2
    vector<pair<int, int>> bridges;
    
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        // ถ้าแยกทั้งสองอยู่ในฝั่งเดียวกัน = ไม่ใช่สะพาน
        if (side[u] == side[v]) {
            if (side[u] == 1) {
                graph1[u].push_back({v, 1});
                graph1[v].push_back({u, 1});
            } else {
                graph2[u].push_back({v, 1});
                graph2[v].push_back({u, 1});
            }
        } else {
            // ถ้าเป็นสะพาน ให้จัดเก็บโดยให้ u อยู่ฝั่ง 1 และ v อยู่ฝั่ง 2
            if (side[u] == 1) {
                bridges.push_back({u, v});
            } else {
                bridges.push_back({v, u});
            }
        }
    }
    
    // คำนวณระยะทางในฝั่ง 1 จาก S
    vector<long long> dist1(N + 1, INF);
    dijkstra(S, dist1, graph1);
    
    // คำนวณระยะทางในฝั่ง 2 จาก T
    vector<long long> dist2(N + 1, INF);
    dijkstra(T, dist2, graph2);
    
    // เก็บ candidate cost สำหรับแต่ละสะพาน ที่สามารถเดินทางได้จริง
    vector<long long> candidates;
    for (auto &b : bridges) {
        int u = b.first;  // จุดบนฝั่ง 1
        int v = b.second; // จุดบนฝั่ง 2
        if (dist1[u] < INF && dist2[v] < INF) {
            candidates.push_back(dist1[u] + dist2[v]);
        }
    }
    
    // หากมี candidate น้อยกว่า 2 แสดงว่าไม่สามารถเลือกสะพานสองเส้นที่แตกต่างกันได้
    if (candidates.size() < 2) {
        cout << -1;
        return 0;
    }
    
    // เลือก candidate สองค่าที่น้อยที่สุด
    sort(candidates.begin(), candidates.end());
    // ผลรวมทั้งหมด = candidate[0] + candidate[1] + 2 (เพิ่ม 2 สำหรับการข้ามสะพาน 2 เส้น)
    long long ans = candidates[0] + candidates[1] + 2;
    cout << ans;
    
    return 0;
}