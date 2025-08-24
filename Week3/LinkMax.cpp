#include <iostream>
#include <unordered_map>
#include <stdio.h>
using namespace std;

int main()
{
    pair<int, int> statNlike = {0,0};
    int N;
    unordered_map<long long, int> LikeStatus;
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;

    for(int i = 0; i<N; i++) {
        long long m;
        cin >> m;
        LikeStatus[m]++;
        if (LikeStatus[m] >= statNlike.second){
            
            statNlike.second = LikeStatus[m] ;

            statNlike.first = m;
        }
        cout << statNlike.first << "\n";
    }
}