#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
vector<string> grid;

// ฟังก์ชันตรวจสอบว่าเราสามารถวางกล่องขนาด 2x2 ที่ตำแหน่ง (x, y) ได้หรือไม่
bool canMove(int x, int y) {
    return x + 1 < N && y + 1 < M && 
           grid[x][y] == '.' && grid[x+1][y] == '.' && 
           grid[x][y+1] == '.' && grid[x+1][y+1] == '.';
}

// ฟังก์ชัน BFS เพื่อค้นหาทางเดิน
bool bfs() {
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(N, vector<bool>(M, false));

    // เริ่มจากทุกจุดที่เป็นช่องว่างในแถวที่ 0 ที่สามารถวางกล่อง 2x2 ได้
    for (int i = 0; i < M - 1; i++) {
        if (grid[0][i] == '.' && grid[0][i+1] == '.') {
            q.push(make_pair(0, i));
            visited[0][i] = true;
            visited[0][i+1] = true;
        }
    }

    // เคลื่อนที่กล่องจากจุดเริ่มต้น
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        
        int x = p.first;
        int y = p.second;

        // ถ้ากล่องไปถึงแถวสุดท้ายได้
        if (x == N - 2) {
            return true;
        }

        // ลองเคลื่อนกล่องไปในทิศทางต่างๆ
        // 1. ลง
        if (canMove(x + 1, y) && !visited[x + 1][y]) {
            q.push(make_pair(x + 1, y));
            visited[x + 1][y] = true;
            visited[x + 1][y + 1] = true;
        }
        // 2. ขวา
        if (y + 2 < M && canMove(x, y + 1) && !visited[x][y + 1]) {
            q.push(make_pair(x, y + 1));
            visited[x][y + 1] = true;
            visited[x + 1][y + 1] = true;
        }
        // 3. ซ้าย
        if (y - 1 >= 0 && canMove(x, y - 1) && !visited[x][y - 1]) {
            q.push(make_pair(x, y - 1));
            visited[x][y - 1] = true;
            visited[x + 1][y - 1] = true;
        }
    }

    return false;
}

int main() {
    cin >> N >> M;
    grid.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> grid[i];
    }

    // เรียกใช้ BFS เพื่อหาทางเดิน
    if (bfs()) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}
