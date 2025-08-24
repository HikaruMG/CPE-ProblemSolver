#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); // เพิ่มความเร็วในการอ่าน/เขียน
    cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    // อ่านราคาสินค้า
    vector<long long> prices(N);
    for (int i = 0; i < N; i++) {
        cin >> prices[i];
    }

    // เรียงราคาจากน้อยไปมาก
    sort(prices.begin(), prices.end());

    // สร้าง prefix sum เพื่อให้คำนวณผลรวมได้เร็ว
    vector<long long> prefix_sum(N + 1, 0);
    for (int i = 0; i < N; i++) {
        prefix_sum[i + 1] = prefix_sum[i] + prices[i];
    }

    // อ่านและตอบคำถาม
    for (int q = 0; q < Q; q++) {
        long long X, Y;
        cin >> X >> Y;

        // หาตำแหน่งแรกที่ราคา >= Y
        int left = 0;
        while (left < N && prices[left] < Y) {
            left++;
        }

        // จำนวนสินค้าที่เหลือหลังกรอง Y
        int remaining = N - left;
        int max_items = 0;

        // คำนวณจำนวนสินค้าสูงสุดที่ซื้อได้
        for (int i = left; i < N; i++) {
            if (prefix_sum[i + 1] - prefix_sum[left] <= X) {
                max_items = i - left + 1;
            } else {
                break;
            }
        }

        cout << max_items << "\n";
    }

    return 0;
}