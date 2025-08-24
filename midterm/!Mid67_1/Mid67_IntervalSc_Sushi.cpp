#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    long long S, end;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long N, L;
    cin >> N >> L;
    vector<Interval> InterV;

    for (int i = 0; i < N; ++i) {
        long long A, B;
        cin >> A >> B;
        if (B > L) { 
            cout << -1 << endl;
            return 0;
        }
        long long tmp = L-B;
        InterV.push_back({A-tmp, A+tmp});
    }

    sort(InterV.begin(), InterV.end(), [](const Interval &a, const Interval &b) {
        return a.S < b.S;
    });

    long long C = 0, cov = -1, i = 0;

    while (i < N) {
        if (InterV[i].S > cov) {

            long long best = InterV[i].end;
            while (i < N && InterV[i].S <= cov) {
                best = max(best, InterV[i].end);
                i++;
            }
            cov = best;
            C++;
        } else {
            i++;
        }
    }

    cout << C << endl;
    return 0;
}
