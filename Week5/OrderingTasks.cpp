#include <bits/stdc++.h>
using namespace std;

void T(vector<vector<int>> graph, vector<int> indg , int n){
    queue<int> q;
    vector<int> ans;
    for(int i = 1; i<=n; i++){
        if(indg[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(int temp : graph[node]){
            indg[temp]--;
            if(indg[temp]==0){
                q.push(temp);
            }
        }
    }
    for(int j = 0;j<ans.size();j++){
        cout << ans[j] << " ";
        // if (j<ans.size()-1){
        //     cout << " ";
        // } 
    }
    cout << endl;
}

int main(){
    int n,m;
    while(1){
        cin >> n >> m;
        if(m==0 and n==0){
            break;
        }
        vector<vector<int>> graph(n+1);
        vector<int> Indg(n+1,0);
        for(int j = 0;j<m;j++){
            int u,v;
            cin >> u >> v;
            graph[u].push_back(v);
            Indg[v]++;
        }
        T(graph,Indg,n);
    }
    return 0;
}