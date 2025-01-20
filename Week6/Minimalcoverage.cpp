#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Segment {
    int left, right;
};

// ฟังก์ชันเปรียบเทียบช่วงเส้นสำหรับการจัดเรียง
bool compare(Segment a, Segment b) {
    return a.left < b.left;
}

int main() {
    int t;
    cin >> t;
    cin.ignore(); // ข้ามบรรทัดว่างหลังจากจำนวน test case

    while (t--) {
        vector<Segment> segments;
        int M;
        cin >> M;

        // อ่านช่วงเส้น
        while (true) {
            int L, R;
            cin >> L >> R;
            if (L == 0 && R == 0) break;
            segments.push_back({L, R});
        }

        // จัดเรียงช่วงเส้นตามตำแหน่งเริ่มต้น
        sort(segments.begin(), segments.end(), compare);

        vector<Segment> selectedSegments;
        int currentCover = 0;
        int i = 0;
        bool possible = true;

        // ใช้กลยุทธ์ greedy เพื่อเลือกช่วงที่ดีที่สุด
        while (currentCover < M && i < segments.size()) {
            int bestRight = currentCover;
            // ค้นหาช่วงที่สามารถขยายการครอบคลุมได้มากที่สุด
            while (i < segments.size() && segments[i].left <= currentCover) {
                bestRight = max(bestRight, segments[i].right);
                i++;
            }

            // ถ้าไม่สามารถขยายการครอบคลุมได้
            if (bestRight == currentCover) {
                possible = false;
                break;
            }

            selectedSegments.push_back(segments[i - 1]);
            currentCover = bestRight;
        }

        // ตรวจสอบว่าเราสามารถครอบคลุมช่วง [0, M] ได้หรือไม่
        if (possible && currentCover >= M) {
            cout << selectedSegments.size() << endl;
            for (const auto& seg : selectedSegments) {
                cout << seg.left << " " << seg.right << endl;
            }
        } else {
            cout << 0 << endl;
        }

        if (t > 0) cout << endl; // ขึ้นบรรทัดว่างระหว่าง test case
    }

    return 0;
}
