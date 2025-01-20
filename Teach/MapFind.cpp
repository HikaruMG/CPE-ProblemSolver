#include <list>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    map<int, int> m;
    m[1] = 1;
    m[2] = 2;
    m[3] = 3;
    m[4] = 4;
    // for(auto it = m.begin(); it != m.end(); it++) {
    //     cout << it->first << " " << it->second << endl;
    // }

    // auto it = m.find(3);
    // if(it != m.end()) {
    //     cout << it->first << " " << it->second << endl;
    // }

    cout << (m.find(3) != m.end()) ? "true" : "false";
    return 0;
}