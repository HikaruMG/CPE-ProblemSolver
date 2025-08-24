#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9; // Maximum Power
int main() {
    int T;
    cin >> T; 
    while (T--) {
        int M, N;
        cin >> M >> N; 
        // สร้างตารางเก็บพลังงาน
        vector<vector<int>> Power(M, vector<int>(N));
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                cin >> Power[i][j]; 
            }
        }
        // DP table
        vector<vector<int>> dp(M, vector<int>(N, INF));
        //ค่าเริ่มต้นแถวแรก (เหนือสุด)
        for (int j = 0; j < N; j++) {
            dp[0][j] = Power[0][j];
        }
        // คำนวณ DP แถว 1 ถึง M-1
        for (int i = 1; i < M; i++) {
            for (int j = 0; j < N; j++) {
                // หาค่าต่ำสุด 3 ทิศทาง (ซ้าย,เดียวกัน,ขวา)
                int BeforeMin = dp[i-1][j]; //เดียวกัน
                if (j > 0) {
                    BeforeMin = min(BeforeMin, dp[i-1][j-1]); //ซ้าย
                }
                if (j < N-1) {
                    BeforeMin = min(BeforeMin, dp[i-1][j+1]); //ขวา
                }
                dp[i][j] = Power[i][j] + BeforeMin; // รวมพลังงานของช่องนี้
            }
        }
        // หาค่าต่ำสุดแถวสุดท้าย
        int ans = INF;
        for (int j = 0; j < N; j++) {
            ans = min(ans, dp[M-1][j]);
        }
        cout << ans << endl; 
    }

    return 0;
}