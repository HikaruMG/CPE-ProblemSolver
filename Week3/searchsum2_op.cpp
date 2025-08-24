#include <iostream>
#include <vector>
using namespace std;
vector<long long> price;
vector<long long> prx_sum;
int main() {
    int N, K;
    cin >> N >> K;
    price.resize(N + 1); 

    for (int i = 1; i <= N; i++) {
        cin >> price[i];
    }


    prx_sum.resize(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        prx_sum[i] = prx_sum[i - 1] + price[i];
    }

    for (int j = 0; j < K; j++) {
        long long M;
        cin >> M;

        int M_book = 0; 
        for (int S = 1; S <= N; S++) {
            for (int E = S; E <= N; E++) {
                long long cost = prx_sum[E] - prx_sum[S - 1];
                if (cost <= M) {
                    int totalBook = E-S + 1;
                    M_book = max(M_book, totalBook);
                } else {
                    break; 
                }
            }
        }
        cout << M_book << endl;
    }

    return 0;
}