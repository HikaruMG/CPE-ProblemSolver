#include <iostream>
#include <map>
using namespace std;
map<long long, int> TotalLike;
map<pair<long long, int>, long long> L_orders;
long long order = 0; 
int main() {
    int N;
    cin >> N; 

    for (int i = 0; i < N; i++) {
        int votes;
        long long status;
        cin >> votes >> status; 
        if (votes == 1) {
            TotalLike[status]++; 
        } else {
            TotalLike[status]--; 
        }
        L_orders[{status, TotalLike[status]}] = order++; 

        int max_TotalLike = -1;
        long long max_status = -1;
        long long max_order = -1;

        for (auto& i : TotalLike) {
            long long CurStatus = i.first;
            int CurTotleLike = i.second;
            long long CurOrder = L_orders[{CurStatus, CurTotleLike}];

            if (CurTotleLike > max_TotalLike) {
                max_TotalLike = CurTotleLike;
                max_status = CurStatus;
                max_order = CurOrder;
            } else if ((CurTotleLike == max_TotalLike) && (CurOrder > max_order)) {
                max_status = CurStatus;
                max_order = CurOrder;
            }
        }
        cout << max_status << endl;
    }

    return 0;
}