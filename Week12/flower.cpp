#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
vector<tuple<int, int, int>> FlowerL;  // ดอกไม้กิ่งยาว
    vector<tuple<int, int, int>> FlowerS;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int M, K;
    cin >> M >> K;
    
    //ยาว (T=1) สั้น (T=0)

    // กิ่งสั้น
    for (int i = 0; i < K; i++) {
        int price, beauty, usedto;
        cin >> price >> beauty >> usedto;
        if (usedto == 1)
            FlowerL.push_back({price, beauty, usedto});
        else
            FlowerS.push_back({price, beauty, usedto});
    }
    
    auto computeDP = [&](const vector<tuple<int,int,int>> &flowers) -> vector<vector<int>> {
        int n = flowers.size();
        // สร้างตาราง dynamicP[c][FlowerBuy] โดย c = ค่าใช้จ่าย ตั้งแต่ 0 ถึง M, FlowerBuy = จำนวนดอกไม้ที่ซื้อ (0 ถึง n)
        vector<vector<int>> dynamicP(M+1, vector<int>(n+1, -1)); 
        dynamicP[0][0] = 0; // ไม่ซื้อดอกไม้ใดๆ
        for (int i = 0; i < n; i++) {
            auto p = flowers[i];
            int price = get<0>(p);
            int beauty = get<1>(p);
            int usedto = get<2>(p);
           
            for (int C = M-price; C >= 0; C--) {
                for (int FlowerBuy = n - 1; FlowerBuy >= 0; FlowerBuy--) {
                    if (dynamicP[C][FlowerBuy] != -1) {
                        int new_C = C + price;
                        int new_FlowerBuy = FlowerBuy + 1;
                        dynamicP[new_C][new_FlowerBuy] = max(dynamicP[new_C][new_FlowerBuy], dynamicP[C][FlowerBuy] + beauty);
                    }
                }
            }
        }
        return dynamicP;
    };
    vector<vector<int>> dynamicPLong = computeDP(FlowerL);   // กลุ่มยาว
    vector<vector<int>> dynamicPShort = computeDP(FlowerS);   // กลุ่มสั้น
    
    int nLong = FlowerL.size();
    int nShort = FlowerS.size();
    int ans = 0; 

    for (int CLong = 0; CLong <= M; CLong++) {
        for (int CShort = 0; CShort <= M - CLong; CShort++) {
            for (int FlowerBuyLong = 0; FlowerBuyLong <= nLong; FlowerBuyLong++) {
                if (dynamicPLong[CLong][FlowerBuyLong] == -1)
                    continue; 
                for (int FlowerBuyShort = 0; FlowerBuyShort <= nShort; FlowerBuyShort++) {
                    if (dynamicPShort[CShort][FlowerBuyShort] == -1)
                        continue;
                    bool Val = false;
                    if(FlowerBuyLong == 0 && FlowerBuyShort == 0) {
                        Val = true; 
                    }
                    else if(FlowerBuyLong == 0) {
                        if(FlowerBuyShort <= 2) {
                            Val = true;
                        }
                    }
                    else if(FlowerBuyShort == 0) {
                        if(FlowerBuyLong <= 2) {
                            Val = true;
                        }
                    }
                    else {
                        if(FlowerBuyLong >= FlowerBuyShort && FlowerBuyLong <= 2 * (FlowerBuyShort + 1))
                            Val = true;
                        else if(FlowerBuyShort > FlowerBuyLong && FlowerBuyShort <= 2 * (FlowerBuyLong + 1))
                            Val = true;
                    }
                    if(Val){
                        ans = max(ans, dynamicPLong[CLong][FlowerBuyLong] + dynamicPShort[CShort][FlowerBuyShort]);
                    }
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}