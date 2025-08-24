#include <iostream>
#include <set>
#include <vector>
#include <cmath>   
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    set<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    vector<int> v;
    for (int i = 0; i < m; i++) {
        int y;
        cin >> y;
        auto iterator = s.lower_bound(y);
        int closest = *iterator;
        //lower_bound(first, last, value) ใช้ค้นหาค่าที่ "ไม่ต่ำกว่า" (≥ value)
        //upper_bound(first, last, value) ใช้ค้นหาค่าที่ "มากกว่า" (> value)
        if (iterator != s.begin()) {
            auto prev_iterator = prev(iterator);
            if (abs(*prev_iterator-y)<=abs(closest-y)) {
                closest = *prev_iterator;
            }
        }
        v.push_back(closest);
    }
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
}