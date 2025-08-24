#include <iostream>
#include <vector>
#include <algorithm>  // ต้องใช้ lower_bound

using namespace std;

int main() {
    vector<int> v = {10, 20, 30, 40, 50};

    auto it = lower_bound(20, 30, 25);
    
    if (it != v.end()) {
        cout << "ค่าที่ไม่ต่ำกว่า 25 คือ " << *it << endl;
    } else {
        cout << "ไม่มีค่าที่ไม่ต่ำกว่า 25" << endl;
    }
}
