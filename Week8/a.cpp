#include <iostream>
#include <vector>

using namespace std;

int main() {
    // สร้าง vector เปล่า
    vector<int> vec;

    // ใช้ push_back เพื่อเพิ่มค่า
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    // แสดงผลลัพธ์
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
    int x;
    cin >> x;
    if (vec[x]!=x) {
        cout << "Yes";
    }
    return 0;
}
