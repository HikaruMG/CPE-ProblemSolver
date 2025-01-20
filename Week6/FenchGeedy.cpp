#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, l;
    cin >> n >> l;

    vector<pair<int, int>> houses(n);
    for (int i = 0; i < n; i++) {
        cin >> houses[i].first >> houses[i].second;
    }

    // จัดเรียงบ้านตามตำแหน่งเริ่มต้น S_i
    sort(houses.begin(), houses.end());

    int fences = 0;    // จำนวนรั้ว
    int currentEnd = -1; // จุดสิ้นสุดของรั้วปัจจุบัน

    for (int i = 0; i < n; i++) {
        int start = houses[i].first;
        int end = houses[i].second;

        // ถ้าบ้านไม่ถูกครอบคลุมด้วยรั้วปัจจุบัน
        if (start > currentEnd) {
            fences++;                // วางรั้วใหม่
            currentEnd = end + l - 1; // อัปเดตจุดสิ้นสุดของรั้ว
        }
    }

    cout << fences << endl;
    return 0;
}
