#include <iostream>
#include <vector>
#include <map>
#include <climits>
using namespace std;

const int INF = 1e9; // ค่าที่แทน infinity

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // dp[i][stock] = จำนวนวันที่หิวขั้นต่ำ
    // ใช้ vector ของ map เพื่อเก็บเฉพาะ stock ที่ใช้งาน
    vector<map<long long, int>> dp(N + 1);
    
    // เริ่มต้นวัน 0
    dp[0][0] = 0; // ไม่มีอาหารสะสม และยังไม่หิว

    // Bottom-Up DP
    for (int i = 0; i < N; i++) {
        for (auto [stock, hungry] : dp[i]) {
            if (hungry == INF) continue; // ข้ามกรณีที่ไม่รอด
            long long total = stock + A[i]; // อาหารทั้งหมดในวันนี้
            if (total < M) continue; // ไม่รอด
            
            // ลองกินทุกจำนวนที่เป็นไปได้
            for (long long eat = M; eat <= total; eat++) {
                long long new_stock;
                int new_hungry = hungry;
                
                if (eat < K) { // หิว
                    new_stock = 0; // กินทั้งหมดที่เหลือ
                    new_hungry = hungry + 1; // เพิ่มวันที่หิว
                    eat = total; // ปรับ eat ให้ครอบคลุมการกินทั้งหมด
                } else { // ไม่หิว
                    new_stock = total - eat;
                }
                
                // อัปเดต dp[i+1][new_stock]
                if (dp[i + 1].find(new_stock) == dp[i + 1].end() || 
                    dp[i + 1][new_stock] > new_hungry) {
                    dp[i + 1][new_stock] = new_hungry;
                }
            }
        }
    }

    // หาคำตอบจาก dp[N]
    int min_hungry = INF;
    for (auto [stock, hungry] : dp[N]) {
        if (hungry < min_hungry) {
            min_hungry = hungry;
        }
    }

    if (min_hungry == INF) {
        cout << -1 << endl; // ไม่รอด
    } else {
        cout << min_hungry << endl; // จำนวนวันที่หิวขั้นต่ำ
    }

    return 0;
}