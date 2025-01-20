#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;

    // เพิ่มข้อมูลที่ด้านหลัง
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);

    // เพิ่มข้อมูลที่ด้านหน้า
    dq.push_front(5);

    // แสดงข้อมูลจากด้านหน้า
    cout << "Front: " << dq.front() << endl; // 5

    // แสดงข้อมูลจากด้านหลัง
    cout << "Back: " << dq.back() << endl; // 30

    // ลบข้อมูลที่ด้านหน้า
    dq.pop_front();

    // ลบข้อมูลที่ด้านหลัง
    dq.pop_back();

    // แสดงข้อมูลทั้งหมดใน deque
    cout << "Deque contents: ";
    for (int x : dq) {
        cout << x << " "; // 10 20
    }

    return 0;
}
