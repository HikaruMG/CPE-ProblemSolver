#include <iostream>
#include <algorithm>
#include <map>
int main() {
    std::map<int,int> x = { { 1,1 },{ 2,2 },{3,9} };
    std::map<int,int>::iterator best
        = std::max_element(x.begin(),x.end(),[] (const std::pair<char,int>& a, const std::pair<char,int>& b)->bool{ return a.second < b.second; } );
    std::cout << best->first << " , " << best->second << "\n";
}