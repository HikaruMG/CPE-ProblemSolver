#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <limits>
using namespace std;

const int INF = 1e9;

int main() {
    int R, C;
    cin >> R >> C;
    int A, B, X, Y;
    cin >> A >> B >> X >> Y;
    // แปลงตำแหน่งจาก 1-indexed เป็น 0-indexed
    A--; B--; X--; Y--;
    
    vector<string> grid(R);
    for (int i = 0; i < R; i++) {
        cin >> grid[i];
    }
    
    // dist[r][c][used]: ระยะทางน้อยที่สุดที่ไปถึงตำแหน่ง (r, c) โดย used = 0 (ยังไม่เจาะ) หรือ 1 (เจาะแล้ว)
    vector<vector<vector<int>>> dist(R, vector<vector<int>>(C, vector<int>(2, INF)));
    
    // ใช้ priority queue สำหรับ Dijkstra โดยเก็บ state เป็น (cost, r, c, used)
    typedef tuple<int, int, int, int> state;
    priority_queue<state, vector<state>, greater<state>> pq;
    
    // เริ่มที่ตำแหน่งเริ่มต้นโดยยังไม่ใช้การเจาะ
    dist[A][B][0] = 0;
    pq.push({0, A, B, 0});
    
    // กำหนดการเคลื่อนที่แบบปกติใน 4 ทิศ (ขึ้น, ซ้าย, ลง, ขวา)
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, -1, 0, 1};
    
    while (!pq.empty()) {
        auto temp = pq.top();
        int d = get<0>(temp);
        int r = get<1>(temp);
        int c = get<2>(temp);
        int used = get<3>(temp);
        pq.pop();
        
        if (d != dist[r][c][used]) continue; // หาก state นี้ไม่ใช่ระยะทางที่ดีที่สุด ให้ข้ามไป
        
        // หากถึงจุดปลายทางแล้ว ให้แสดงผลและจบโปรแกรม
        if (r == X && c == Y) {
            cout << d << endl;
            return 0;
        }
        
        // 1. เคลื่อนที่ตามปกติ (เดินจากเซลล์หนึ่งไปยังเซลล์ที่ติดกัน ถ้าเป็นทางเดิน)
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if (grid[nr][nc] != '.') continue; // เคลื่อนที่ได้เฉพาะเซลล์ที่เป็นทางเดิน ('.')
            if (dist[nr][nc][used] > d + 1) {
                dist[nr][nc][used] = d + 1;
                pq.push({d + 1, nr, nc, used});
            }
        }
        
        // 2. หากยังไม่ใช้การเจาะ (used == 0) ให้ลองใช้ portal
        if (used == 0) {
            // แนวตั้ง: ลง
            if (r + 1 < R && r + 2 < R) {
                if (grid[r+1][c] == '*' && grid[r+2][c] == '.') {
                    if (dist[r+2][c][1] > d + 2) {
                        dist[r+2][c][1] = d + 2;
                        pq.push({d + 2, r+2, c, 1});
                    }
                }
            }
            // แนวตั้ง: ขึ้น
            if (r - 1 >= 0 && r - 2 >= 0) {
                if (grid[r-1][c] == '*' && grid[r-2][c] == '.') {
                    if (dist[r-2][c][1] > d + 2) {
                        dist[r-2][c][1] = d + 2;
                        pq.push({d + 2, r-2, c, 1});
                    }
                }
            }
            
            // แนวนอน: ขวา
            if (c + 1 < C && c + 2 < C) {
                if (grid[r][c+1] == '*' && grid[r][c+2] == '.') {
                    if (dist[r][c+2][1] > d + 2) {
                        dist[r][c+2][1] = d + 2;
                        pq.push({d + 2, r, c+2, 1});
                    }
                }
            }
            // แนวนอน: ซ้าย
            if (c - 1 >= 0 && c - 2 >= 0) {
                if (grid[r][c-1] == '*' && grid[r][c-2] == '.') {
                    if (dist[r][c-2][1] > d + 2) {
                        dist[r][c-2][1] = d + 2;
                        pq.push({d + 2, r, c-2, 1});
                    }
                }
            }
        }
    }
    
    // หากค้นหาเสร็จแล้วยังไม่พบเส้นทาง ให้แสดงผล -1
    cout << -1 << endl;
    return 0;
}
