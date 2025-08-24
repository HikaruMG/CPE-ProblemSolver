#include <iostream>
using namespace std;

int main() {
    int L, H, R,PIC[100][100],GBlurr[100][100];
    cin >> L >> H >> R;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < L; j++) {
            cin >> PIC[i][j];
        }
    }
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < L; x++) {
            int Total = 0,count = 0;  
            for (int dy = -R; dy <= R; dy++) {
                for (int dx = -R; dx <= R; dx++) {
                    int ny = y + dy; 
                    int nx = x + dx; 
                    if (abs(dx) + abs(dy) <= R && ny >= 0 && ny < H && nx >= 0 && nx < L) {
                        Total += PIC[ny][nx];
                        count++;
                    }
                }
            }
            GBlurr[y][x] = Total / count;
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < L; j++) {
            cout << GBlurr[i][j];
            if (j < L - 1) cout << " "; 
        }
        cout << endl;
    }

    return 0;
}