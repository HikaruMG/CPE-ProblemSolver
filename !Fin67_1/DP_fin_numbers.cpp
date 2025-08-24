#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9; // ค่าที่ใช้แทน -infinity

int main() {
    int N;
    cin >> N;
    
    // อาร์เรย์เก็บค่าบนขั้นบันได
    vector<int> val(N + 1); // ขั้น 0 ถึง N
    for (int i = 1; i <= N; i++) {
        cin >> val[i];
    }
    val[0] = 0; // ขั้น 0 ไม่มีค่า
    
    // อาร์เรย์เก็บขั้นบังคับ
    vector<int> force(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> force[i];
    }
    force[0] = 0; // ขั้น 0 ไม่บังคับ
    
    // อาร์เรย์ DP
    vector<long long> dp(N + 1, -INF); // ใช้ long long เพราะผลรวมอาจเกิน int
    dp[0] = 0; // เริ่มจากขั้น 0 ได้ 0
    
    // คำนวณ DP
    for (int i = 0; i <= N; i++) {
        if (dp[i] == -INF) continue; // ถ้ามาถึงขั้นนี้ไม่ได้ ข้ามไป
        
        // ลองก้าวไป 1, 2, 3, 4 ขั้น
        for (int step = 1; step <= 4 && i + step <= N + 1; step++) {
            int next = i + step;
            // ถ้า next <= N และ next เป็นขั้นบังคับ หรือ i เป็นจุดเริ่มต้น
            if (next <= N && force[next] == 1) {
                dp[next] = max(dp[next], dp[i] + val[next]);
            } else if (next <= N) {
                // เลือกได้ว่าจะเหยียบหรือไม่เหยียบ
                dp[next] = max(dp[next], dp[i] + val[next]); // เหยียบ
                dp[next] = max(dp[next], dp[i]); // ไม่เหยียบ
            } else {
                // เกิน N ไปแล้ว
                dp[N] = max(dp[N], dp[i]);
            }
        }
    }
    
    // หาคำตอบ
    long long ans = dp[N];
    cout << ans << endl;
    
    return 0;
}