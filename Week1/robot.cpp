#include <iostream>
#include <string>
using namespace std;

int main()
{
    int x = 0, y = 0;
    string w;
    cin >> w;
    for(int i = 0 ; i<w.size() ;i++){
        if(w[i] == 'Z'){
            x = 0;
            y = 0;
        }
        else if(w[i] == 'N'){
            y++;
        }
        else if (w[i] == 'S'){
            y--;
        }
        else if (w[i] == 'E'){
            x++;
        }
        else if (w[i] == 'W'){
            x--;
        }
    }
    cout << x << " " << y;

    return 0;
}