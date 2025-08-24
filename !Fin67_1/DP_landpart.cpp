#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<long long> path;
int main() {
    int N;
    cin >> N;
    path.resize(N+1);
    vector<long long> dp(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        cin >> path[i];
    }

    for (int i = 5; i <= N; i++) { 
        long long valueM = 0;
        for (int j = i; j >= 1; j--) {
            valueM = max(valueM, path[j]);
            if (i - j + 1 >= 5) { 
                dp[i] = max(dp[i], dp[j-1] + valueM);
            }
        }
    }
    cout << dp[N] << endl;
    return 0;
}