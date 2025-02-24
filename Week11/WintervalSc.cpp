#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Schedule
{
int s,e,w,indx;
};

bool compareTime(Schedule a, Schedule b){
    return a.e < b.e;
}

int compatibleCheck(vector<Schedule> &sch, int indx){
    int low = 0, high = indx-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(sch[mid].e <= sch[indx].s){
            if(sch[mid+1].e <= sch[indx].s){
                low = mid+1;
            } else {
                return mid;
            }
        } else {
            high = mid-1;
        }
    }
    return -1;
}


int main() {
    int n;
    cin >> n;
    vector<Schedule> sch(n);
    for(int i = 0; i < n; i++){
        cin >> sch[i].s >> sch[i].e >> sch[i].w;
        sch[i].indx = i+1;
    }
    sort(sch.begin(), sch.end(), compareTime);
    vector<int> weight(n);
    vector<int> prevIndx(n,-1);
    weight[0] = sch[0].w;

    for(int i = 1; i < n; i++){
        int totalWeight = sch[i].w;
        int prev = compatibleCheck(sch, i);
        if (prev != -1){
            totalWeight += weight[prev];
        }
        if(totalWeight > weight[i-1]){
            weight[i] = totalWeight;
            prevIndx[i] = prev;
        } else {
            weight[i] = weight[i-1];
            prevIndx[i] = i-1;
        }
    }
    cout << weight[n-1] << endl;
    vector<int> ans;
    int i = n-1;
    while(i >= 0){
        if(prevIndx[i] == -1 or weight[i] != weight[prevIndx[i]]){
            ans.push_back(sch[i].indx);
            i = compatibleCheck(sch, i);
        }
        else {
            i = prevIndx[i];
        }
    }
    cout << ans.size() << endl;
    for(int i = ans.size()-1; i >= 0; i--){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}