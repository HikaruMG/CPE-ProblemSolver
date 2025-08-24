#include <iostream>
#include <vector>
using namespace std;

// ฟังก์ชัน DFS เพื่อระบายสีและตรวจสอบ Bipartite
bool dfs(vector<vector<int>>& graph, vector<int>& colors, int u, int color) {
    colors[u] = color; // ระบายสีให้จุดยอด u
    
    // เยี่ยมเยือนจุดยอดที่อยู่ติดกัน
    for (int v : graph[u]) {
        // ถ้าจุดยอด v ยังไม่ระบายสี
        if (colors[v] == -1) {
            // เรียก DFS โดยระบายสีตรงข้าม (1 - color)
            if (!dfs(graph, colors, v, 1 - color)) {
                return false;
            }
        }
        // ถ้าจุดยอด v ระบายสีแล้ว และสีเดียวกับ u
        else if (colors[v] == colors[u]) {
            return false; // ไม่ใช่ Bipartite Graph
        }
    }
    return true;
}

// ฟังก์ชันหลักเพื่อตรวจสอบ Bipartite Graph
bool isBipartite(vector<vector<int>>& graph, int V) {
    // สร้าง array สำหรับเก็บสี (-1 = ยังไม่ระบาย, 0 = สีแรก, 1 = สีที่สอง)
    vector<int> colors(V, -1);
    
    // ตรวจสอบทุกจุดยอด (กรณีกราฟมีหลาย component)
    for (int i = 0; i < V; i++) {
        if (colors[i] == -1) {
            // เริ่ม DFS จากจุดยอดที่ยังไม่ระบายสี โดยใช้สี 0
            if (!dfs(graph, colors, i, 0)) {
                return false;
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