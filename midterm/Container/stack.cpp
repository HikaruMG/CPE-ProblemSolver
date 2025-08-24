#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    int n, value;
    
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++) {
        cin >> value;
        s.push(value);
    }
    
    cout << "Stack elements: ";
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    
    return 0;
}