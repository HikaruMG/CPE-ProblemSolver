#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfsShortestPath(vector<vector<int>>& adj, int V, int src) {
    vector<int> dist(V + 1, -1); // ระยะทาง (-1 หมายถึงยังไม่ถึง)
    queue<int> q;

    dist[src] = 0; // ระยะทางจาก source ถึงตัวมันเองเป็น 0
    q.push(src);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // สำรวจจุดยอดที่อยู่ติดกัน
        for (int v : adj[u]) {
            if (dist[v] == -1) { // ถ้ายังไม่ถูกเยี่ยมชม
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    return dist;
}

int main() {
    int V = 5; // จำนวนจุดยอด
    int E = 6; // จำนวนเส้นเชื่อม

    // Adjacency List
    vector<vector<int>> adj(V + 1);

    // เพิ่มเส้นเชื่อม (กราฟไม่มุ่ง, ไม่มีน้ำหนัก)
    vector<pair<int, int>> edges = {
        {1, 2}, {1, 3}, {2, 4}, {3, 4}, {3, 5}, {4, 5}
    };

    for (auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // หาเส้นทางที่สั้นที่สุดจากจุด 1
    int src = 1;
    vector<int> dist = bfsShortestPath(adj, V, src);

    // พิมพ์ระยะทาง
    cout << "Shortest distances from vertex " << src << ":\n";
    for (int i = 1; i <= V; i++) {
        if (dist[i] == -1) {
            cout << "Vertex " << i << ": Unreachable" << endl;
        } else {
            cout << "Vertex " << i << ": " << dist[i] << endl;
        }
    }

    return 0;
} 