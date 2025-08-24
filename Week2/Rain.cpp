#include <iostream>
#include <stack>
using namespace std;

int main() {
    int N;

    while (cin >> N && N != 0) {
        while (1)
        {
            stack<int> station;
            int current = 1;
            int cursor = 0;
            int order[N];
            cin >> order[0];
            if (order[0] == 0) break;

            for (int i = 1; i < N; i++)
            {
                cin >> order[i];
            }

            while (current <= N || !station.empty())
            {
                if (!station.empty() && station.top() == order[cursor])
                {
                    station.pop();
                    cursor++;
                }
                else if (current <= N)
                {
                    station.push(current++);
                }
                else
                {
                    break;
                }
            }

            if (cursor == N)
            {
                cout << "Yes\n";
            }
            else
            {
                cout << "No\n";
            }
        }
        cout << "\n";
    }

    return 0;
}