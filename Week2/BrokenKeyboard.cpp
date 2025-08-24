#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
   string word;
    list<char> text;
    while (getline(cin, word))
    {
        auto cursor = text.begin();
        for (char c : word)
        {
            if (c == '[')
            {
                cursor = text.begin();
            }
            else if (c == ']')
            {
                cursor = text.end();
            }
            else
            {
                cursor = text.insert(cursor, c);
                cursor++;
            }
        }
        for (char c : text)
        {
            cout << c;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
        }
        cout << '\n';
        text.clear();
    }
    return 0;
}
