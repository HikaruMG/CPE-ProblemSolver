#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void Play(int n) {
    
    deque<int> Card;
    vector<int> discardDeck;

    if (n == 1) {
        cout << "Discarded cards:" << endl;
        cout << "Remaining card: 1" << endl;
        return;
    }

    for(int i = 1; i <= n; i++) {
        Card.push_back(i);
    }

    while(Card.size() > 1) {
        discardDeck.push_back(Card.front());
        Card.pop_front();

        int front = Card.front();
        Card.pop_front();
        Card.push_back(front);
    }

    cout << "Discarded cards:";
    if(!discardDeck.empty()) {
        cout << " ";
        for(int i = 0; i < discardDeck.size(); i++) {
            cout << discardDeck[i];
            if(i < discardDeck.size()-1) {
                cout << ", ";
            }
        }
    }
    cout << endl;
    
    cout << "Remaining card: " << Card.front() << endl;
    // queue<int> card;
    // vector<int> discardDeck;

    // for (int i = 1; i <= n; i++) {
    //     card.push(i);
    // }

    // while (card.size() > 1) {
    //     discardDeck.push_back(card.front());
    //     card.pop();
    //     int T = card.front();
    //     card.pop();
    //     card.push(T);
    // }

    // cout << "Discarded cards:";
    // if (!discardDeck.empty()) {
    //     cout << " ";  
    //     for (size_t i = 0; i < discardDeck.size(); i++) {
    //         if (i > 0) cout << ", ";
    //         cout << discardDeck[i];
    //     }
    // }
    // cout << endl;
    // cout <<"Remaining card: " << card.front()<<endl;
    
}

int main() {
    int n;
    while (true)
    {
        cin >> n;
        if (n == 0) {
            break;
        }
        Play(n);
    }
    cout << endl;
    return 0;
}