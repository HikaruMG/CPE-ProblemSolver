#include <iostream>
#include <vector>
using namespace std;

// ฟังก์ชัน DFS เพื่อสำรวจ Connected Component เดียว
void DFS(vector<vector<int>>& adj, int u, vector<bool>& visited) {
    visited[u] = true; // ทำเครื่องหมายว่าจุดยอดนี้ถูกเยี่ยมชมแล้ว
    
    // สำรวจจุดยอดที่อยู่ติดกัน
    for (int v : adj[u]) {
        if (!visited[v]) {
            DFS(adj, v, visited);
        }
    }
}

// ฟังก์ชันหาจำนวน Connected Components
int findConnectedComponents(vector<vector<int>>& adj, int V) {
    vector<bool> visited(V + 1, false); // visited array (เริ่มจาก index 1)
    int components = 0; // ตัวนับ Connected Components

    // วนลูปทุกจุดยอด
    for (int u = 1; u <= V; u++) {
        if (!visited[u]) { // ถ้าจุดยอดนี้ยังไม่ถูกเยี่ยมชม
            DFS(adj, u, visited); // เรียก DFS เพื่อสำรวจ Connected Component
            components++; // เพิ่มจำนวน Connected Components
        }
    }

    return components;
}

int main() {
    int V, E;
    
    // รับ input
    cin >> V >> E;

    // สร้าง Adjacency List
    vector<vector<int>> adj(V + 1); // เริ่ม index ที่ 1

    // รับเส้นเชื่อมและเพิ่มใน Adjacency List (กราฟไม่มุ่ง)
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // เพิ่มทั้ง u->v และ v->u เพราะกราฟไม่มุ่ง
    }

    // หาและแสดงจำนวน Connected Components
    int result = findConnectedComponents(adj, V);
    cout << result << endl;

    return 0;
}