#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

struct UnionFind {
    vector<int> root, rank;
    UnionFind(int n) {
        root.resize(n+1);
        rank.resize(n+1, 0);
        for(int i = 1; i <= n; i++) {
            root[i] = i;
        }
    }

    int findSet(int u) {
        if(root[u] == u) return u;
        return root[u] = findSet(root[u]);
    }

    void unionSet(int u, int v) {
        u = findSet(u);
        v = findSet(v);
        if(u == v) return;
        if(rank[u] < rank[v]) {
            root[u] = v;
        } else if(rank[u] > rank[v]) {
            root[v] = u;
        } else {
            root[v] = u;
            rank[u]++;
        }
    }
};

int main(){
    int N, M;
    cin >> N >> M;
    UnionFind V(N);
    vector< tuple<int,int,int> > edges; //(cost, Start, End)
    for(int i = 0; i < M; i++){
        int Start, End, C, Status;
        cin >> Start >> End >> C >> Status;
        if(Status == 1) { // สร้างถนน no cost
            V.unionSet(Start, End);
        } else {
            edges.push_back({C, Start, End});
        }
    }
    sort(edges.begin(), edges.end(), [](auto &a, auto &b){
        return get<0>(a) < get<0>(b);}
    );

    long long Total = 0;
    for(auto &e : edges){
        int cost = get<0>(e);
        int Start = get<1>(e);
        int End = get<2>(e);
        if(V.findSet(Start) != V.findSet(End)){
            V.unionSet(Start, End);
            Total += cost;
        }
    }
    cout << Total << "\n";

    return 0;
}
