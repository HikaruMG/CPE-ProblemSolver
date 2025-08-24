#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> Height;

long long play(int N, int H, int Ta, int Td, vector<int>& Height) {
    long long total = 0;
    vector<bool> Isused(N, false);
    int r = N - 1;
    for (int i = 0; i < N; i++) {
        if (Isused[i]) continue;
        while (r > i && (Height[i] + Height[r] >= H || Isused[r])) {
            r--;
        }
        if (r > i && Height[i]+Height[r] < H && !Isused[r] && 2*Ta>Td) {
            total += Td;
            Isused[r] = Isused[i] = true;
        } else {
            total += Ta;
            Isused[i] = true;
        }
    }
    return total;
}
int main() {
    int C; 
    cin >> C;
    
    for (int i = 1; i <= C; ++i) {
        int Ta, Td,N,H;
        cin >> N >> H >> Ta >> Td;
        Height.resize(N);

        for (int k = 0; k < N; ++k) {
            cin >> Height[k];
        }
        sort(Height.begin(), Height.end());
        long long total = play(N, H, Ta, Td, Height); 
        cout << "Case " << i << ": " << total << endl;
    }
    
    return 0;
}
