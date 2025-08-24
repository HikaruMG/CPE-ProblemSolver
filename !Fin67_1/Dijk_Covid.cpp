#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <tuple> 

using namespace std;

struct Edge {
    int next, price;
};

vector<vector<Edge>> adj;
vector<int> people;

vector<long long> dijkstra(int start, int n) {
    vector<long long> dist(n + 1, LLONG_MAX);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    dist[start] = 0;
    pq.emplace(0, start);
    while (!pq.empty()) {
        long long d;
        int u;
        tie(d, u) = pq.top();
        pq.pop();
        if (d != dist[u]) continue;
        for (auto &edge : adj[u]) {
            int v = edge.next;
            long long cost = edge.price;
            if (dist[u]+cost<dist[v]) {
                dist[v]=dist[u]+cost;
                pq.emplace(dist[v], v);
            }
        }
    }
    return dist;
}

int main() {
    int N, M, L;
    cin >> N >> M >> L;
    people.resize(N + 1);
    adj.resize(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> people[i];
    }

    for (int i = 0; i < M; ++i) {
        int A, B, C;
        cin >> A >> B >> C;
        adj[A].push_back({B, C});
        adj[B].push_back({A, C});
    }
    vector<long long> lengthHospital = dijkstra(1, N);
    long long totalCost = 0;
    for (int i = 2; i <= N; ++i) {
        long long walk = people[i]*lengthHospital[i];
        long long car = L*lengthHospital[i];
        totalCost += min(walk, car);
    }

    cout << totalCost << endl;
    return 0;
}
