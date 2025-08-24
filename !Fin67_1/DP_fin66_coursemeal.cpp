#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<ll> X(N+1), Y(N+1), Z(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> X[i] >> Y[i] >> Z[i];
    }
    vector<ll> dynamicP(N+5, 0); 
    
    for (int i = N; i >= 1; i--) {
        ll CH1 = X[i] + dynamicP[i+1]; 
        ll CH2 = (i+1 <= N) ? Y[i] + dynamicP[i+2] : Y[i];
        ll CH3 = (i+3 <= N) ? Z[i] + dynamicP[i+4] : Z[i];
        ll CH4 = dynamicP[i+1]; 

        dynamicP[i] = max({CH1, CH2, CH3, CH4});
    }
    
    cout << dynamicP[1] << endl;
    return 0;
}