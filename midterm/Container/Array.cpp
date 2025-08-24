#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    
    int arr[n]; // ขนาดกำหนดจากผู้ใช้ (ใน C++ ควรใช้ vector แทน array ขนาด动态)
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "Array elements: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}