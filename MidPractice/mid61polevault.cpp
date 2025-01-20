#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<int> lengths(n);
    for (int i = 0; i < n; i++) {
        cin >> lengths[i];
    }
    
    vector<int> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i];
    }
    
    set<int> possibleLengths;
    possibleLengths.insert(0);
    
    for (int length : lengths) {
        set<int> newLengths = possibleLengths;
        for (int currentLength : possibleLengths) {
            newLengths.insert(currentLength + length);
        }
        possibleLengths = newLengths;
    }
    
    for (int query : queries) {
        if (possibleLengths.count(query)) {
            cout << "Y";
        } else {
            cout << "N";
        }
    }
    
    cout << endl;
    
    return 0;
}
