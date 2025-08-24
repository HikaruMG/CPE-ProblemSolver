#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> adj(1001);

// void printQueue(queue<int> q) { // รับ queue โดย value (สำเนา)
//     cout << "Queue: ";
//     while (!q.empty()) {
//         cout << q.front() << " ";
//         q.pop();
//     }
//     cout << endl;
// }

int bfs(int E,int hos, vector<vector<int>>& adj){
    int nearH = 0;
    vector<int> route(1001,-1); ;
    queue<int> q;
    q.push(E);
    route[E] = 0;
    while(!q.empty()){
        // printQueue(q);
        int u = q.front();
        // cout << "Front:" << u << endl;
        q.pop();
        if (route[u] <= hos){
            nearH++;
            // cout << "NearH:" << nearH << endl;
        }
        else{
            // cout << "skip" << endl;
            continue;
        }
        for (int v : adj[u]){
            if (route[v] == -1){
                q.push(v);
                route[v] = route[u] + 1;
                // cout << "Route "<< v <<":" " " << route[v] << endl;
                
            }
        }
        // cout << endl;
        
    }
    return nearH;

}
int main(){
    int n,m,h,t;
    int MaxNear = 0;
    cin >> n >> m >> h;
   
    for (int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++){
        // cout << endl;
        // cout << "E:" << i << endl;
        MaxNear = max(MaxNear,bfs(i,h,adj));
    }
    cout << MaxNear;
    return 0;

}