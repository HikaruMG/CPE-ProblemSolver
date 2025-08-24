#include <iostream>
#include <vector>
using namespace std;
vector<int> ItemPrice;


int main(){
    int N,T=0;
    cin >> N;
    ItemPrice.resize(N);
    for (int i = 0; i < N; i++){
        cin >> ItemPrice[i];
        T += ItemPrice[i];
    }
    int SumMax = T / 2;
    vector<vector<bool>> dynamicP(SumMax + 1, vector<bool>(SumMax + 1, false));
    dynamicP[0][0] = true;
    for (int i = 0; i < N; i++){
        int p = ItemPrice[i];
        vector<vector<bool>> newdynamicP = dynamicP;
        for (int a = SumMax; a>=0; a--){
            for (int b = SumMax; b>=0; b--){
                if (dynamicP[a][b]){
                    if(a + p <= SumMax){
                        newdynamicP[a + p][b] = true;
                    }
                    if(b + p <= SumMax){
                        newdynamicP[a][b + p] = true;
                    }
                }
            }
        }
        dynamicP = newdynamicP;
    }
    int ans = 0;
    for (int s = SumMax; s>=0; s--){
        if (dynamicP[s][s]){
            ans = s;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}