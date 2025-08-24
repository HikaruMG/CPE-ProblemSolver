#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool CheckPair(char a, char b) {
    return (a == 'A' && b == 'U') || (a == 'U' && b == 'A') || (a == 'C' && b == 'G') || (a == 'G' && b == 'C');
}
int Play(string B) {
    int n = B.length();
    int low = 0, high = 0;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int len = 5; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            dp[i][j] = dp[i + 1][j];
            
            for (int k = i + 4; k <= j; k++) { 
                if (CheckPair(B[i], B[k])) {
                    if(k > i + 1){
                        low = dp[i + 1][k - 1];
                    }
                    else{
                        low = 0;
                    }
                    if((k < j)){
                        high = dp[k + 1][j];
                    }
                    else{
                        high = 0;   
                    }
                    dp[i][j] = max(dp[i][j], 1 + low + high);
                }
            }
        }
    }
    return dp[0][n-1];
}
int main() {
    string B;
    cin >> B;
    cout << Play(B) << endl;
    return 0;
}