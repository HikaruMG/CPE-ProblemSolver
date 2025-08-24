#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M,weeks = 0;
    cin >> N >> M;
    multiset<long long> B;
    vector<long long> WeeksDemands(M);
    for (int i = 0; i < N; i++) {
        long long x;
        cin >> x;
        B.insert(x);
    }
    for (int i = 0; i < M; i++) {
        cin >> WeeksDemands[i];
    }

    for (int j = 0; j < M; j++) {
        long long y = WeeksDemands[j]; 
        auto it = B.lower_bound(y);
        if (it == B.end()) {
            break;
        }
        B.erase(it);
        weeks++;
    }
    cout << weeks << endl;
    return 0;
}