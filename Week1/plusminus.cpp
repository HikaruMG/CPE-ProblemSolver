#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    int N;
    string words;
    cin >> N;
    cin.ignore(); 
    getline(cin, words);

    stringstream splitswords(words);
    int ans, num;
    char oprate;
    splitswords >> ans;

    for (int i = 1; i < N; i++) {
        splitswords >> oprate >> num; 
        if (oprate == '+') {
            ans += num; 
        } else if (oprate == '-') {
            ans -= num; 
        }
    }
    cout << ans << endl;

    return 0;
}