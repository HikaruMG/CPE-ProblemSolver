#include <iostream>
using namespace std;

void one(int n){
    int next = n;
    int now = n;
    for (int i = 0; i < n; i++)
    {
        cin >> now;
        if ((next - now) == 1)
        {
            cout << 0 << "\n";
        }
        else
        {
            cout << 1 << "\n";
        }
        next = now;
    }
}

void two(int n)
{
    int next = n;
    int now = n;
    int y1;
    for (int i = 0; i < n; i++)
    {
        cin >> now;
        if (i == 0)
        {           
            y1 = now; 
            if (y1 < n)
            {
                cout << 0 << "\n";
            }
            else
            {
                cout << 1 << "\n";
            }
            continue;
        }
        if (now == 2*y1 + (y1+1) ){
            cout << 1 << "\n";
            y1++;
        }
        else
        {
            cout << 0 << "\n";
            y1--;
        }
        next = now;
    }
}

int main()
{
    int n, select, now, next;
    cin >> n >> select;
    if (select == 1){
        one(n);        
    }
    else if(select == 2)
    {
        two(n);
    }
    return 0;
}