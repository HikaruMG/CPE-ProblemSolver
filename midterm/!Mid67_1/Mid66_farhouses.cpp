#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int N, K, L;
    long long Max_dists = 0;
    cin >> N >> K >> L;
    vector<long long> Data(N);
    for(int i = 0; i < N; i++) {
        cin >> Data[i];
    }
    sort(Data.begin(), Data.end());
    for(int i = 0; i <= N - (K + L) - 1; i++) {
        long long Dist = Data[i+K+L]-Data[i];
        if(Dist > Max_dists) {
            Max_dists = Dist;
        }
    }
    cout << Max_dists << endl;

    return 0;
}