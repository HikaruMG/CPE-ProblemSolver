#include <iostream>
#include <vector>
using namespace std;

int main() {
    // ประกาศ vector สำหรับเก็บจำนวนเต็ม
    vector<int> vec;
    int n, x;

    // รับจำนวนสมาชิกที่ต้องการเก็บใน vector
    cout << "Enter the number of elements: ";
    cin >> n;

    // ใช้ลูปสำหรับรับค่าแต่ละตัวแล้วเก็บไว้ใน vector
    for (int i = 0; i < n; i++) {
        // cout << "Enter element " << i + 1 << ": ";
        cin >> x;
        vec.push_back(x);  // เพิ่มค่า x เข้าไปใน vector
    }

    // แสดงผลสมาชิกทั้งหมดใน vector
    cout << "Vector elements are: ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    return 0;
}
