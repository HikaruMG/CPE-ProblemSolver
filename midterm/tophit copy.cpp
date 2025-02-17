#include <list>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
bool comp(int a, int b) {
    return a > b;
}
bool compare(const pair<int, int>&a, const pair<int, int>&b)
{
   return a.second<b.second;
}
int main() {
    int n,m,l,t;
    int b = 0;
    cin >> n >> m >> l;
    vector<long long> line(n, 0);
    vector<pair<int,int>> score;
    map<int, int> c;
    vector<pair<int,int>> temp;
    for(int i = 0 ; i<n ; i++){
        cin >> t;
        line[i] = t;
    }
    // for(int i = 0; i < line.size(); i++) {
    //             cout << line[i] << endl;
    // }
    for(int i = 0; i<m ; i++){
        c[line[i]] = c[line[i]]+1;
        // cout << i << endl;
        if(i==m-1){
            // cout << i << endl;
            // cout << m << endl;
            if(m<=n){
                // cout << i << endl;
                // cout << m << endl;
                // b = b+1;
                i = b;
                m = m+1;
                // cout << i << endl;
                // cout << m << endl;
                // for(auto it = c.begin(); it != c.end(); it++) {
                //   cout << it->first << " " << it->second << endl;
                // }
                // cout << endl;
                std::map<int,int>::iterator best
                = std::max_element(c.begin(),c.end(),[] (const std::pair<char,int>& a, const std::pair<char,int>& b)->bool{ return a.second < b.second; } );
                // score[b] = best->first;
                score.push_back(make_pair(best->first,best->second));
                // cout << best->first << endl;
                c.clear();
                b = b+1;
                // cout << i << endl;
                // cout << m << endl;
            }
        }
    }
    
    
    // for(int i = 0; i < score.size(); i++) {
    //     cout << score[i] << endl;
    // }

    std::sort(score.begin(), score.end(), [](auto &left, auto &right) {
    return left.second < right.second;
});
    // for(auto it = score.begin(); it != score.end(); it++) {
    //     cout << it->first << " " << it->second << endl;
    // }
    // cout << score.back().first << ' ' << score.back().second;
    for(auto it = score.begin(); it != score.end(); it++) {
        if(it->second <= score.back().second){
            temp.push_back(make_pair(score.front,score.back));
        }
    }
    sort(temp.begin(), temp.end(), [](auto &left, auto &right) {
    return left.second < right.second;
    });
    for(auto it = temp.begin(); it != temp.end(); it++) { 
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}
