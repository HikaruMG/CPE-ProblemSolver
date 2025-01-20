#include <list>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);
    // for(list<int>::iterator it = l.begin(); it != l.end(); it++) {
    //     cout << *it << endl;
    // }
    // for(auto it = l.begin(); it != l.end(); it++) { 
    //     cout << *it << endl;
    // }
    for(int i = 0; i < l.size(); i++) {
        cout << l[i] << endl;
    }
    
    
}