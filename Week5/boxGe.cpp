#include <bits/stdc++.h>
using namespace std;

struct Position {
    int r,c;
    Position(int r_,int c_) : r(r_), c(c_) {}
};

// bool Isinmap(int x, int y, int M) {
//     return x >= 0 && x < M && y >= 0 && y < M;
// }

bool Ismove(int n, int m,int r, int c, vector<string>& map) {
    if(c<0 or r<0){
        return false;
    }
    if(r+1 >= n or c+1 >= m){
        return false;
    }
    if(map[r][c] == '#' or map[r+1][c] == '#' or map[r][c+1] == '#' or map[r+1][c+1] == '#'){
        return false;
    }
    return true;
}
bool TopDown(int n,int m,int r,int c,vector<string>& map) {
    set<pair<int,int>> visited;
    queue<Position> q;
    for(int c = 0; c < m-2; c++){
        if(Ismove(n,m,r,c,map)){
            q.push({r,c});
            visited.insert({r,c});
        }
    }
    int DistX[] = {-1, 1, 0, 0};
    int DistY[] = {0, 0, -1, 1};
    while(!q.empty()){
        Position node = q.front();
        q.pop();
        if(node.r == n-2){
            return true;
        }
        for(int i = 0; i < 4; i++){
            int moveX = node.r + DistX[i];
            int moveY = node.c + DistY[i];
            if(Ismove(n,m,moveX,moveY,map) and visited.find({moveX,moveY}) == visited.end()){
                q.push({moveX,moveY});
                visited.insert({moveX,moveY});
            }
        }
    }
    return false;
    
}

int main(){
    int n,m,r,c;
    cin >> n >> m;
    vector<string> map(n);
    for (int i = 0; i < n; i++) {
        cin >> map[i];
    }
    if(TopDown(n,m,0,0,map)){
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    return 0;

}
