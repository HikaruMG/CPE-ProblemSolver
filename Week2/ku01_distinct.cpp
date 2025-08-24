#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector<long long> Prices;
set<long long> T;
int main() {
    int N;
    cin >> N; 
    Prices.resize(N); 
    for (int i = 0; i < N; i++) {
        cin >> Prices[i];
    }
    for (int i = 0; i < N; i++) { 
        long long sum = 0; 
        for (int j = i; j < N; j++) { 
            sum += Prices[j]; 
            T.insert(sum); 
        }
    }
    cout << T.size() << endl;

    return 0;
}