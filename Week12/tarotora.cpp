#include <bits/stdc++.h>
using namespace std;

const int MAX_Val = 10000000;
vector<int> A, B;
int main()
{
    int X;
    cin >> X;
    while (X--)
    {
        int n, k;
        cin >> n >> k;
        A.resize(n);
        B.resize(n);
        for (int i = 0; i < n; ++i)
            cin >> A[i] >> B[i];
        vector<int> dynamicP(2 * k + 1, MAX_Val);
        dynamicP[k] = 0;
        for (int i = 0; i < n; ++i)
        {
            vector<int> TmpdynamicP(2 * k + 1, MAX_Val);
            for (int d = 0; d <= 2 * k; ++d)
            {
                if (dynamicP[d] == MAX_Val){
                    continue;
                }

                if (d + 1 <= 2 * k){
                    TmpdynamicP[d + 1] = min(TmpdynamicP[d+1], dynamicP[d]+A[i]);
                }

                if (d - 1 >= 0){
                    TmpdynamicP[d - 1] = min(TmpdynamicP[d-1], dynamicP[d]+B[i]);
                }
            }
            dynamicP = TmpdynamicP;
        }
        int res = MAX_Val;
        for (int ans : dynamicP)
        {
            if (ans < res)
            {
                res = ans;
            }
        }
        cout << res << "\n";
    }
    return 0;
}