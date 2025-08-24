#include <iostream>
#include <vector>
#include <list>
using namespace std;


int main() {
    int n;
    vector<list<int>> train(100001);
    cin >> n;
    for (int idx = 0; idx<n; idx++) {
        char c;
        int x,i,j;
        cin >> c >> x >> i;
        switch (c)
        {
        case 'N':
            train[i].push_back(x);
            break;
        case 'M':
            // train[i].insert(train[i].end(), train[x].begin(), train[x].end());
            train[i].splice(train[i].end(), train[x]);
            train[x].clear();
            break;
        default:
            break;
        }
    }
    for (int i = 0; i < train.size(); i++) {
        for (int x : train[i]) {
            cout << x << endl;
        }
    }

    return 0;
}
