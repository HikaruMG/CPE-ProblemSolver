#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// โครงสร้างข้อมูลสำหรับการเก็บตำแหน่งและจำนวนก้าว
struct Point {
    int x, y, steps;
};

// การเคลื่อนที่ที่สามารถทำได้
const vector<Point> moves = {
    {-1, 0, 1},  // ขึ้น 1 เซลล์
    {1, 0, 1},   // ลง 1 เซลล์
    {0, -1, 1},  // ซ้าย 1 เซลล์
    {0, 1, 1},   // ขวา 1 เซลล์
    {-2, 0, 2},  // ขึ้น 2 เซลล์
    {2, 0, 2},   // ลง 2 เซลล์
    {0, -2, 2},  // ซ้าย 2 เซลล์
    {0, 2, 2}    // ขวา 2 เซลล์
};

// ฟังก์ชันตรวจสอบการเคลื่อนที่ว่าอยู่ในขอบเขตและเป็นเซลล์ที่สามารถเดินได้หรือไม่
bool isValidMove(int x, int y, int N, vector<vector<char>>& grid) {
    return (x >= 0 && x < N && y >= 0 && y < N && grid[x][y] == '.');
}

// ฟังก์ชันหาเส้นทางที่สั้นที่สุดจากจุดเริ่มต้นไปยังจุดสิ้นสุด
int minStepsToReachEnd(vector<vector<char>>& grid) {
    int N = grid.size();
    vector<vector<bool>> visited(N, vector<bool>(N, false));  // เก็บสถานะการเยี่ยมชมแต่ละเซลล์
    queue<Point> q;  // คิวสำหรับการค้นหาแบบ BFS
    q.push({0, 0, 0});  // เริ่มต้นที่ (0, 0) ด้วยจำนวนก้าว 0
    visited[0][0] = true;

    while (!q.empty()) {
        Point current = q.front();
        q.pop();

        // ถ้าถึงจุดสิ้นสุด ให้คืนค่าจำนวนก้าว
        if (current.x == N - 1 && current.y == N - 1) {
            return current.steps;
        }

        // ตรวจสอบการเคลื่อนที่ที่เป็นไปได้ทั้งหมด
        for (const auto& move : moves) {
            int newX = current.x + move.x;
            int newY = current.y + move.y;

            // ถ้าการเคลื่อนที่ถูกต้องและยังไม่เคยเยี่ยมชม ให้เพิ่มเข้าไปในคิว
            if (isValidMove(newX, newY, N, grid) && !visited[newX][newY]) {
                q.push({newX, newY, current.steps + move.steps});
                visited[newX][newY] = true;
            }
        }
    }

    return -1; // ถ้าไม่มีเส้นทาง
}

int main() {
    int N;
    cin >> N;  // อ่านขนาดของตาราง
    vector<vector<char>> grid(N, vector<char>(N));

    // อ่านค่าของตาราง
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> grid[i][j];
        }
    }

    int result = minStepsToReachEnd(grid);

    // แสดงผลจำนวนก้าวที่น้อยที่สุดหรือแสดงว่าไม่มีเส้นทาง
    if (result != -1) {
        cout << result << endl;
    } else {
        cout << "ไม่มีเส้นทาง" << endl;
    }

    return 0;
}
