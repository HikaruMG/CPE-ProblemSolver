#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    
    ll Sums = 0;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    for(int i = 1; i < N; i++) {
        Sums += abs(A[i] - A[i-1]);
    }
    ll min_sum = Sums;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(abs(i - j) <= 1) {
                continue; 
            }
            vector<ll> Tmp = A;
            Tmp[i] = A[j]; 
            
            ll New_sum = 0;
            for(int k = 1; k < N; k++) {
                New_sum += abs(Tmp[k]-Tmp[k-1]);
            }
            
            min_sum = min(min_sum, New_sum);
        }
    }
    cout << min_sum << endl;
    return 0;
}