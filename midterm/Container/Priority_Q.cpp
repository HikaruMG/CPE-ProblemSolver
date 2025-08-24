#include <iostream>
#include <queue>
using namespace std;

int main() {
    // สร้าง priority queue แบบ Max-Heap (default)
    priority_queue<int> pq;
    
    // รับข้อมูลจากผู้ใช้
    int n, value;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++) {
        cin >> value;
        pq.push(value);
    }
    
    // แสดงข้อมูลตามลำดับความสำคัญ (สูงสุด -> ต่ำสุด)
    cout << "Priority Queue elements (Max-Heap): ";
    while(!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
    
    return 0;
}