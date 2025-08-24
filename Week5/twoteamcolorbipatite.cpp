#include <bits/stdc++.h>
using namespace std;
const int max_N = 100010;
int a,b,n,m;
vector<int> adj[max_N];
vector<int> TwoColor;
bool CheckBi(vector<pair<int,int>> node,int s){
    for(int i = 1 ; i <=n ;i++){
        adj[i].clear();
    }
    for (int j = 0 ; j <= s ; j++){
        int x = node[j].first;
        int y = node[j].second;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    queue<int> q;
    TwoColor.assign(n+1,-1);
    for(int i = 1;i<=n;i++){
        if(TwoColor[i] != -1){
            continue;
        }
        TwoColor[i] = 0;
        q.push(i);
        while (!q.empty())
        {
            int nodeU = q.front();
            q.pop();
            for (int temp : adj[nodeU]){
                if(TwoColor[temp] == -1){
                    TwoColor[temp] = 1-TwoColor[nodeU];
                    q.push(temp);
                }
                else if(TwoColor[temp] == TwoColor[nodeU]){
                    return false;
                }
            }
        }  
    }
    return true;
}

int main(){
    
    cin >> n >> m;
    vector<pair<int,int>> node(m);
    for(int i =0; i<m; i++){
        cin >> a >> b;
        node[i].first = a;
        node[i].second = b;
    }
    int low = 0, high = m-1, ans = 0 ;
    while (low<=high)
    {
        int mid = low+(high-low)/2;
        if (CheckBi(node,mid)){
            ans = mid+1;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    cout << ans << endl;
    return 0;
}