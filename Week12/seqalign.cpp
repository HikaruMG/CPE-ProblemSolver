#include <bits/stdc++.h>
using namespace std;

int main() {
    string word1, word2;
    cin >> word1 >> word2;
    int X = word1.length(); // len of word1
    int Y = word2.length(); // len of word2
    vector<vector<int>> dynamicP(X + 1, vector<int>(Y + 1));

    for (int i = 0; i <= X; i++) {
        dynamicP[i][0] = i; 
    }
    
    for (int j = 0; j <= Y; j++) {
        dynamicP[0][j] = j; 
    }
    
    for (int i = 1; i <= X; i++) {
        for (int j = 1; j <= Y; j++) {
            if (word1[i-1] == word2[j-1]) {
                dynamicP[i][j] = dynamicP[i-1][j-1];
            } else {
                dynamicP[i][j] = min({
                    dynamicP[i-1][j-1]+1, 
                    dynamicP[i-1][j]+1, 
                    dynamicP[i][j-1]+1 
                });
            }
        }
    }
    cout << dynamicP[X][Y] << endl;
    return 0;
}