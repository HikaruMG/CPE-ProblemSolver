#include <iostream>
#include <list>
using namespace std;
void show(list<int> l)
{
    for (int val : l)
    {
        cout << val << endl;
    }
}

// Include necessary header files
#include <iostream>
#include <list> // For using the list container
using namespace std;

// Function to display the contents of a list
void show(list<int> l) {
    for (int val : l) {
        cout << val << endl;
    }
}

int main() {
    int n, value; // Variables to store the number of operations and the value to be manipulated
    string sel; // Variable to store the type of operation
    list<int> temp; // List to perform operations on

    // Read the number of operations to be performed
    cin >> n;
    for (int i = 0; i < n; i++) {
        // Read the operation type
        cin >> sel;
        if (sel == "ri") { // If the operation is "ri" (right insert)
            cin >> value; // Read the value to be inserted
            temp.push_back(value); // Insert value at the end of the list
        }
        else if (sel == "li") { // If the operation is "li" (left insert)
            cin >> value; // Read the value to be inserted
            temp.push_front(value); // Insert value at the beginning of the list
        }
        else if (sel == "rr") { // If the operation is "rr" (rotate right)
            if(temp.empty()) { // Check if the list is empty
                continue; // If empty, skip the operation
            }
            else {
                int last = temp.back(); // Get the last element
                temp.pop_back(); // Remove the last element
                temp.push_front(last); // Insert it at the beginning
            }   
        }
        else if (sel == "lr") { // If the operation is "lr" (rotate left)
            if(temp.empty()) { // Check if the list is empty
                continue; // If empty, skip the operation
            }
            else {
                int first = temp.front(); // Get the first element
                temp.pop_front(); // Remove the first element
                temp.push_back(first); // Insert it at the end
            }
        }
    }

    show(temp); // Display the final state of the list
    return 0; // Return 0 to indicate successful completion
}
