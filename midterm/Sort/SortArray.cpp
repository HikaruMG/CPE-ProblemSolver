#include <iostream>
#include <algorithm> // สำหรับ sort
using namespace std;

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    // เรียงลำดับจากน้อยไปมาก
    sort(arr, arr + n);

    cout << "Sorted Array (ascending): ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // เรียงลำดับจากมากไปน้อย
    sort(arr, arr + n, greater<int>());

    cout << "Sorted Array (descending): ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}