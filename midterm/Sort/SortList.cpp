#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> lst = {5, 2, 9, 1, 5, 6};

    // เรียงลำดับจากน้อยไปมาก
    lst.sort();

    cout << "Sorted Linked List (ascending): ";
    for (int val : lst) {
        cout << val << " ";
    }
    cout << endl;

    // เรียงลำดับจากมากไปน้อย
    lst.sort(greater<int>());

    cout << "Sorted Linked List (descending): ";
    for (int val : lst) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}