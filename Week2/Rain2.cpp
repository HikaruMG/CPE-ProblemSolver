#include <iostream>
#include <stack>
using namespace std;

int main() {
    int N;
    
    while (cin >> N && N != 0) {  // อ่านค่า N และตรวจสอบว่าจบหรือไม่
        while (true) {
            int order[N];
            cin >> order[0];
            if (order[0] == 0) break; // ถ้าเจอ 0 ให้หยุดอ่านลำดับ
            
            for (int i = 1; i < N; i++) {
                cin >> order[i];  // อ่านลำดับขาออกที่ต้องการ
            }

            stack<int> station;  // ใช้เป็นสถานี (Stack)
            int currentCoach = 1;  // เริ่มจากตู้ที่ 1
            int index = 0;         // ชี้ไปยังลำดับที่ต้องการ

            while (currentCoach <= N || !station.empty()) {
                if (!station.empty() && station.top() == order[index]) {
                    station.pop(); // ถ้าตู้ที่อยู่บนสุดของ Stack ตรงกับที่ต้องการ ให้นำออก
                    index++;
                } else if (currentCoach <= N) {
                    station.push(currentCoach++); // ดันตู้เข้า Stack
                } else {
                    break; // ถ้าทำอะไรไม่ได้แล้ว ให้ออกจากลูป
                }
            }

            if (index == N)  // ถ้าจัดเรียงได้ครบทุกตู้
                cout << "Yes\n";
            else
                cout << "No\n";
        }
        cout << "\n"; // เพิ่มบรรทัดว่างตามรูปแบบเอาต์พุต
    }
    return 0;
}
