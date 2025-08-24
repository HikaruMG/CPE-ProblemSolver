#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> ItemPrice;
vector<int> W;
vector<int> maxW;
int knapsack(int MW, vector<int>& ItemPrice, vector<int>& W, int N) {
    vector<vector<int>> dynamicP(N + 1, vector<int>(MW + 1, 0));
    for (int i = 1; i <= N; i++) {
        for (int w = 0; w <= MW; w++) {
            dynamicP[i][w] = dynamicP[i-1][w];
            if (w >= W[i-1]) {
                dynamicP[i][w] = max(dynamicP[i][w], dynamicP[i-1][w-W[i-1]]+ItemPrice[i-1]);
            }
        }
    }
    return dynamicP[N][MW];
}

int main() {
    int T;
    cin >> T; 
    for (int t = 0; t < T; t++) {
        int N;
        cin >> N; 
        ItemPrice.resize(N);
        W.resize(N);
        for (int i = 0; i<N; i++) {
            cin >> ItemPrice[i] >> W[i];
        }
        int G;
        cin >> G; 
        maxW.resize(G);
        for (int i = 0; i < G; i++) {
            cin >> maxW[i];
        }
        long long totalValue = 0;
        for (int i = 0; i < G; i++) {
            totalValue += knapsack(maxW[i], ItemPrice, W, N);
        }
        cout << totalValue << endl;
    }
    
    return 0;
}