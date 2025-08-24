#include <iostream>
#include <vector>
#include <climits>
using namespace std;
struct paper {
    long long C;
    long long P;
    long long W;
};
int main() {
    int K, N;
    cin >> K >> N;
    vector<paper> papers(K);
    vector<long long> Boxed(N);
    
    for (int i = 0; i < K; i++) {
        cin >> papers[i].C >> papers[i].P >> papers[i].W;
    }
    for (int i = 0; i < N; i++) {
        cin >> Boxed[i];
    }
    long long lowestC = LLONG_MAX; 
    for (int i = 0; i < K; i++) {
        long long CurW = 0;
        long long Capa = papers[i].W;
        int shipping = 1;
        bool used = true;
        for (int j = 0; j < Boxed.size(); j++) { 
            if (Boxed[j] > Capa) {
                used = false; 
                break; 
            } 
            if (CurW + Boxed[j] <= Capa) {
                CurW += Boxed[j]; 
            } else {
                shipping++; 
                CurW = Boxed[j]; 
            }
        }
        if (used) { 
            long long cost = papers[i].C + (shipping * papers[i].P);
            lowestC = min(lowestC, cost);
        }
    }
    cout << lowestC << endl;
    return 0;
}