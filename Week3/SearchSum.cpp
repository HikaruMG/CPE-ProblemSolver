#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<long long> prices(n + 1, 0); // ใช้ long long เพื่อป้องกัน overflow
    for (int i = 1; i <= n; ++i) {
        cin >> prices[i];
    }

    // คำนวณ prefix sum
    vector<long long> prefixSum(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefixSum[i] = prefixSum[i - 1] + prices[i];
    }

    // ตอบคำถาม k ครั้ง
    for (int i = 0; i < k; ++i) {
        long long m;
        cin >> m;

        // ใช้ binary search เพื่อหาจำนวนเล่มสูงสุดที่ซื้อได้
        int left = 0, right = n, answer = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (prefixSum[mid] <= m) {
                answer = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        cout << answer << endl;
    }

    return 0;
}
