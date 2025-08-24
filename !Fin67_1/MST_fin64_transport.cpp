#include <bits/stdc++.h>
using namespace std;
struct edge {
    int u,v;
    double w;
    bool operator<(const edge& other) const {
        return w < other.w;
    }
};
vector<int> parent, ranks;
void INIT_UF(int n) {
    parent.resize(n);
    ranks.resize(n,0);
    for (int a = 0; a < n; ++a) {
        parent[a] = a;
    }
}

int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

bool unions (int u, int v) {
    int pu = find(u), pv = find(v);
    if (pu == pv) {
        return false;
    }
    if (ranks[pu] < ranks[pv]) {
        swap(pu, pv);
    }
    parent[pv] = pu;
    if (ranks[pu] == ranks[pv]) {
        ranks[pu]++;
    }
    return true;
}

double EUD_dist(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main(){
    int N;
    cin >> N;
    vector<pair<int,int>> Posit(N);
    for (int a = 0; a < N; ++a) {
        cin >> Posit[a].first >> Posit[a].second;
    }
    vector<edge> E;
    for (int a = 0; a < N; ++a) {
        for (int b = a+1; b<N; ++b) {
            double d = EUD_dist(Posit[a].first,Posit[a].second,Posit[b].first,Posit[b].second);
            E.push_back({a,b,d});
        }
    }
    sort(E.begin(),E.end());
    INIT_UF(N);

    vector<edge> mst;
    for (auto& e : E) {
        if (mst.size() == N -2) {
            break;
        }
        if (unions(e.u,e.v)) {
            mst.push_back(e);
        }
    }
    double totalC = 0.0;
    for (auto&e : mst) {
        totalC += e.w;
    }
    printf("%.4f\n", totalC);
    return 0;
}