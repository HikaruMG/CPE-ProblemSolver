#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int M;
    cin >> M; 
    vector<int> High(M);
    map<int, int> WoodCoutn; // key = ความยาว, value = จำนวน
    int maxHigh = 0; 
    for (int i = 0; i < M; i++) {
        cin >> High[i];
        if (High[i] > maxHigh) {
            maxHigh = High[i];
        }
    }

    for (int h = 1; h <= maxHigh; h++) {
        int len = 0; 
        for (int i = 0; i < M; i++) {
            if (High[i]>=h) {
                len++; 
            } else {
                if (len > 0) {
                    WoodCoutn[len]++;
                    len=0;
                }
            }
        }
        if (len > 0) {
            WoodCoutn[len]++;
        }
    }

    cout << WoodCoutn.size() << endl;
    for (auto it = WoodCoutn.begin(); it != WoodCoutn.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}