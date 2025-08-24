#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    while (true) {
        int n, m;
        cin >> n >> m;
        
        if (n == 0 && m == 0) break;
        
        // กราฟแทนด้วยแอดจาเซนซีลิสต์
        vector<vector<int>> adj(n + 1);
        vector<int> inDegree(n + 1, 0);
        
        // อ่านข้อมูลความสัมพันธ์การทำงาน
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            inDegree[v]++;
        }
        
        // คิวสำหรับการประมวลผลงานที่ไม่มีข้อกำหนด
        queue<int> q;
        
        // เพิ่มงานที่มี In-degree เป็น 0 ลงในคิว
        for (int i = 1; i <= n; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        // ลำดับงานที่จัดเรียงแล้ว
        vector<int> topOrder;
        
        // ใช้ Kahn's Algorithm
        while (!q.empty()) {
            int task = q.front();
            q.pop();
            topOrder.push_back(task);
            
            // ลด In-degree ของงานที่ขึ้นอยู่กับงานปัจจุบัน
            for (int neighbor : adj[task]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        // พิมพ์ลำดับงานที่จัดเรียงแล้ว
        for (int i = 0; i < topOrder.size(); i++) {
            cout << topOrder[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
