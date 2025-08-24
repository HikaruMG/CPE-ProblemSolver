#include <iostream>
#include <set>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    set<int> elements;
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        elements.insert(x);
    }

    vector<int> results;
    for (int j = 0; j < M; ++j) {
        int y;
        cin >> y;

        auto it = elements.lower_bound(y); // หา element ที่ >= y
        int closest = *it;                // ตั้งค่าเริ่มต้นเป็น lower_bound

        // ตรวจสอบ element ก่อน lower_bound ถ้ามี
        if (it != elements.begin()) {
            auto prev_it = prev(it);
            if (abs(*prev_it - y) <= abs(closest - y)) {
                closest = *prev_it;
            }
        }

        results.push_back(closest);
    }

    for (int res : results) {
        cout << res << endl;
    }

    return 0;
}
