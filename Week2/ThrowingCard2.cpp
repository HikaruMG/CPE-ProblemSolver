#include <iostream>
#include <vector>
#include <deque>
using namespace std;

void Play(int n) {
    if (n == 1) { // กรณี n=1 ต้องพิมพ์แยก
        cout << "Discarded cards:" << endl;
        cout << "Remaining card: 1" << endl;
        return;
    }

    deque<int> Card;
    vector<int> discardDeck;
    
    for (int i = 1; i <= n; i++) {
        Card.push_back(i);
    }

    while (Card.size() > 1) {
        discardDeck.push_back(Card.front());
        Card.pop_front();

        int front = Card.front();
        Card.pop_front();
        Card.push_back(front);
    }

    cout << "Discarded cards:";
    for (size_t i = 0; i < discardDeck.size(); i++) {
        if (i > 0) cout << ", ";
        cout << discardDeck[i];
    }
    cout << endl;
    
    cout << "Remaining card: " << Card.front() << endl;
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        Play(n);
    }
    return 0;
}
