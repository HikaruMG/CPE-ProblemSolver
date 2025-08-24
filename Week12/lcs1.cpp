#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    // รับสตริงสองสตริงจาก input
    string S, T;
    getline(cin, S);
    getline(cin, T);
    
    int n = S.size();
    int m = T.size();
    
    // กำหนด dp array ขนาด (n+1) x (m+1) เพื่อบันทึกความยาว LCS ของ S[0...i-1] และ T[0...j-1]
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    // วนลูปจาก i = 1 จนถึง n และ j = 1 จนถึง m
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // หากอักขระที่ตำแหน่ง i-1 ของ S และ j-1 ของ T ตรงกัน
            if (S[i - 1] == T[j - 1]) {
                // ให้ dp[i][j] เท่ากับ dp[i-1][j-1] บวก 1
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                // หากไม่ตรงกัน ให้นำค่าสูงสุดของ dp[i-1][j] กับ dp[i][j-1]
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    // ผลลัพธ์คือ dp[n][m] คือความยาวของ LCS ระหว่าง S และ T
    cout << dp[n][m] << endl;
    
    return 0;
}