#include <iostream>
#include <vector>
using namespace std;
vector<pair<long long, long long>> verch;
int main() {
    int N, notsell = 0;
    long long verch_Max = 0; 
    cin >> N; 
    verch.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> verch[i].first >> verch[i].second; // เก็บ Pi และ Vi
    }

    for (int i = N - 1; i >= 0; i--) {
        long long Pi = verch[i].first; 
        long long Vi = verch[i].second;
        if (Vi < verch_Max) {
            notsell++;
        }
        verch_Max = max(verch_Max, Vi);
    }

    cout << notsell << endl; 
    return 0;
}