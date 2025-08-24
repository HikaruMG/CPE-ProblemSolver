#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, stack<int>& s) {
    visited[node] = true; // ทำเครื่องหมายว่าเยี่ยมแล้ว
    
    // เยี่ยมโหนดที่เชื่อมต่อทั้งหมด
    for(int next : graph[node]) {
        if(!visited[next]) {
            dfs(next, graph, visited, s);
        }
    }
    
    // หลังจากสำรวจโหนดที่เชื่อมต่อหมดแล้ว ใส่โหนดปัจจุบันใน stack
    s.push(node);
}

void topologicalSortDFS(int n, vector<vector<int>>& graph) {
    vector<bool> visited(n + 1, false); // เก็บสถานะการเยี่ยม
    stack<int> s; // ใช้ stack เพื่อเก็บลำดับ
    
    // เรียก DFS สำหรับทุกโหนดที่ยังไม่เยี่ยม
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            dfs(i, graph, visited, s);
        }
    }
    
    // พิมพ์ผลลัพธ์จาก stack
    while(!s.empty()) {
        cout << s.top();
        s.pop();
        if(!s.empty()) cout << " ";
    }
    cout << endl;
}

int main() {
    int n, m;
    while(true) {
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        
        vector<vector<int>> graph(n + 1);
        for(int i = 0; i < m; i++) {
            int i_task, j_task;
            cin >> i_task >> j_task;
            graph[i_task].push_back(j_task);
        }
        
        topologicalSortDFS(n, graph);
    }
    return 0;
}