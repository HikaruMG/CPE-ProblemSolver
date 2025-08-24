#include <bits/stdc++.h>
using namespace std;

struct edge {
    int to; //ปลายทาง
    bool needMagic; //ถนนใช้เวทไหม
};

struct state {
    int current; // Verter ที่อยู่่
    int Health; // เลือดที่เหลือ
    bool hasM; // ผ่าน รร.เวทยัง
};

int main(){
    int N,M,K,H;
    cin >> N >> M >> K >> H;
    unordered_set<int> VertexSchool; //เก็บข้อมูล Vertex ที่เป็น รร.
    for (int a = 0; a < K; ++a) {
        int temp;
        cin >> temp;
        VertexSchool.insert(temp);
    }
    vector<vector<edge>> graph(N+1);
    for (int a = 0; a < M; ++a) {
        int A,B,C;
        cin >> A >> B >> C;
        graph[A].push_back({B,C == 1});
        graph[B].push_back({A,C == 1});
    }

    queue<state> q;
    unordered_map<int, unordered_map<int, bool>> visited[N + 1]; // [ [["False", "False"], ["False", "False"]] ]
    bool start = VertexSchool.count(1) > 0;
    q.push({1,H,start});
    visited[1][H][start] = true;

    unordered_set<int> CanTravel;
    CanTravel.insert(1);

    while (!q.empty()) {
        state Cur = q.front();
        q.pop();

        for (auto& i : graph[Cur.current]) {
            // if (Cur.Health > 0 and (!i.needMagic or Cur.hasM)) {
            //     // if (!i.needMagic or (i.needMagic and Cur.hasM)) {
            //         int nextV = i.to;
            //         int nextHealth = Cur.Health-1;
            //         bool nextM = Cur.hasM || VertexSchool.count(nextV) > 0;
            //         if (!visited[nextV][nextHealth][nextM]) {
            //             visited[nextV][nextHealth][nextM] = true;
            //             q.push({nextV,nextHealth,nextM});
            //             CanTravel.insert(nextV);
                    // }
                // }
            int nextV = i.to;
            int nextH = Cur.Health - 1;
            bool nextM = Cur.hasM || VertexSchool.count(nextV);
            bool roadType = i.needMagic;
            if (nextH >= 0 && (!roadType || Cur.hasM)){
                if (!visited[nextV][nextH][nextM]) {
                    visited[nextV][nextH][nextM] = true;
                    q.push({nextV,nextH,nextM});
                    CanTravel.insert(nextV);
                }
            }
        }
    }
    cout << CanTravel.size() << endl;
    return 0;
 }