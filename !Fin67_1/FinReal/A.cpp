#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    int N,x;
    int twotime = 0;
    int threetime = 0;
    bool check2 = false;
    bool check3 = false;
    cin >> N;
    vector<int> score(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> x;
        score.push_back(x);
    }

    for (int i = 1; i<N; i++) {
        check2 = false;
        check3 = false;
        for(int j = i+1; j <= N; j++){
            if (score[j] >= 3*score[i]) {
                threetime++;
                check3 = true;
                break;
            }
            else if (score[j] >= 2*score[i]) {
                check2 = true;
            }
        }
        if (check2 == true and check3 == false) {
           twotime++;
        }
        
    }
    cout << threetime << " " << twotime << endl;
}