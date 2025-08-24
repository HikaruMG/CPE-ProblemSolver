#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> Parent;
struct EdgeRouth{
    int u, v, size;
    bool operator<(const EdgeRouth &other) const {
        return size < other.size; // low to high
    }
};

int find(int a){
    if(Parent[a] != a){
        Parent[a] = find(Parent[a]);
    }
    return Parent[a];
} 


void unionSet(int a, int b) {
    int parentA = find(a);
    int parentB = find(b);
    if (parentA != parentB) {
        Parent[parentB] = parentA;
    }
}
int kruskalTree(int n, vector<EdgeRouth> &e) {
    int w = 0, pathCount = 0;
    sort(e.begin(), e.end());
    for (auto &edge : e) {
        if (find(edge.u) != find(edge.v)) {
            unionSet(edge.u, edge.v);
            w += edge.size;
            pathCount++;

            if (pathCount == n - 1){
                break;
            } 
        }
    }
    return (pathCount == n - 1) ? w : -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<EdgeRouth> e;
    int N,W;
    cin >> N >> W;
    Parent.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        Parent[i] = i;
    }
    
    for(int i=0; i<W; i++){
        int u,v,len;
        cin >> u >> v >> len;
        e.push_back({u, v, len});
        cout << kruskalTree(N, e) << '\n';

        for (int i = 1; i <= N; i++) {
            Parent[i] = i;
        }
    }
    return 0;
}