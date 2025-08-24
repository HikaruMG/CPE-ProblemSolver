#include <bits/stdc++.h>
using namespace std;
vector<int> dynamicP;
vector<int> paent;
vector<int> longseq;
int main() {
    int N;
    cin >> N; 
    vector<int> x(N);
    for(int i = 0; i < N; i++) {
        cin >> x[i]; 
    }
    dynamicP.resize(N,1);
    paent.resize(N,-1);
     
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < i; j++) {
            if(x[j] < x[i] && dynamicP[j] + 1 > dynamicP[i]) {
                dynamicP[i] = dynamicP[j] + 1; 
                paent[i] = j; 
            }
        }
    }
    
    auto max_it = max_element(dynamicP.begin(), dynamicP.end()); 
    int Len_max = *max_it; 
    int idx_max = distance(dynamicP.begin(), max_it); 
    
    int Curr = idx_max;
    while(Curr != -1) {
        longseq.push_back(x[Curr]); 
        Curr = paent[Curr]; 
    }
    reverse(longseq.begin(), longseq.end());
    cout << Len_max << endl;
    for(size_t i = 0; i < longseq.size(); i++) {
        cout << longseq[i]; 
        if(i < longseq.size() - 1) cout << " ";
    }
    cout << endl; 
    
    return 0;
}