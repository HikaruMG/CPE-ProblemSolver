#include <iostream>
#include <vector>

using namespace std;

int find(vector<int>& V, int x) {
    if (V[x]!=x) {
        V[x]=find(V,V[x]);
    }
    return V[x];
}

void unionFind(vector<int>& V, vector<int>& Depth, int x, int y) {
    int VectorX = find(V, x);
    int VectorY = find(V, y);
    if (VectorX != VectorY) {
        if (Depth[VectorX] > Depth[VectorY]) {
            V[VectorY] = VectorX;
        } else if (Depth[VectorX] < Depth[VectorY]) {
            V[VectorX] = VectorY;
        } else {
            V[VectorY] = VectorX;
            Depth[VectorX]++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, Q;
    cin >> N >> Q;
    vector<int> V(N + 1);
    vector<int> Depth(N + 1, 0);

    for (int i = 1; i <= N; ++i) {
        V[i] = i;
    }

    for (int i = 0; i < Q; ++i) {
        char type;
        int X, Y;
        cin >> type >> X >> Y;

        if (type == 'c') {
            unionFind(V, Depth, X, Y);
        } else if (type == 'q') {
            if (find(V, X) == find(V, Y)) {
                cout << "yes\n";
            } else {
                cout << "no\n";
            }
        }
    }

    return 0;
}