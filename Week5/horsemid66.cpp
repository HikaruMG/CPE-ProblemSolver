#include <bits/stdc++.h>
using namespace std;

struct Horse {
    int x, y, dist, KnightMove;
    Horse(int x_, int y_, int dist_, int used_) : x(x_), y(y_), dist(dist_), KnightMove(used_) {}
};

// 4 ทิศทางปกติ
const int DirectRow[] = {-1, 1, 0, 0}; 
const int DirectColumn[] = {0, 0, -1, 1}; 

// 8 ทิศทางกระโดดแบบม้า
const int KDirectRow[] = {-2, -2, -1, -1, 2, 2, 1, 1};
const int KDirectColumn[] = {-1, 1, -2, 2, -1, 1, -2, 2};

bool CanMove(const vector<vector<char>>& Chess, int x, int y, int n) {
    return (x >= 0 && x < n && y >= 0 && y < n && Chess[x][y] == '.');
}

int play(const vector<vector<char>>& Chess, int n) {
    if (Chess[0][0] != '.' || Chess[n-1][n-1] != '.') {
        return -1;
    }
    
    vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(n, vector<bool>(2, false)));
    queue<Horse> q;
    
    q.push({0, 0, 0, 0}); // (x, y, distance, KnightMove)
    visited[0][0][0] = true;
    
    while (!q.empty()) {
        Horse Cnode = q.front();
        q.pop();
        
        if (Cnode.x == n-1 && Cnode.y == n-1) {
            return Cnode.dist;
        }

        for (int d = 0; d < 4; ++d) {
            int nextX = Cnode.x + DirectRow[d];
            int nextY = Cnode.y + DirectColumn[d];

            if (CanMove(Chess, nextX, nextY, n) && !visited[nextX][nextY][Cnode.KnightMove]) {
                q.push({nextX, nextY, Cnode.dist + 1, Cnode.KnightMove});
                visited[nextX][nextY][Cnode.KnightMove] = true;
            }
        }

        if (Cnode.KnightMove == 0) {
            for (int d = 0; d < 8; ++d) {
                int nextX = Cnode.x + KDirectRow[d];
                int nextY = Cnode.y + KDirectColumn[d];

                if (CanMove(Chess, nextX, nextY, n) && !visited[nextX][nextY][1]) {
                    q.push({nextX, nextY, Cnode.dist + 1, 1});
                    visited[nextX][nextY][1] = true;
                }
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<vector<char>> Chess(n, vector<char>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> Chess[i][j];
        }
    }

    cout << play(Chess, n) << endl;

    return 0;
}
