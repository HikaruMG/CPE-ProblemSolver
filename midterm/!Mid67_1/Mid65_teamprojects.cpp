#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;
    
    // เก็บจำนวนคู่ (degree) ของแต่ละนักเรียน
    vector<int> degree(N + 1, 0);
    // เก็บรายการคู่ทั้งหมด (เพื่อที่จะนำไปพิจารณาเฉพาะ constrained)
    vector<pair<int, int>> pairs;
    
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        degree[a]++;
        degree[b]++;
        pairs.push_back({a, b});
    }
    
    // สร้างกราฟเฉพาะสำหรับ constrained: นักเรียนที่ degree < K
    vector<vector<int>> graph(N + 1);
    for(auto &p : pairs){
        int a = p.first, b = p.second;
        // เพิ่ม edge เฉพาะเมื่อทั้ง a และ b เป็น constrained
        if(degree[a] < K && degree[b] < K){
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
    }
    
    // array สำหรับเก็บสีของแต่ละ vertex (-1 หมายถึงยังไม่ระบุสี)
    vector<int> color(N + 1, -1);
    
    // ฟังก์ชันตรวจสอบความเป็น bipartite สำหรับ component ที่มี vertex u เป็นจุดเริ่มต้น
    auto bfs = [&](int start) -> bool {
        queue<int> q;
        color[start] = 0;
        q.push(start);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v : graph[u]){
                // ถ้ายังไม่ได้กำหนดสี
                if(color[v] == -1){
                    color[v] = 1 - color[u];
                    q.push(v);
                } else if(color[v] == color[u]){
                    // พบว่ามี edge ที่เชื่อม vertex ที่มีสีเดียวกัน
                    return false;
                }
            }
        }
        return true;
    };
    
    // ตรวจสอบทุก vertex ที่เป็น constrained
    for(int i = 1; i <= N; i++){
        if(degree[i] < K && color[i] == -1){
            if(!bfs(i)){
                cout << "no";
                return 0;
            }
        }
    }
    
    cout << "yes";
    return 0;
}
