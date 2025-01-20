#include <iostream>
using namespace std;

int main()
{
    int count = 0, n, p[301];
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> p[i];
        for(int j = 0 ; j <i; j++){
            if(p[j] < p[i]){
                count++;
            }
        }
    }
    cout << count;
    return 0;
}