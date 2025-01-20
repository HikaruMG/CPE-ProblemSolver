#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, k , t,i=1, total[200001] = {0};
    int count = 0;
    cin >> n >> k >> t;
    total[t] = -1;
    while(1){
        if (total[i] == 0)
        {
            total[i]++;
            count++;
            i = (i+k) % n;
        }
        else if (total[i] < 0)
        {
            cout << count+1;
            break;
        }
        else
        {
            cout << count;
            break;
        }
    }
    return 0;
}