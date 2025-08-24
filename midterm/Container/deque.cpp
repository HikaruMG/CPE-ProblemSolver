#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;
    int n, value;
    
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++) {
        cin >> value;
        if(i % 2 == 0) dq.push_front(value); // เพิ่มที่หน้า
        else dq.push_back(value);            // เพิ่มที่ท้าย
    }
    
    cout << "Deque elements: ";
    while(!dq.empty()) {
        cout << dq.front() << " ";
        dq.pop_front();
    }
    cout << endl;
    
    return 0;
}