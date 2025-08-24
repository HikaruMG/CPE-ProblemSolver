#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
struct Road {
    int connect;
    long long cost;
    int status;
};

struct state {
    long long dist;
    int vertex;
    int remain;
    bool operator>(const state& other) const {
        return dist > other.dist; // เรียงจากน้อยไปมาก
    }
};

int main(){
    int N,M,Ai,Bi,Ci,Si;
    cin >> N >> M;
    vector<vector<Road>> graph(N+1);
    for (int a = 0; a < M; ++a) {
        cin >> Ai >> Bi >> Ci >> Si;
        graph[Ai].push_back({Bi,Ci,Si});
    }
    vector<vector<long long>> dist(N+1, vector<long long>(2,INF));
    priority_queue<state, vector<state>,greater<>> pq;
    dist[1][1] = 0;
    pq.push({0,1,1});

    while (!pq.empty()) {
        state cur = pq.top();
        pq.pop();

        long long d = cur.dist;
        int u = cur.vertex;
        int s = cur.remain;
        if (d > dist[u][s]) continue;
        for (auto i : graph[u]) {
            int v = i.connect;
            long long Ncost = d + i.cost;
            int new_status = s;
            if (i.status) {
                if (s==0) continue;
                new_status = 0;
            }
            if (Ncost < dist[v][new_status]) {
                dist[v][new_status] = Ncost;
                pq.push({Ncost,v,new_status});
            }
        }
    }
    long long ans = min(dist[N][0],dist[N][1]);
    if (ans == INF) {
        cout << "-1" << endl;
    }
    else {
        cout << ans << endl;
    }
    return 0;
}