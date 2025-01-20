#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ฟังก์ชันตรวจสอบว่ากราฟสามารถแบ่งออกเป็นสองกลุ่มได้หรือไม่
bool isBipartite(int n, const vector<pair<int, int>>& matches, int day) {
    vector<int> color(n + 1, -1); // -1 หมายถึงยังไม่ถูกทำสี
    vector<vector<int>> adj(n + 1); // สร้างกราฟ

    // สร้างกราฟจากการแข่งขันจนถึงวันที่ `day`
    for (int i = 0; i < day; ++i) {
        int u = matches[i].first;
        int v = matches[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // ใช้ BFS ในการตรวจสอบว่าเป็น bipartite หรือไม่
    for (int i = 1; i <= n; ++i) {
        if (color[i] == -1) {
            queue<int> q;
            q.push(i);
            color[i] = 0; // เริ่มต้นให้สีเป็น 0

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int neighbor : adj[node]) {
                    if (color[neighbor] == -1) {
                        color[neighbor] = 1 - color[node]; // เปลี่ยนสีเป็นตรงข้าม
                        q.push(neighbor);
                    } else if (color[neighbor] == color[node]) {
                        return false; // ถ้าสีตรงกันแสดงว่าไม่สามารถแบ่งกลุ่มได้
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> matches(m);
    for (int i = 0; i < m; ++i) {
        cin >> matches[i].first >> matches[i].second;
    }

    // Binary search เพื่อหาวันที่ช้าที่สุดที่สามารถแบ่งได้
    int left = 1, right = m, result = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (isBipartite(n, matches, mid)) {
            result = mid; // ถ้าสามารถแบ่งได้ในวันที่ `mid` ให้บันทึกวันนั้น
            left = mid + 1; // ลองค้นหาวันที่มากกว่านี้
        } else {
            right = mid - 1; // ถ้าไม่สามารถแบ่งได้ให้ลองค้นหาวันที่น้อยกว่านี้
        }
    }

    cout << result << endl;
    return 0;
}
