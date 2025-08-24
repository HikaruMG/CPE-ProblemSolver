#include <iostream>
#include <string>
#include <vector>
using namespace std;

int countSubsequence(string S, string T) {
    int m = S.length(); // ความยาวของ S
    int n = T.length(); // ความยาวของ T
    
    // สร้างตาราง DP ขนาด (n+1) × (m+1)
    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
    
    // กรณีฐาน: subsequence ว่างปรากฏได้ 1 ครั้ง
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    
    // เติมตาราง DP
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // ไม่เลือกตัวอักษรปัจจุบัน
            dp[i][j] = dp[i-1][j];
            
            // ถ้าตัวอักษรตรงกัน เลือกตัวอักษรนี้
            if (T[i-1] == S[j-1]) {
                dp[i][j] += dp[i-1][j-1];
            }
        }
    }
    
    // คำนวณจำนวนครั้งสูงสุดแบบ non-overlapping
    long long result = 0;
    int last_pos = -1;
    
    // วนลูปเพื่อหา subsequence แบบ non-overlapping
    for (int i = 1; i <= n; i++) {
        if (dp[i][m] > dp[i-1][m]) {
            result++;
            i += m - 1; // ข้ามไป m ตัวเพื่อไม่ให้ซ้อนกัน
        }
    }
    
    return result;
}

int main() {
    string S, T;
    getline(cin, S); // รับสตริง S
    getline(cin, T); // รับสตริง T
    
    int result = countSubsequence(S, T);
    cout << result << endl;
    
    return 0;
}