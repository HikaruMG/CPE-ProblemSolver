#include <bits/stdc++.h>
using namespace std;
vector<long long> High;
vector<long long> Maximun;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long N, Q;
    cin >> N >> Q;

    High.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> High[i];
    }

    Maximun.resize(N);
    Maximun[0] = High[0];
    for(int i = 1; i < N; i++) {
        Maximun[i] = min(Maximun[i-1], High[i]);
    }

    for(int i = 0; i < Q; i++) {
        int T;
        cin >> T;
        if(T == 1) {
            int j;
            cin >> j;
            cout << Maximun[j-1] << endl; 
        } else {
            long long k;
            cin >> k;
            auto iter = upper_bound(Maximun.begin(), Maximun.end(), k, greater<long long>());
            int q = iter - Maximun.begin();
            if(q == 0) {
                cout << 0 << endl;
            } else {
                cout << q << endl;
            }
        }
    }
    return 0;
}