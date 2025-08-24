#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int N;
    cin >> N;

    // อ่านข้อมูลกำไร Ci และ Bi
    vector<ll> C(N+1), B(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> C[i] >> B[i];
    }

    // สร้างตาราง DP: dp[i][state] แทนกำไรสูงสุดถึงตึก i ในสถานะ state
    vector<vector<ll>> dp(N+1, vector<ll>(3, 0));

    // กรณีเริ่มต้นที่ตึก 1
    dp[1][0] = 0;          // ไม่เปิดร้าน
    dp[1][1] = C[1];       // เปิดร้านกาแฟ
    dp[1][2] = B[1];       // เปิดร้านเบเกอรี่

    // คำนวณ DP สำหรับตึก 2 ถึง N
    for (int i = 2; i <= N; i++) {
        // สถานะ None: เลือกกำไรสูงสุดจากตึกก่อนหน้า
        dp[i][0] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]});

        // สถานะ Coffee: ตึกก่อนหน้าต้องไม่เป็น Coffee
        dp[i][1] = C[i] + max(dp[i-1][0], dp[i-1][2]);

        // สถานะ Bakery: ตึกก่อนหน้าต้องไม่เป็น Bakery
        dp[i][2] = B[i] + max(dp[i-1][0], dp[i-1][1]);
    }

    // หาคำตอบสูงสุดที่ตึก N
    ll max_profit = max({dp[N][0], dp[N][1], dp[N][2]});

    // ถ้ากำไรเป็นลบ ให้เลือกไม่เปิดร้าน (กำไร = 0)
    if (max_profit < 0) max_profit = 0;

    cout << max_profit << endl;

    return 0;
}