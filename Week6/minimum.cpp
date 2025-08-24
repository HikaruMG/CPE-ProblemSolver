#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Line {
    int left, right;
};


int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int M;
        cin >> M;
        vector<Line> Lines;
        int Li, Ri;
        while (cin >> Li >> Ri, !(Li == 0 && Ri == 0)) {
            Lines.emplace_back(Li, Ri);
        }
        vector<Line> result;
        int current_coverage = 0;
        int best_right = 0;
        int i = 0;
        while (current_coverage < M) {
            best_right = current_coverage; 
            int best_idx = -1;

            for (int j = 0; j < Lines.size(); j++) {
                if (Lines[j].left <= current_coverage && Lines[j].right > best_right) {
                    best_right = Lines[j].right;
                    best_idx = j;
                }
            }
            
 
            if (best_idx == -1) {
                result.clear(); 
                break;
            }

            result.emplace_back(Lines[best_idx].left, Lines[best_idx].right);
            current_coverage = best_right; 
        }
        
        
        if (current_coverage < M) {
            cout << "0\n";
        } else {
            
            sort(result.begin(), result.end(), [](Line a, Line b) {
                return a.left < b.left;
            });
            
            
            cout << result.size() << "\n";
            for (auto seg : result) {
                cout << seg.left << " " << seg.right << "\n";
            }
        }
        
       
        if (t < T - 1) cout << "\n";
    }
    return 0;
}