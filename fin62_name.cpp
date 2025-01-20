#include <iostream>
#include <string>

using namespace std;
/**
 * @brief Counts the number of occurrences of a substring S in a string T
 *
 * @param S The substring to search for
 * @param T The string to search in
 * @return The number of occurrences of S in T
 */
int FindName(const string &S, const string &T) {
    int count = 0; // number of occurrences of S in T
    int Cur_idx = 0; // current index in S
    for (char c : T) { // iterate over each character in T
        if (c == S[Cur_idx]) { // if the current character matches the current
                                // character in S
            Cur_idx++; // move to the next character in S
            if (Cur_idx == S.size()) { // if we've reached the end of S
                count++; // increment the count of occurrences of S
                Cur_idx = 0; // reset the current index in S
            }
        }
    }
    return count;
}

int main() {
    string S, T;
    cin >> S >> T;
    cout << FindName(S, T) << endl;
    return 0;
}
