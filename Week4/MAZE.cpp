#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool Isinmap(int x, int y, int n) {
    return x >= 0 && x < n && y >= 0 && y < n;
}
struct CurrentBFS {
    int x, y, IsneedKey;
};

bool Walk(int n,int r,int c,int a,int b,vector<vector<char>>& maze) {
    int DistX[] = {-1, 1, 0, 0};
    int DistY[] = {0, 0, -1, 1};
    vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(n, vector<bool>(2, false)));
    queue<CurrentBFS> q;
    visited[r][c][0] = true;
    q.push({r, c, 0});

    // Debug
    // cout << "r: " << r << " c: " << c << " a: " << a << " b: " << b << endl;
    // cout << endl;
    
    
    while (!q.empty())  
    {
        /* code */
        CurrentBFS node = q.front();

        // cout << "node: " << node.x << " " << node.y << " " << node.IsneedKey << endl;
        q.pop();
        
        if (node.x == a && node.y == b) {
            // Debug
            // cout << node.x << " == "<< a << " " << node.y << " == "<< b << " " << node.IsneedKey << endl;
            // cout << "Yes" << endl;
            // cout << endl;
            return true;
        }
        for (int i = 0; i < 4; i++) {
            int moveX = node.x + DistX[i];  
            int moveY = node.y + DistY[i];  
            
            if (Isinmap(moveX, moveY, n) && !visited[moveX][moveY][node.IsneedKey]) {
                // cout << "moveX: " << moveX << " moveY: " << moveY << endl;
                if (maze[moveX][moveY] == '#'){
                    // cout << "Wall" << endl;
                     continue; // กำแพง
                }
                if (maze[moveX][moveY] == 'O') { // ประตู
                    // cout << "Door" << endl;
                    if (node.IsneedKey == 0) {
                        visited[moveX][moveY][1] = true;
                        q.push({moveX, moveY, 1});
                    }
                }
                else{
                    // cout << "Normal" << endl;
                    visited[moveX][moveY][node.IsneedKey] = true;
                    q.push({moveX, moveY, node.IsneedKey});
                }
            }
            else{
                // cout << moveX << " " << moveY << " " << node.IsneedKey << " " << endl;
                // cout << "Out of map" << endl;
                // cout << endl;
            }
        }
    }
    return false;
}

int main() {
    int n,q, r, c, a, b;
    cin >> n >> q;
    vector<vector<char>> maze(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }

    for (int i = 0; i < q; i++) {
        
        cin >> r >> c >> a >> b;
        // cout << "r: " << r << " c: " << c << " a: " << a << " b: " << b << endl;
        r--; c--; a--; b--;
        if (Walk(n, r, c, a, b, maze)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    return 0;
}