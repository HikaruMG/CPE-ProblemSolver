#include <iostream>
#include <vector>
using namespace std;
vector<pair<long long, long long>> home;
int main() {
    int n;
    int wall = 0;
    int i = 0;
    long long l;
    cin >> n >> l;
    home.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> home[i].first >> home[i].second;
    }
    while (i < n) {
        long long wall_i = home[i].first;  
        long long wall_j = wall_i + l;  
        wall++;
        while (i < n && home[i].second <= wall_j) {
            i++;
        }
    }
    cout << wall << endl;
    return 0;
}