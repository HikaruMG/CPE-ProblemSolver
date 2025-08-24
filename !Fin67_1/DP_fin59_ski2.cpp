#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int main() {
    int N, K;
    long long ans = 0;
    cin >> N >> K;
    vector<long long> H(N), S(N);
    for(int i = 0; i < N; i++) {
        cin >> H[i] >> S[i];
    }

    vector<long long> dynamicP(N);
    for(int i = 0; i < N; i++) {
        dynamicP[i] = S[i];
    }
    
    for(int i = N-2; i >= 0; i--) {
        for(int j = i+1; j < N; j++) {
            if(H[i] >= H[j] && H[i]-H[j] <= K) {
                dynamicP[i] = max(dynamicP[i],S[i]+dynamicP[j]);
            }
        }
    }
    for(int i = 0; i < N; i++) {
        ans = max(ans, dynamicP[i]);
    }
    cout << ans << endl;
    
    return 0;
}