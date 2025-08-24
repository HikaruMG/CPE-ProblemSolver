#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> C, B;
int main() {
    int N;
    cin >> N;
    C.resize(N+1), B.resize(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> C[i] >> B[i];
    }
    vector<vector<ll>> dynamicP(N+1, vector<ll>(3, 0));

    dynamicP[1][0] = 0;          
    dynamicP[1][1] = C[1];       
    dynamicP[1][2] = B[1];     


    for (int i = 2; i <= N; i++) {
        dynamicP[i][0] = max({dynamicP[i-1][0], dynamicP[i-1][1], dynamicP[i-1][2]});
        dynamicP[i][1] = C[i] + max(dynamicP[i-1][0], dynamicP[i-1][2]);
        dynamicP[i][2] = B[i] + max(dynamicP[i-1][0], dynamicP[i-1][1]);
    }

    ll Profi_Max = max({dynamicP[N][0], dynamicP[N][1], dynamicP[N][2]});
    if (Profi_Max < 0) Profi_Max = 0;
    cout << Profi_Max << endl;

    return 0;
}