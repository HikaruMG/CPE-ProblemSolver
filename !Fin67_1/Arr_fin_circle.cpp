#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;
vector<long long> Data;
vector<long long> Data_Ex2;
int main() {
    int N, H,seen_Max = 0;
    cin >> N >> H;
    Data.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> Data[i];
    }
    Data_Ex2.resize(2*N);
    for (int i = 0; i < N; i++) {
        Data_Ex2[i] = Data[i];
        Data_Ex2[i+N] = Data[i];
    }
    
    
    for (int S = 0; S < N; S++) {
        long long Cur_Helth = H; 
        int scenes = 0;

        for (int i = S; i < S + N; i++) {
            if (Cur_Helth >= Data_Ex2[i]) {
                Cur_Helth -= Data_Ex2[i];
                scenes++;
            } else {
                break; 
            }
        }
        seen_Max = max(seen_Max, min(scenes, N));
    }

    cout << seen_Max << endl;
    
    return 0;
}