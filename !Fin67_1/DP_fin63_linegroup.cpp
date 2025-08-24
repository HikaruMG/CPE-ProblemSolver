#include <iostream>
#include <vector>
#include <climits>
using namespace std;
vector<int> opacity;
int main() {
    int N;
    cin >> N;
    opacity.resize(N);
    vector<int> dp(N, INT_MAX);
    for (int i = 0; i < N; i++) {
        cin >> opacity[i];
    }
    for (int i = 1; i < min(10, N); i++) {
        int ValueMax = opacity[0];
        int ValueMin = opacity[0];

        for (int j = 1; j <= i; j++) {
            ValueMax = max(ValueMax, opacity[j]);
            ValueMin = min(ValueMin, opacity[j]);
        }
        dp[i] = ValueMax - ValueMin;
    }


    for (int i = 2; i < N; i++) { // เริ่มที่ 2 เพราะกลุ่มแรกครอบคลุม i=1 แล้ว
        for (int j = 2; j <= 10 && i - j + 1 >= 0; j++) { // ขนาดกลุ่ม 2-10
            int ValueMax = opacity[i];
            int ValueMin = opacity[i];
            for (int k = 1; k < j && i - k >= 0; k++) {
                ValueMax = max(ValueMax, opacity[i - k]);
                ValueMin = min(ValueMin, opacity[i - k]);
            }
            if (i - j >= 0) { // ถ้ามีกลุ่มก่อนหน้า
                if (dp[i - j] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i-j] + (ValueMax-ValueMin));
                }
            } else { // กรณีกลุ่มแรก
                dp[i] = min(dp[i], ValueMax-ValueMin);
            }
        }
    }
    cout << dp[N - 1] << endl; // ผลลัพธ์ที่ตำแหน่งสุดท้าย
    return 0;
}