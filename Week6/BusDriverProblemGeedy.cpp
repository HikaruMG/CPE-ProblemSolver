#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    while (true) {
        int n, d, r;
        cin >> n >> d >> r;
        
        if (n == 0 && d == 0 && r == 0) {
            break;
        }
        vector<int> AM(n);  
        vector<int> PM(n);
        
        for (int i = 0; i < n; i++) {
            cin >> AM[i];
        }
        
        for (int i = 0; i < n; i++) {
            cin >> PM[i];
        }
        
        sort(AM.begin(), AM.end());                    
        sort(PM.begin(), PM.end(), greater<int>());    
        
        long long OT = 0;
        for (int i = 0; i < n; i++) {
            int totalRoute = AM[i] + PM[i];
            if (totalRoute > d) {
                OT += (long long)(totalRoute - d) * r;  
            }
        }
        cout << OT << endl;
    }
    
    return 0;
}