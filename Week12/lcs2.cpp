#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    string word1, word2;
    getline(cin,  word1);
    getline(cin, word2);
    int X = word1.size();
    int Y = word2.size();
    vector<vector<int>> dynamicP(X+1, vector<int>(Y+1, 0));
    
    for (int i = 1; i <= X; i++){
        for (int j = 1; j <= Y; j++){
            if (word1[i-1] == word2[j-1])
                dynamicP[i][j] = dynamicP[i-1][j-1] + 1;
            else
                dynamicP[i][j] = max(dynamicP[i-1][j], dynamicP[i][j-1]);
        }
    }
    int Len = dynamicP[X][Y];
    string longcomseq = "";
    int i = X;
    int j = Y;
    while (i > 0 && j > 0) {
        if ( word1[i-1] == word2[j-1]) {
            longcomseq.push_back(word1[i-1]);
            i--; 
            j--;
        } else {
            if (dynamicP[i-1][j]>=dynamicP[i][j-1])
                i--;
            else
                j--;
        }
    }
    reverse(longcomseq.begin(), longcomseq.end());
    cout << Len << "\n" << longcomseq;
    
    return 0;
}