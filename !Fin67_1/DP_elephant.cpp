#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> Items;
int main() {
    int N;
    cin >> N; 
    Items.resize(N);
    vector<long long> dp(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> Items[i];
    }
    if(N < 3) {
        cout << 0 << endl;
        return 0;
    }
    dp[0] = 0; 
    dp[1] = 0; 
    dp[2] = Items[2];
    
    for(int i = 3; i < N; i++) {
        // เลือก max ระหว่าง
        // 1. ไม่เก็บกล้วยที่ i = dp[i-1]
        // 2. เก็บกล้วยที่ i = Items[i] + dp[i-3]
        dp[i] = max(dp[i-1], Items[i] + (i >= 3 ? dp[i-3] : 0));
    }
    cout << dp[N-1] << endl;
    return 0;
}