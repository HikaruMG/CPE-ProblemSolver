#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec;
    int n, value;
    
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++) {
        cin >> value;
        vec.push_back(value);
    }
    
    cout << "Vector elements: ";
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
    
    return 0;
}