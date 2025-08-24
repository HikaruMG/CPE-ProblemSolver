#include <iostream>
#include <deque>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main() {
    int n,m;
    int miss = 0;
    deque<int> cache;
    unordered_set<int> cacheSet;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int web;
        cin >> web;
        if (cacheSet.find(web) != cacheSet.end()) {
            continue;
        }
        miss++;
        if (cache.size() == n) {
            int x = cache.front();
            cache.pop_front();
            cacheSet.erase(x);
        }
        cache.push_back(web);
        cacheSet.insert(web);
    }
    //     if(find(cache.begin(), cache.end(), web) != cache.end()) {
            
    //         // for (int x : cache) {
    //         //     cout << x << " ";
    //         // }
    //         // cout << endl;
    //         continue;
    //     } else {
    //         miss++;
    //         if(cache.size() == n) {
    //             cache.pop_front();
    //         }
    //         cache.push_back(web);

    //         // for (int x : cache) {
    //         //     cout << x << " ";
    //         // }
    //         // cout << endl;
    //     }
    // } 
    cout << miss << endl;    
}