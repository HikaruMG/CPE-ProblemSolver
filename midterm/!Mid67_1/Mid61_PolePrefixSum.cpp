#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    // อ่านความยาวไม้ N ท่อน
    vector<int> L(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> L[i];
    }

    // คำนวณ prefix sum
    vector<long long> prefix_sum(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + L[i];
    }

    // สร้าง set ของผลรวมที่เป็นไปได้
    set<long long> possible_sums;
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j++) {
            long long sum = prefix_sum[j] - prefix_sum[i - 1];
            possible_sums.insert(sum);
        }
    }

    // อ่านคำถาม Q ข้อ
    vector<int> queries(Q);
    for (int i = 0; i < Q; i++) {
        cin >> queries[i];
    }

    // ตอบคำถาม
    for (int i = 0; i < Q; i++) {
        if (possible_sums.count(queries[i]) > 0) {
            cout << "Y";
        } else {
            cout << "N";
        }
        // if (i < Q - 1) cout << " "; // ช่องว่างระหว่างคำตอบ
    }
    cout << endl;

    return 0;
}