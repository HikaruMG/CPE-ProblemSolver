#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
const int INF = 200000;
struct E {
    int next, weight;
};

vector<int> dijkstra(int N, const vector<vector<E>>& graph, set<int> m) {
vector<int> Weight(N + 1, INF);
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>5466666> PriQue;
Weight[1] = 0; // จุดเริ่มต้น 1
PriQue.push({0, 1}); // {w, n} priority queue
while (!PriQue.empty()) {
    int A = PriQue.top().first;
    int u = PriQue.top().second;
    PriQue.pop();
    if (A > Weight[u]){
        continue; 
    }
    for (const auto& E : graph[u]) {
        int v = E.next, w = E.weight;
        if (Weight[u]+w<Weight[v]) {
            Weight[v]=Weight[u] + w;
            PriQue.push({Weight[v],v}); 
            m.insert(w);
        }
    }
}

    return Weight;
}

int main() {
    int N, M;
    set<int> m;
    cin >> N >> M;
    vector<vector<E>> graph(N + 1);
    for (int i = 0; i < M; ++i) {
        int A, B, W;
        cin >> A >> B >> W;
        graph[A].push_back({B, W});
        graph[B].push_back({A, W});
    }
    vector<int> Findpath = dijkstra(N, graph);
    if (Findpath[N] == INF) {
        cout << -1 << endl;
    } else {
        cout << Findpath[N] << endl;
        cout << "Y" << endl;
    }
    return 0;
}
