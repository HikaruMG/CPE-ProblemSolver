#include <bits/stdc++.h>
using namespace std;

struct Horse
{
    int x,y,dist;
    Horse(int x_, int y_, int dist_) : x(x_),y(y_),dist(dist_) {}
};

const vector<Horse> HorseM = {
    {-1, 0, 1},  // ขึ้น 1 
    {1, 0, 1},   // ลง 1 
    {0, -1, 1},  // ซ้าย 1
    {0, 1, 1},   // ขวา 1
    {-2, 0, 2},  // ขึ้น 2 
    {2, 0, 2},   // ลง 2
    {0, -2, 2},  // ซ้าย 2 
    {0, 2, 2}    // ขวา 2 
};

bool CanMove(const vector<vector<char>> map,int x,int y, int n){
    return (x>=0 and x<n and y >=0 and y<n and map[x][y] =='.');
}

int play(const vector<vector<char>> map, int n){
    // int n = map.size();
    if(map[0][0] != '.' or map[n-1][n-1] != '.'){
        return -1;
    }
    vector<vector<bool>> visited(n,vector<bool> (n,false));
    queue<Horse> q;
    q.push({0,0,0});
    visited[0][0] = true;
    while (!q.empty())
    {
        Horse Cnode = q.front();
        q.pop();
        if (Cnode.x == n-1 and Cnode.y == n-1){
            return Cnode.dist;
        }
        for(const auto m : HorseM){
            int nextX = Cnode.x+m.x;
            int nextY = Cnode.y+m.y;
            if (CanMove(map,nextX,nextY,n) and !visited[nextX][nextY]){
                q.push({nextX,nextY,Cnode.dist+m.dist});
                visited[nextX][nextY] = true;
            }
        }
    }
    return -1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<vector<char>> map(n,vector<char>(n));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n; j++){
            cin >> map[i][j];
        }
    }
    int ans = play(map,n);

    if (ans != -1) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}