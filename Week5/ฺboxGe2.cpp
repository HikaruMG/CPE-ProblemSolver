#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// โครงสร้างสำหรับเก็บพิกัดของจุด
struct Point {
    int x, y;
};

// ฟังก์ชันตรวจสอบว่ากล่อง 2x2 สามารถวางที่ตำแหน่ง (x, y) ได้หรือไม่
bool isValidMove(vector<vector<char>> &grid, int x, int y, int N, int M) {
    if (x + 1 >= N || y + 1 >= M) return false; // ตรวจสอบว่ากล่องจะไม่เกินขอบเขตของแผนที่
    return grid[x][y] == '.' && grid[x+1][y] == '.' && grid[x][y+1] == '.' && grid[x+1][y+1] == '.'; // ตรวจสอบว่าตำแหน่งทั้งหมดในกล่องเป็นช่องว่าง
}

// ฟังก์ชันตรวจสอบว่ากล่องสามารถเคลื่อนที่จากด้านบนสุดไปถึงด้านล่างสุดได้หรือไม่
bool canMoveBox(vector<vector<char>> &grid, int N, int M) {
    queue<Point> q; // คิวสำหรับการทำ BFS
    vector<vector<bool>> visited(N, vector<bool>(M, false)); // บันทึกสถานะที่เคยเยี่ยมชมแล้ว
    
    // เพิ่มจุดเริ่มต้นที่เป็นไปได้ทั้งหมดในแถวบนสุดในคิว
    for (int j = 0; j < M-1; j++) {
        if (isValidMove(grid, 0, j, N, M)) {
            q.push({0, j}); // เพิ่มจุดเริ่มต้นในคิว
            visited[0][j] = true; // บันทึกสถานะที่เคยเยี่ยมชมแล้ว
        }
    }
    
    // เริ่มการทำ BFS
    while (!q.empty()) {
        Point p = q.front(); // ดึงจุดที่อยู่หน้าสุดในคิวออกมา
        q.pop();
        
        // ถ้ากล่องถึงแถวล่างสุด แสดงว่าสามารถเคลื่อนผ่านได้
        if (p.x == N-2) return true;
        
        // ทิศทางที่สามารถเคลื่อนที่ได้: ขึ้น ลง ซ้าย ขวา
        vector<Point> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (Point d : directions) {
            int newX = p.x + d.x;
            int newY = p.y + d.y;
            // ตรวจสอบการเคลื่อนที่และสถานะที่เคยเยี่ยมชมแล้ว
            if (newX >= 0 && newX < N-1 && newY >= 0 && newY < M-1 && isValidMove(grid, newX, newY, N, M) && !visited[newX][newY]) {
                q.push({newX, newY}); // เพิ่มจุดใหม่ในคิว
                visited[newX][newY] = true; // บันทึกสถานะที่เคยเยี่ยมชมแล้ว
            }
        }
    }
    return false; // ถ้าไม่สามารถเคลื่อนกล่องไปถึงแถวล่างสุดได้
}

int main() {
    int N, M;
    cin >> N >> M; // อ่านค่าขนาดแผนที่
    vector<vector<char>> grid(N, vector<char>(M)); // สร้างแผนที่
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j]; // อ่านค่าจุดแต่ละจุดในแผนที่
        }
    }
    
    // ตรวจสอบว่ากล่องสามารถเคลื่อนผ่านแผนที่ได้หรือไม่
    if (canMoveBox(grid, N, M)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    
    return 0;
}
