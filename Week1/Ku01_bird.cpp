#include <iostream>
using namespace std;

int main() {
    int N, C=0;
    int High[1001];
    cin >> N; 
    for (int i = 1; i <= N; i++) {
        cin >> High[i]; 
    }
    for (int i = 1; i <= N; i++) {
        bool val = true; 

        if (i > 1 && High[i] < High[i - 1]) {
            val = false;
        }
        if (i < N && High[i] < High[i + 1]) {
            val = false;
        }
        if (val) {
            C++;
        }
    }
    cout << C << endl; 
    return 0;
}