#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;  

    vector<int> Normal(N + 25, 0); 
    int Curr = 0;  
    for (int i = 1; i <= N; i++) {
        Curr -= Normal[i];
        int L;
        cin >> L;

        for (int j = 0; j < L; j++) {
            int a, b;
            cin >> a >> b;
            Curr += a; 
            Normal[i+b] += a;  
        }
        cout << Curr << endl;
    }

    return 0;
}