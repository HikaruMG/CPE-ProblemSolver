#include <bits/stdc++.h>
using namespace std;

struct play{
    int x,y;
    play(int x_,int y_) : x(x_),y(y_) {}
};

bool CheckBI(vector<vector<int>> adj, vector<play> E,int n,int nextE){
    queue<int> q;
    vector<int> TwoColor(n+1,-1);
    TwoColor[1]=0;
    q.push(1);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        
        for(int temp : adj[node]){
            if (nextE != -1 and ((node == E[nextE].x and temp == E[nextE].y or \
                                node == E[nextE].y and temp == E[nextE].x))){
                                    continue;
                                }
            if(TwoColor[temp]==-1){
                TwoColor[temp] = 1-TwoColor[node];
                q.push(temp);
            }
            else if(TwoColor[temp]==TwoColor[node]){
                return false;
            }
        }
    }
    for(int j = 1; j<=n;j++){
        if (TwoColor[j]==-1){
            TwoColor[j]=0;
            q.push(j);
            while (!q.empty()){
                int node = q.front();
                q.pop();
        
                for(int temp : adj[node]){
                    if (nextE != -1 and ((node == E[nextE].x and temp == E[nextE].y or \
                                        node == E[nextE].y and temp == E[nextE].x))){
                                            continue;
                                }
                    if(TwoColor[temp]==-1){
                        TwoColor[temp] = 1-TwoColor[node];
                        q.push(temp);
                    }
                    else if(TwoColor[temp]==TwoColor[node]){
                        return false;
                    }
                }
            }
        }
    }
    return true;  
}

int main(){
    int n,m;
    cin >> n >>m;
    
    vector<vector<int>> adj(n+1);
    vector<play> E;

    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        E.push_back(play(u,v));
        adj[u].push_back(v);
        adj[v].push_back(u);

    }
    for(int i = 0;i<m;i++){
        if(CheckBI(adj,E,n,i)){
            cout << E[i].x << " " << E[i].y << endl;
        }
    }
    

}