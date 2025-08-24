#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void topologicalSortKahn(int n, vector<vector<int>>& graph, vector<int>& inDegree) {
    vector<int> result;
    queue<int> q;
    
    // หาโหนดที่มี in-degree = 0
    for(int i = 1; i <= n; i++) {
        if(inDegree[i] == 0) {
            q.push(i);
        }
    }
    
    // ประมวลผลด้วย Queue
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        result.push_back(curr);
        
        // ลบขอบและอัพเดท in-degree
        for(int next : graph[curr]) {
            inDegree[next]--;
            if(inDegree[next] == 0) {
                q.push(next);
            }
        }
    }
    
    // พิมพ์ผลลัพธ์
    for(int i = 0; i < result.size(); i++) {
        cout << result[i];
        if(i < result.size() - 1) cout << " ";
    }
    cout << endl;
}

int main() {
    int n, m;
    while(true) {
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        
        vector<vector<int>> graph(n + 1);
        vector<int> inDegree(n + 1, 0);
        
        for(int i = 0; i < m; i++) {
            int i_task, j_task;
            cin >> i_task >> j_task;
            graph[i_task].push_back(j_task);
            inDegree[j_task]++;
        }
        
        topologicalSortKahn(n, graph, inDegree);
    }
    return 0;
}