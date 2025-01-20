#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int long long n, r, min = 1e9 + 1 , count = 0;
    int long long total[100001] ;
    cin >> n >> r;
    for(int long long i = 0; i<n; i++){
        cin >> total[i];
        if (total[i] < min)
        {
            min = total[i];
        }
    }
    for(int long long j = 0; j<n ; j++){
        if ((r-1) *total[j] < r * min){
            count++;
        }
    }
    cout << count;
    return 0;
}