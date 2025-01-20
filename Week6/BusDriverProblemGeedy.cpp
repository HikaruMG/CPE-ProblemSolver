#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    while (true) {
        int n, d, r;
        cin >> n >> d >> r;
        
        // ตรวจสอบว่าเป็นกรณีที่ไม่มีข้อมูล
        if (n == 0 && d == 0 && r == 0) {
            break;
        }
        
        vector<int> morning(n), evening(n);
        
        // รับข้อมูลเส้นทางรถบัสเช้า
        for (int i = 0; i < n; i++) {
            cin >> morning[i];
        }
        
        // รับข้อมูลเส้นทางรถบัสเย็น
        for (int i = 0; i < n; i++) {
            cin >> evening[i];
        }
        
        // เรียงลำดับเส้นทางทั้งสองเพื่อให้ค่าล่วงเวลาน้อยที่สุด
        sort(morning.begin(), morning.end());
        sort(evening.begin(), evening.end());
        
        int totalOvertime = 0;
        
        // คำนวณค่าล่วงเวลาสำหรับแต่ละคนขับ
        for (int i = 0; i < n; i++) {
            int totalLength = morning[i] + evening[i];
            if (totalLength > d) {
                totalOvertime += (totalLength - d) * r;
            }
        }
        
        // แสดงผลค่าล่วงเวลารวม
        cout << totalOvertime << endl;
    }
    
    return 0;
}
