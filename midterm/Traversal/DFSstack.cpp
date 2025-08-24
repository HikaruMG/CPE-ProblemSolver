#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// ฟังก์ชัน DFS ด้วย Stack
void DFS(vector<vector<int>>& adj, int V, int start) {
    vector<bool> visited(V + 1, false); // visited array เริ่มจาก index 1
    stack<int> s; // สแตกสำหรับ DFS

    s.push(start); // เพิ่มจุดเริ่มต้นลง stack

    cout << "DFS Traversal: ";
    while (!s.empty()) {
        int u = s.top(); // ดูจุดยอดที่อยู่บนสุดของ stack
        s.pop(); // นำออกจาก stack

        // ถ้ายังไม่ถูกเยี่ยมชม
        if (!visited[u]) {
            visited[u] = true; // ทำเครื่องหมายว่าเยี่ยมชม
            cout << u << " ";  // แสดงจุดยอด

            // เพิ่มจุดยอดที่อยู่ติดกันลง stack (ตามลำดับย้อนกลับเพื่อให้เหมือน recursive DFS)
            for (int i = adj[u].size() - 1; i >= 0; i--) {
                int v = adj[u][i];
                if (!visited[v]) {
                    s.push(v);
                }
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

//     // รัน DFS
//     DFS(adj, V, 1);

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

    DFS(adj, V, start);
    return 0;
}