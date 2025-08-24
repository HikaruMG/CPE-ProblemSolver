#include <bits/stdc++.h>
using namespace std;
vector<int> Data;
int main() {
    int N;
    cin >> N;
    
    Data.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> Data[i];
        Data[i]--; 
    }
    vector<int> Data_inv(N);
    for(int j = 0; j < N; j++) {
        Data_inv[Data[j]] = j;
    }
    
    vector<int> C(N, 0);
    for(int j = 0; j < N; j++) {
        int k = (j - Data_inv[j] + N) % N;
        C[k]++;
    }
    int max_C = 0;
    for(int k = 0; k < N; k++) {
        if(C[k] > max_C) {
            max_C = C[k];
        }
    }
    cout << max_C << endl;
    return 0;
}