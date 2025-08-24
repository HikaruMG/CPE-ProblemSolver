#include <iostream>
#include <vector>
using namespace std;
void DepthFirstSearch(int v, vector<vector<int>>&Conectedge, vector<bool>&exploded) {
    exploded[v] = true;
    for (int u : Conectedge[v]) {
        if (!exploded[u]) {
            DepthFirstSearch(u,Conectedge,exploded);
        }
    }
}
int main() {
    int n,m,c=0;
    cin >> n >> m;
    vector<vector<int>> Conectedge(n + 1);
    
    vector<bool> exploded(n + 1, false);
    for (int i = 0; i < m; ++i) {
        int U, V;
        cin >> U >> V;
        Conectedge[U].push_back(V);
        Conectedge[V].push_back(U);
    }
    for (int i=1; i<=n; ++i) {
        if(!exploded[i]) {
            DepthFirstSearch(i, Conectedge, exploded);
            ++c;
        }
    }
    cout << c << endl;
    return 0;
}