#include <iostream>
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K; // รับค่า N, M, K
    int A[1001]; // อาร์เรย์เก็บจำนวนอาหารที่ได้รับแต่ละวัน
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    long long stock = 0; // อาหารสะสม ใช้ long long เพราะอาจเกิน int
    int hungry_days = 0; // นับวันที่หิว

    for (int i = 0; i < N; i++) {
        stock += A[i]; // เพิ่มอาหารที่ได้รับในวันนี้
        if (stock < M) { // ถ้าอาหารไม่พอขั้นต่ำ ตาย
            cout << -1 << endl;
            return 0;
        }
        
        long long eat;
        if (stock >= K) { // ถ้าอาหารเพียงพอให้ไม่หิว
            eat = K; // กิน K กล่อง
        } else { // ถ้าอาหารน้อยกว่า K (แต่ >= M)
            eat = stock; // กินทั้งหมด (หิว)
            hungry_days++; // นับวันที่หิว
        }
        stock -= eat; // ลด stock ตามที่กินไป
    }

    cout << hungry_days << endl; // แสดงผลจำนวนวันที่หิว
    return 0;
}