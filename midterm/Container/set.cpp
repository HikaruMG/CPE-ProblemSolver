#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;
    
    // เพิ่มข้อมูล
    s.insert(5);
    s.insert(2);
    s.insert(9);
    s.insert(2); // 2 มีอยู่แล้ว จะไม่ถูกเพิ่มซ้ำ
    
    // แสดงข้อมูล (เรียงลำดับอัตโนมัติ)
    cout << "Set elements: ";
    for(int x : s) cout << x << " ";
    cout << endl;
    
    // ค้นหาและลบ
    if(s.find(5) != s.end()) {
        s.erase(5);
        cout << "After erasing 5: ";
        for(int x : s) cout << x << " ";
        cout << endl;
    }
    
    return 0;
}