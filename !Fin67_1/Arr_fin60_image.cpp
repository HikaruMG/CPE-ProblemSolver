#include <iostream>
using namespace std;

int main() {
    int L, H, R;
    cin >> L >> H >> R;

    // รับข้อมูลภาพต้นฉบับ
    int original[100][100]; // ขนาดสูงสุดตามโจทย์
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < L; j++) {
            cin >> original[i][j];
        }
    }

    // สร้างอาร์เรย์สำหรับเก็บผลลัพธ์
    int blurred[100][100];

    // คำนวณภาพเบลอ
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < L; x++) {
            int sum = 0;  // ผลรวมค่าสี
            int count = 0; // จำนวนจุดที่ใช้คำนวณ

            // ลูปหาจุดในรัศมี R
            for (int dy = -R; dy <= R; dy++) {
                for (int dx = -R; dx <= R; dx++) {
                    int ny = y + dy; // พิกัด y ใหม่
                    int nx = x + dx; // พิกัด x ใหม่

                    // ตรวจสอบว่าในรัศมี Manhattan และอยู่ในขอบเขตภาพ
                    if (abs(dx) + abs(dy) <= R && ny >= 0 && ny < H && nx >= 0 && nx < L) {
                        sum += original[ny][nx];
                        count++;
                    }
                }
            }

            // คำนวณค่าเฉลี่ย (ปัดลงอัตโนมัติเมื่อหารจำนวนเต็ม)
            blurred[y][x] = sum / count;
        }
    }

    // แสดงผลลัพธ์
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < L; j++) {
            cout << blurred[i][j];
            if (j < L - 1) cout << " "; // ช่องว่างระหว่างตัวเลข
        }
        cout << endl;
    }

    return 0;
}