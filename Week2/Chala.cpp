#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m;
    cin >> m;  // จำนวนกิจกรรม

    // สร้าง vector สำหรับเก็บตู้รถไฟที่แต่ละชานชลา
    vector<vector<int>> platforms(100001);  // ชานชลา 1 ถึง 100,000

    // ประมวลผลกิจกรรม
    for (int idx = 0; idx < m; idx++) {  // เปลี่ยนชื่อจาก 'i' เป็น 'idx'
        char activity;
        int x, i, j;
        cin >> activity;

        if (activity == 'N') {
            cin >> x >> i;  // หมายเลขตู้ x และ หมายเลขชานชลา i
            platforms[i].push_back(x);  // เพิ่มตู้รถไฟที่ชานชลา i
        } else if (activity == 'M') {
            cin >> i >> j;  // หมายเลขชานชลา i และ j
            // ย้ายตู้รถไฟจากชานชลา i ไปยังชานชลา j
            platforms[j].insert(platforms[j].end(), platforms[i].begin(), platforms[i].end());
            platforms[i].clear();  // เคลียร์ตู้รถไฟจากชานชลา i
        }
    }

    // พิมพ์รายการตู้รถไฟจากชานชลา 1 ถึง 100,000
    for (int i = 1; i <= 100000; i++) {
        for (int x : platforms[i]) {
            cout << x << endl;
        }
    }

    return 0;
}
