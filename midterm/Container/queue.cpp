#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    int n, value;
    
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++) {
        cin >> value;
        q.push(value);
    }
    
    cout << "Queue elements: ";
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    
    return 0;
}