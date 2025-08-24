#include <iostream>
#include <vector>
#include <cmath>

// ฟังก์ชันสร้าง Sieve เพื่อหาจำนวนเฉพาะถึง R
std::vector<bool> sieve(int R) {
    std::vector<bool> isPrime(R + 1, true); // สร้างเวกเตอร์ขนาด R+1 โดยเริ่มต้นเป็น true
    isPrime[0] = isPrime[1] = false;        // 0 และ 1 ไม่ใช่จำนวนเฉพาะ
    for (int i = 2; i <= std::sqrt(R); ++i) {
        if (isPrime[i]) {                   // ถ้า i เป็นจำนวนเฉพาะ
            for (int j = i * i; j <= R; j += i) {
                isPrime[j] = false;         // ตัดพหุคูณของ i ออก
            }
        }
    }
    return isPrime;
}

int main() {
    int L, R;
    std::cin >> L >> R;                     // รับค่า L และ R จากผู้ใช้
    
    // สร้าง Sieve ถึง R
    std::vector<bool> isPrime = sieve(R);
    
    int count = 0;                          // ตัวแปรนับจำนวนคู่
    // วนลูปตั้งแต่ L ถึง R-2 เพื่อหาคู่ที่ห่างกัน 2
    for (int i = L; i <= R - 2; ++i) {
        if (isPrime[i] && isPrime[i + 2]) { // ถ้า i และ i+2 เป็นจำนวนเฉพาะ
            count++;                        // เพิ่มจำนวนคู่
        }
    }
    
    std::cout << count << std::endl;        // แสดงผลลัพธ์
    return 0;
}