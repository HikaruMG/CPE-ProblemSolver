#include <iostream>
using namespace std;


int main()
{
    int n, hand[100001], item,max = 0;
    int count = 0;

    cin >> n;
    for(int i = 1; i<=n ;i++){
        cin >> hand[i];
    }

    for(int i = 1; i<=n ;i++){
        if (hand[i] != 0){
            int count = 1;
            item = hand[i];
            hand[i] = 0; 
            
            while (item != i)
            {
                int tmp = item;   
                item = hand[item]; 
                hand[tmp] = 0;    
                count++;
            }
            
            if (count > max)
            {
                max = count;
            }
        }
    }
    cout << max;
    return 0;
}