#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ฟังก์ชัน BFS
void BFS(vector<vector<int>>& adj, int V, int start) {
    vector<bool> visited(V + 1, false); // visited array เริ่มจาก index 1
    queue<int> q; // คิวสำหรับ BFS

    visited[start] = true; // ทำเครื่องหมายว่าเยี่ยมชมแล้ว
    q.push(start); // เพิ่มจุดเริ่มต้นลงคิว

    cout << "BFS Traversal: ";
    while (!q.empty()) {
        int u = q.front(); // นำจุดยอดออกจากคิว
        q.pop();
        cout << u << " "; // แสดงจุดยอดที่เยี่ยมชม

        // สำรวจจุดยอดที่อยู่ติดกัน
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << endl;
}

// int main() {
//     int V = 5; // จำนวนจุดยอด
//     int E = 4; // จำนวนเส้นเชื่อม

//     // สร้าง Adjacency List
//     vector<vector<int>> adj(V + 1);

//     // เพิ่มเส้นเชื่อม (กราฟไม่มุ่ง)
//     int edges[4][2] = {{1, 2}, {2, 3}, {1, 3}, {3, 4}};
//     for (int i = 0; i < E; i++) {
//         int u = edges[i][0];
//         int v = edges[i][1];
//         adj[u].push_back(v);
//         adj[v].push_back(u); // กราฟไม่มุ่ง
//     }

//     // รัน BFS
//     BFS(adj, V, 1);

//     return 0;
// }

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj(V + 1);
    cout << "Enter " << E << " edges (u v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // กราฟไม่มุ่ง
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    BFS(adj, V, start);
    return 0;
}