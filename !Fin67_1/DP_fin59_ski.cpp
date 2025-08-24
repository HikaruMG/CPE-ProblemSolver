#include <iostream>
#include <vector>
#include <algorithm> // ใช้ max

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    // เก็บข้อมูลความสูงและคะแนน
    vector<long long> H(N), S(N);
    for(int i = 0; i < N; i++) {
        cin >> H[i] >> S[i];
    }
    
    // อาร์เรย์ DP
    vector<long long> dp(N);
    
    // เติมค่าเริ่มต้น: ถ้าไม่ไปต่อ คะแนน = S[i]
    for(int i = 0; i < N; i++) {
        dp[i] = S[i];
    }
    
    // คำนวณ DP จากขวาไปซ้าย
    for(int i = N-2; i >= 0; i--) {
        // ดูแท่นทางขวาทั้งหมด
        for(int j = i+1; j < N; j++) {
            // ตรวจสอบเงื่อนไข
            if(H[i] >= H[j] && H[i] - H[j] <= K) {
                dp[i] = max(dp[i], S[i] + dp[j]);
            }
        }
    }
    
    // หาค่าสูงสุดจากทุกจุดเริ่มต้น
    long long ans = 0;
    for(int i = 0; i < N; i++) {
        ans = max(ans, dp[i]);
    }
    
    cout << ans << endl;
    
    return 0;
}