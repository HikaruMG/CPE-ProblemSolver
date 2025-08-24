#include <iostream>
using namespace std;

int main() {
    int R, C, B, T;
    cin >> R >> C >> B >> T;
    int maps[10][10];
    int Total = 0; 
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> maps[i][j];
            Total += maps[i][j];
        }
    }
    
    int water = 0,CountWater = 0,AnimalFeedWater = 0;
    CountWater++;
    water = B;
    
    for(int i = 0; i < R; i++) {
        bool AnimalRow = false;

        for(int j = 0; j < C; j++) {
            if(maps[i][j] > 0) {
                AnimalRow = true;
                break;
            }
        }
    
        if(!AnimalRow) {
            continue; 
        }
        for(int j = 0; j < C; j++) {
            while(maps[i][j] > 0) {
                if(water < T) { 
                    CountWater++;
                    water = B;
                }
                water -= T; 
                maps[i][j]--; 
                AnimalFeedWater++; 
            }
        }

        if(AnimalFeedWater < Total) {
            CountWater++;
            water = B;
        }
    }
    
    cout << CountWater << endl;
    return 0;
}