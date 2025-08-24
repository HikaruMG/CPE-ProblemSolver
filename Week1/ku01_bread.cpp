#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
vector<int> Xpos;
vector<int> Ypos;
vector<int> WID;
vector<int> HEI;
vector<long long> Ares; 
int main() {
    int W, H, M, N;

    cin >> W >> H >> M >> N;
    Xpos.resize(M+1);
    Ypos.resize(N+1);
    Xpos[0] = 0; 
    Ypos[0] = 0;
    for (int i = 1; i <= M; i++) {
        cin >> Xpos[i];
    }
    Xpos.push_back(W); 
    for (int i = 1; i <= N; i++) {
        cin >> Ypos[i];
    }
    Ypos.push_back(H); 
    for (int i = 1; i < Xpos.size(); i++) {
        WID.push_back(Xpos[i] - Xpos[i - 1]);
    }
    for (int i = 1; i < Ypos.size(); i++) {
        HEI.push_back(Ypos[i] - Ypos[i - 1]);
    }
    
    for (int i = 0; i < WID.size(); i++) {
        for (int j = 0; j < HEI.size(); j++) {
            long long area = (long long)WID[i] * HEI[j];
            Ares.push_back(area);
        }
    }
    sort(Ares.begin(), Ares.end(), greater<long long>());
    
    if (Ares.size() >= 2) {
        cout << Ares[0] << " " << Ares[1] << endl;
    } else {
        cout << Ares[0] << endl; 
    }
    return 0;
}