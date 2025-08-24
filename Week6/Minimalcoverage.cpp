#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Line {
    int left, right;
    bool operator<(const Line& other) const {
        return left < other.left;
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int M;
        bool check = true;
        int CurClove = 0;
        int i = 0;
        vector<Line> Lines;
        vector<Line> ChooseLines;
        cin >> M;
        while (true) {
            int L, R;
            cin >> L >> R;
            if (L == 0 && R == 0){
                 break;
            }
            Lines.push_back({L, R});
        }
        sort(Lines.begin(), Lines.end());



        while (CurClove < M && i < Lines.size()) {
            int RightB = CurClove;
            Line best_line = {0, 0};
            bool found = false;
            while (i < Lines.size() && Lines[i].left <= CurClove) {
                if (Lines[i].right > RightB) {
                    RightB = Lines[i].right;
                    best_line = Lines[i];
                    found = true;
                }
                i++;
            }
            if (!found) {
                check = false;
                break;
            }
            ChooseLines.push_back(best_line);
            CurClove = RightB;
        }
        if (check && CurClove >= M) {
            cout << ChooseLines.size() << endl;
            for (const auto& item : ChooseLines) {
                cout << item.left << " " << item.right << endl;
            }
        } else {
            cout << 0 << endl;
        }
        if (t > 0){
             cout << endl; 
        }
    }
    return 0;
}
