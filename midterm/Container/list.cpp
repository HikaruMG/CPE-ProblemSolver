#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> lst;
    int n, value;
    
    // รับข้อมูลจากผู้ใช้
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++) {
        cin >> value;
        if(i % 2 == 0) lst.push_front(value); // เพิ่มที่หน้า
        else lst.push_back(value);            // เพิ่มที่ท้าย
    }
    
    // แสดงข้อมูลใน list
    cout << "List elements: ";
    for(int val : lst) {
        cout << val << " ";
    }
    cout << endl;
    
    // ลบข้อมูลจากหน้าและท้าย
    if(!lst.empty()) {
        lst.pop_front();
        cout << "After pop_front: ";
        for(int val : lst) cout << val << " ";
        cout << endl;
    }
    
    if(!lst.empty()) {
        lst.pop_back();
        cout << "After pop_back: ";
        for(int val : lst) cout << val << " ";
        cout << endl;
    }
    
    return 0;
}