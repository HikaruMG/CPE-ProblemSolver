#include <bits/stdc++.h>
using namespace std;
vector<long long> itemsP;
vector<long long> prex_Sums;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, Q;
    cin >> N >> Q;

    itemsP.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> itemsP[i];
    }
    sort(itemsP.begin(), itemsP.end());

    prex_Sums.resize(N + 1, 0);
    for (int i = 0; i < N; i++) {
        prex_Sums[i + 1] = prex_Sums[i] + itemsP[i];
    }

    for (int q = 0; q < Q; q++) {

        long long X, Y;
        cin >> X >> Y;
        int L = 0;
        while (L < N && itemsP[L] < Y) {
            L++;
        }

        int Remains = N - L;
        int items_Max = 0;

        for (int i = L; i < N; i++) {
            if (prex_Sums[i + 1] - prex_Sums[L] <= X) {
                items_Max = i - L + 1;
            } else {
                break;
            }
        }
        cout << items_Max << "\n";
    }

    return 0;
}