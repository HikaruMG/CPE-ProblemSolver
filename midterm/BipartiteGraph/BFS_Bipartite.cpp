#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ฟังก์ชันตรวจสอบว่าเป็น Bipartite Graph หรือไม่
bool isBipartite(vector<vector<int>>& graph, int V) {
    // สร้าง array สำหรับเก็บสี (-1 = ยังไม่ระบาย, 0 = สีแรก, 1 = สีที่สอง)
    vector<int> colors(V, -1);
    
    // ใช้ BFS เริ่มจากจุดยอดแรก (vertex 0)
    queue<int> q;
    q.push(0);
    colors[0] = 0; // ระบายสีจุดยอดแรกเป็นสี 0
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        // ตรวจสอบจุดยอดที่อยู่ติดกัน
        for (int v : graph[u]) {
            // ถ้าจุดยอด v ยังไม่ระบายสี
            if (colors[v] == -1) {
                // ระบายสีตรงข้ามกับจุดยอด u
                colors[v] = 1 - colors[u];
                q.push(v);
            }
            // ถ้าจุดยอด v ระบายสีแล้ว และสีเดียวกับ u
            else if (colors[v] == colors[u]) {
                return false; // ไม่ใช่ Bipartite Graph
            }
        }
    }
    
    // ตรวจสอบจุดยอดที่อาจไม่ถูกเชื่อมต่อ (กรณีกราฟมีหลาย component)
    for (int i = 0; i < V; i++) {
        if (colors[i] == -1) {
            q.push(i);
            colors[i] = 0;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : graph[u]) {
                    if (colors[v] == -1) {
                        colors[v] = 1 - colors[u];
                        q.push(v);
                    }
                    else if (colors[v] == colors[u]) {
                        return false;
                    }
                }
            }
        }
    }
    
    return true; // เป็น Bipartite Graph
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;
    
    // สร้าง adjacency list
    vector<vector<int>> graph(V);
    cout << "Enter " << E << " edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // เพราะเป็น undirected graph
    }
    
    // ตรวจสอบว่าเป็น Bipartite Graph หรือไม่
    if (isBipartite(graph, V)) {
        cout << "Yes, this is a Bipartite Graph.\n";
    } else {
        cout << "No, this is not a Bipartite Graph.\n";
    }
    
    return 0;
}