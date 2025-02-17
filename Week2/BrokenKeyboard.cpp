#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    string input;
    
    // Process each test case until EOF
    while (getline(cin, input)) {
        deque<char> home, end;  // Two deques to manage home and end inserts
        bool atHome = true;  // Initially, we're in the home position
        
        // Iterate over each character in the input string
        for (char ch : input) {
            if (ch == '[') {
                atHome = true;  // Switch to home position
            } else if (ch == ']') {
                atHome = false;  // Switch to end position
            } else {
                if (atHome) {
                    home.push_front(ch);  // Insert at the home (beginning)
                } else {
                    end.push_back(ch);  // Insert at the end (after all text)
                }
            }
        }
        
        // Print the result: first print the home deque (in reverse order), then print the end deque
        for (auto it = home.begin(); it != home.end(); ++it) {
            cout << *it;
        }
        for (auto it = end.begin(); it != end.end(); ++it) {
            cout << *it;
        }
        cout << endl;
    }
    
    return 0;
}
