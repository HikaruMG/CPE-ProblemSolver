#include <iostream>
using namespace std;

int main() {
    int N, M, K, FoodNeeded = 0;
    long long BeforeFood = 0, eat; 
    cin >> N >> M >> K;
    int TotalFood[1001];
    for (int i = 0; i < N; i++) {
        cin >> TotalFood[i];
    }

    for (int i = 0; i < N; i++) {
        BeforeFood += TotalFood[i]; 
        if (BeforeFood < M) { 
            cout << -1 << endl;
            return 0;
        }
        
        if (BeforeFood >= K) { 
            eat = K; 
        } else { 
            eat = BeforeFood; 
            FoodNeeded++; 
        }
        BeforeFood -= eat; 
    }
    cout << FoodNeeded << endl; 
    return 0;
}