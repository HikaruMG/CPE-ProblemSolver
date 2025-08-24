#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    // รับลำดับข้อมูล
    vector<int> sequence(M);
    vector<vector<int>> pos(N + 1); // pos[x] เก็บตำแหน่งที่ x ปรากฏ
    for (int i = 0; i < M; i++) {
        cin >> sequence[i];
        pos[sequence[i]].push_back(i); // บันทึกตำแหน่ง (0-based)
    }

    // คำนวณคะแนนเรทติ้งสำหรับแต่ละรายการ
    vector<int> rating(N + 1, 0); // rating[x] เก็บคะแนนของรายการ x
    for (int x = 1; x <= N; x++) {
        if (pos[x].empty()) {
            rating[x] = 0; // ถ้าไม่ปรากฏเลย ได้ 0
            continue;
        }
        if (pos[x].size() == 1) {
            rating[x] = 1; // ถ้าปรากฏครั้งเดียว ได้ 1
            continue;
        }

        int max_len = 0;
        int left = 0;
        for (int right = 0; right < pos[x].size(); right++) {
            // เลื่อน left ถ้าช่องว่างเกิน 5
            while (pos[x][right] - pos[x][left] > 5 && left < right) {
                left++;
            }
            // ความยาวคือจำนวนสมาชิกในหน้าต่าง
            int current_len = right - left + 1;
            max_len = max(max_len, current_len);
        }
        rating[x] = max_len;
    }

    // หารายการที่มีคะแนนสูงสุด
    int best_rating = 0;
    int best_show = 1;
    for (int x = 1; x <= N; x++) {
        if (rating[x] > best_rating) {
            best_rating = rating[x];
            best_show = x;
        } else if (rating[x] == best_rating && x < best_show) {
            best_show = x;
        }
    }

    // แสดงผลลัพธ์
    cout << best_show << " " << best_rating << endl;

    return 0;
}