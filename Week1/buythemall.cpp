#include <iostream>
using namespace std;

int main() {
    int P1, P2, P3, N;
    cin >> P1 >> P2 >> P3;
    cin >> N;
    int collection[4] = {0};
    for (int j = 1; j <= N; j++) {
        int x;
        cin >> x;
        collection[x]++;
    }

    long long cost1 = (long long)collection[1] * P1; 
    long long cost2 = (long long)collection[2] * P2;
    long long cost3 = (long long)collection[3] * P3;

    long long min_cost = cost1;
    if (cost2 < min_cost) min_cost = cost2;
    if (cost3 < min_cost) min_cost = cost3;
    cout << min_cost << endl;

    return 0;
}