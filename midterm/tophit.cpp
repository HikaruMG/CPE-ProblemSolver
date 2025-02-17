#include <list>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
bool compare(const pair<int, int>&a, const pair<int, int>&b)
{
   return a.second<b.second;
}
int main() {
    int n,m,l;
    cin >> n >> m >> l;
    vector<long long> line(m + 1, 0);
    vector<long long> score(n + 1, 0);
    map<int, int> c;
    for (int i = 0; i < n/2 ; ++i) {
        int t;
        if(i < m){
            cin >> t;
            c[t] = c[t]+1;
            continue;
        }
        std::map<int,int>::iterator best
        = std::max_element(c.begin(),c.end(),[] (const std::pair<char,int>& a, const std::pair<char,int>& b)->bool{ return a.second < b.second; } );
        score[i] = best->first;
        i = 0;
    }
    // for(int i = 0; i < score.size(); i++) {
    //             cout << score[i] << endl;
    // }
    // for(auto it = c.begin(); it != c.end(); it++) {
    //     cout << it->first << " " << it->second << endl;
    // }
    // maxn = max_element(c.begin(), c.end(), compare)->second;
    // cout<<maxn->first<<endl;
    for(auto it = l.begin(); it != l.end(); it++) { 
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}
