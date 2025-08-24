#include <iostream>
#include <vector>
#include <climits>
using namespace std;
vector<int> Cut;
int main() {
    while (true) {
        int Len,n;
        cin >> Len >> n;
        if (Len == 0) {
            break;
        }
        Cut.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> Cut[i];
        }
        vector<int> Loc = Cut;
        Loc.insert(Loc.begin(), 0);
        Loc.push_back(Len);
        int size = Loc.size();
        
        // dp[i][j] = minimum cost to cut i to j
        vector<vector<int>> dp(size, vector<int>(size, 0));
        for (int l = 2; l < size; l++) {
            // i start
            for (int i = 0; i < size - l; i++) {
                // j ending
                int j = i+l;
                dp[i][j] = INT_MAX;
                // k in between
                for (int k = i + 1; k < j; k++) {
                    int cost = dp[i][k]+dp[k][j] + (Loc[j]-Loc[i]);
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }
        cout << "The minimum cutting is " << dp[0][size - 1] << "." << endl;
    }
    
    return 0;
}