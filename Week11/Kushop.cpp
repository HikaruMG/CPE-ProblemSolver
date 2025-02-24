#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<long long> dp(N+1, 0);
    long long price;
    if(N > 0){
        cin >> price;    
        dp[1] = price; 
    }

    for (int i = 2; i <= N; i++){
        cin >> price;
        dp[i] = max(dp[i-1], dp[i-2]+price);
    }
    cout << dp[N] << "\n";
    return 0;
}
