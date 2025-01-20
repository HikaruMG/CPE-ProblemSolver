#include <iostream>
#include <vector>
#include <set>

using namespace std;

// ฟังก์ชันเพื่อตรวจสอบว่าสามารถแบ่งคนเป็นสองบริษัทได้หรือไม่หลังจากลบคู่ที่กำหนด
bool canDivide(int n, vector<pair<int, int>>& matches, int exclude1, int exclude2) {
    vector<int> company(n + 1, -1); // -1 หมายความว่ายังไม่ได้ถูกกำหนดบริษัท

    for (auto match : matches) {
        // ข้ามคู่ที่กำลังตรวจสอบการลบ
        if ((match.first == exclude1 && match.second == exclude2) || (match.first == exclude2 && match.second == exclude1)) {
            continue;
        }

        int person1 = match.first;
        int person2 = match.second;

        // กรณีทั้งสองคนยังไม่ได้ถูกกำหนดบริษัท
        if (company[person1] == -1 && company[person2] == -1) {
            company[person1] = 0;
            company[person2] = 1;
        }
        // กรณีคนแรกยังไม่ถูกกำหนดบริษัท
        else if (company[person1] == -1) {
            company[person1] = 1 - company[person2];
        }
        // กรณีคนที่สองยังไม่ถูกกำหนดบริษัท
        else if (company[person2] == -1) {
            company[person2] = 1 - company[person1];
        }
        // กรณีทั้งสองคนถูกกำหนดบริษัทแล้วและอยู่ในบริษัทเดียวกัน
        else if (company[person1] == company[person2]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m; // อ่านจำนวนคนและจำนวนคู่ของประวัติการเล่นเป่ายิ้งฉุบ

    vector<pair<int, int>> matches(m);
    for (int i = 0; i < m; ++i) {
        cin >> matches[i].first >> matches[i].second; // อ่านคู่ของประวัติการเล่นเป่ายิ้งฉุบ
    }

    // ตรวจสอบคู่ของประวัติการเล่นเป่ายิ้งฉุบทั้งหมด
    for (auto match : matches) {
        if (canDivide(n, matches, match.first, match.second)) {
            cout << match.first << " " << match.second << endl; // แสดงผลคู่ที่สามารถลบออกได้
            break;
        }
    }

    return 0;
}
