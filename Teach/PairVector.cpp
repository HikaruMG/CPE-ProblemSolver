#include <list>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    vector<pair<int,int>> l;
    l.push_back(make_pair(10,20));
    l.push_back(make_pair(105,240));
    l.push_back(make_pair(104,220));

    sort(l.begin(), l.end());
    // for(list<int>::iterator it = l.begin(); it != l.end(); it++) {
    //     cout << *it << endl;
    // }
    // for(auto it = l.begin(); it != l.end(); it++) { 
    //     cout << it->first << " " << it->second << endl;
    // }
    for(int i = 0; i < l.size(); i++) {
        cout << l[i] << endl;
    }
    
    
}