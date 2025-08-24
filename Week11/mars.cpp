#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int dp[1005][26][26];
string word;
int Route(char Start, char End) {
    int a = Start - 'A'; //แปลงเป็นตัวเลข (A=0, B=1, ..., Z=25) ASCII
    int b = End - 'A';
    int cw = abs(a - b); //ตามเข็มนาฬิกา
    int ccw = 26 - cw; //ทวนเข็มนาฬิกา
    return min(cw, ccw);
}

int Play(int i, int left, int right) {
    if (i >= word.length()) {
        return 0;
    } // Base Case

    if (dp[i][left][right] != -1) {
        return dp[i][left][right];
    }
    char pos = word[i]; 
    int Change_left = Route(left + 'A', pos);
    int Change_right = Route(right + 'A', pos);

    // USe left 
    int left_cost = Change_left + Play(i+1, pos-'A', right);
    
    // Use right to move
    int right_cost = Change_right + Play(i+1, left, pos-'A');
    return dp[i][left][right] = min(left_cost, right_cost); //เอาค่าต่ำสุด
}


int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> word;
        memset(dp, -1, sizeof(dp));
        // เริ่มต้นที่ตำแหน่ง 0, วงล้อซ้าย = 'A'(0), วงล้อขวา = 'A'(0)
        int ans = Play(0, 0, 0);
        cout << ans << "\n";
    }
    return 0;
}