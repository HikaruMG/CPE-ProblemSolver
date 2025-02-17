#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void processDeck(int n) {
    queue<int> deck;
    vector<int> discarded;
    
    // Initialize the deck
    for (int i = 1; i <= n; i++) {
        deck.push(i);
    }
    
    // Perform the operations until one card remains
    while (deck.size() > 1) {
        // Discard the top card
        discarded.push_back(deck.front());
        deck.pop();
        
        // Move the next card to the bottom
        int topCard = deck.front();
        deck.pop();
        deck.push(topCard);
    }
    
    // Output the results
    if (!discarded.empty()) {
        cout << "Discarded cards: ";
        for (int i = 0; i < discarded.size(); i++) {
            cout << discarded[i];
            if (i < discarded.size() - 1) cout << ", ";
        }
        cout << endl;
    } else {
        cout << "Discarded cards: " << endl;
    }
    
    cout << "Remaining card: " << deck.front() << endl;
}

int main() {
    int n;
    
    while (true) {
        cin >> n;
        if (n == 0) break;
        processDeck(n);
    }
    
    return 0;
}
