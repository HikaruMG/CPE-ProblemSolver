#include <bits/stdc++.h>
using namespace std;

int directX[4] = {-1,0,1,0}; // ขึ้น ขาว ลง ซ้าย
int dirextY[4] = {0,1,0,-1};
int c[4] = {5,1,0,1};

struct state {
    int x,y,E;
    state(int x, int y, int e) : x(x), y(y), E(e) {}
    bool operator>(const state& other) const {
        return E > other.E;
    }
};

int play(int H, int W, vector<string>& grids) {
    vector<vector<int>> minE(H,vector<int>(W,INT_MAX));
    priority_queue<state, vector<state>, greater<state>> pq;
    minE[H-1][0] = 0;
    pq.push({H-1,0,0});

    while (!pq.empty()) {
        state Cur = pq.top();
        pq.pop();
        int x = Cur.x;
        int y = Cur.y;
        int E = Cur.E;
        if (E > minE[x][y]) {
            continue;
        }
        if (x == 0 and y == W-1) {
            return E;
        }

        for (int a = 0; a < 4; ++a) {
            int nx = x + directX[a];
            int ny = y + dirextY[a];
            int Ncost = E+c[a];

            if (nx >= 0 and nx < H and ny >= 0 and ny<W and grids[nx][ny] != 'X' and Ncost < minE[nx][ny]) {
                minE[nx][ny] = Ncost;
                pq.push({nx,ny,Ncost});
            }
        }
    }
    return -1;
}
int main(){
    int H,W;
    cin >> H >> W;
    vector<string> grids(H);
    for (int a = 0; a < H; ++a) {
        cin >> grids[a];
    }
    int ans = play(H,W,grids);
    cout << ans << endl;
    return 0;
}