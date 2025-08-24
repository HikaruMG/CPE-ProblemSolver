#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    vector<long long> prices(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> prices[i];
    }

    vector<long long> prefixSum(n+1);
    for (int i = 1; i <= n; i++) {
        prefixSum[i] = prefixSum[i-1] + prices[i];
    }

    for (int i = 0; i < k; i++) {
        long long target;
        cin >> target;
        // long long m;
        // cin >> m;
        // int left = 0, right = n, target = 0;
        int left = 0, right = n, a = 0;
        while (left <= right) 
        {
            int mid = (left + right) / 2;
            if(prefixSum[mid] == target) {
                a = mid;
            }
            else if (prefixSum[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        // while (left <= right) {
        //     int mid = (left + right) / 2;
        //     if (prefixSum[mid] <= m) {
        //         target = mid;
        //         left = mid + 1;
        //     }
        //     else {
        //         right = mid - 1;
        //     }
        // }
        cout << a << endl;
    }
}