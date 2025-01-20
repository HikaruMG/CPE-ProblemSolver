#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct State {
    int x, y, usedKey;
};

bool isValid(int x, int y, int n) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

bool canReach(vector<vector<char>>& maze, int n, int R, int C, int A, int B) {
    vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(n, vector<bool>(2, false)));
    queue<State> q;
    
    // เริ่มจากตำแหน่ง (R, C) โดยไม่มีการใช้กุญแจ
    q.push({R, C, 0});
    visited[R][C][0] = true;

    // ทิศทางการเดิน (ขึ้น, ลง, ซ้าย, ขวา)
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!q.empty()) {
        State curr = q.front();
        q.pop();

        // ถ้าถึงจุดปลาย
        if (curr.x == A && curr.y == B) {
            return true;
        }

        // ลูปเดินทางไปทิศทางต่างๆ
        for (int i = 0; i < 4; ++i) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];

            if (isValid(nx, ny, n) && !visited[nx][ny][curr.usedKey]) {
                if (maze[nx][ny] == '#') continue; // กำแพง

                if (maze[nx][ny] == '0') { // ประตู
                    if (curr.usedKey == 0) { // ยังไม่มีการใช้กุญแจ
                        // ใช้กุญแจแล้วเดินต่อ
                        visited[nx][ny][1] = true;
                        q.push({nx, ny, 1});
                    }
                } else { // ทางเดินปกติ
                    visited[nx][ny][curr.usedKey] = true;
                    q.push({nx, ny, curr.usedKey});
                }
            }
        }
    }

    return false; // ถ้าไม่มีทางไปถึง
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<vector<char>> maze(n, vector<char>(n));

    // อ่านแผนที่
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> maze[i][j];
        }
    }

    // ตอบคำถาม
    for (int i = 0; i < q; ++i) {
        int R, C, A, B;
        cin >> R >> C >> A >> B;
        R--; C--; A--; B--; // เปลี่ยนจาก 1-based เป็น 0-based index

        if (canReach(maze, n, R, C, A, B)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    return 0;
}
