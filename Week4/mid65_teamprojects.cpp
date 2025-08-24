#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
vector<int> adj[MAXN]; 
vector<int> color;    
vector<int> dgr; 
vector<bool> visited;

int N, M, K;

bool dfs(int u, int c, vector<bool>& visited) {
    color[u] = c;  
    visited[u] = true;
    
    for(int v : adj[u]) {
        if(!visited[v]) {
            if(!dfs(v, c^1, visited)) return false;  
        }
        else if(color[v] == color[u] && dgr[u] < K && dgr[v] < K) {
            return false;
        }
    }
    return true;
}

bool CheckBipa() {
    color.assign(N+1, -1);  
    visited.resize(N+1, false);
    
    for(int i = 1; i <= N; i++) {
        if(!visited[i]) {
            if(!dfs(i, 0, visited)) return false;
        }
    }
    return true;
}

int main() {
    cin >> N >> M >> K;
    dgr.assign(N+1, 0);
    
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);  
        dgr[a]++;
        dgr[b]++;
    }
    if(CheckBipa()) cout << "yes\n";
    else cout << "no\n";
    return 0;
}