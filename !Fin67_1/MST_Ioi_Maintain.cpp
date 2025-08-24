#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct road{
    int u, v, len;
    bool operator<(const road &other) const {
        return len < other.len;
        //มีตัวดำเนินการ < สำหรับใช้ในการเรียงลำดับจากน้ำหนักน้อยไปมาก (ใช้ใน Kruskal’s Algorithm)
    }
};

vector<int> railroad;

int find(int a){
    if(railroad[a] != a){
        //ไล่หา root ขึ้นไป จนสุด
        railroad[a] = find(railroad[a]);
    }
    return railroad[a];
} 

void unite(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    if (rootA != rootB) {
        railroad[rootB] = rootA; //รวมเซต b เข้าไปที่เซต a
    }
}

int kruskalMST(int n, vector<road> &edges) {
    sort(edges.begin(), edges.end()); // เรียงตาม len
    int mstWeight = 0, edgesUsed = 0;
    for (auto &edge : edges) {
        if (find(edge.u) != find(edge.v)) {
            unite(edge.u, edge.v);
            mstWeight += edge.len;
            edgesUsed++;
            if (edgesUsed == n - 1) break; // ได้ MST แล้ว
        }
    }
    return (edgesUsed == n - 1) ? mstWeight : -1;
    //ใช้ตรวจสอบว่า MST เชื่อมครบทุกจุดหรือไม่
    //ถ้า เชื่อมครบ (edgesUsed == N-1) → คืนค่า mstWeight
    //ถ้า ยังไม่ครบ → คืนค่า -1
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,W;
    cin >> N >> W;

    railroad.resize(N + 1);
    // 1,2,3,4,...
    vector<road> edges;

    for (int i = 1; i <= N; i++) {
        railroad[i] = i; //rootเริ่มต้นให้แต่ละ node
        // 1,2,3,...
    }
    
    for(int i=0; i<W; i++){
        int u,v,len;
        cin >> u >> v >> len;
        edges.push_back({u, v, len});
        cout << kruskalMST(N, edges) << '\n';
        //เริ่มจับเซตใหม่
        for (int i = 1; i <= N; i++) {
            railroad[i] = i;
        }
    }
    return 0;
}