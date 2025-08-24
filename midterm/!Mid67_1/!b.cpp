#include <bits/stdc++.h>
using namespace std;
int x;
void sort(vector<vector<int>> &v) {

    // Sort every row one by one
    for (auto &i : v)
        sort(i.begin(), i.end());
}
int main(){
    
    int total;
    int now;
    int l,n,g;
    
    cin >> l >> n >> g;
    vector<vector<int>> food(n);
    for(int i = 0 ; i<l;i++){
        for(int j=0; j<n;j++ ){
            cin >> x;
            food[i].push_back(x);
        }
    }
    sort(food);

    for(int j=0; j<n;j++){
        for(int i; i<n;i++){
            if(total <= g){
                total += food[i][j];
                now +=1;
            }
        }
    }

    cout<<now<<endl;
    
    

}