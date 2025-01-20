#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int C;  // Number of test cases
    cin >> C;
    
    for (int case_num = 1; case_num <= C; ++case_num) {
        int N, H, Ta, Td;
        cin >> N >> H >> Ta >> Td;
        
        vector<int> heights(N);
        for (int i = 0; i < N; ++i) {
            cin >> heights[i];
        }
        
        // Sort the heights to facilitate pairing smaller hippos with larger ones
        sort(heights.begin(), heights.end());
        
        int total_time = 0;
        int i = 0;
        
        while (i < N) {
            if (i + 1 < N && heights[i] + heights[i + 1] < H) {
                // Pair the i-th and (i+1)-th hippos
                total_time += Td;
                i += 2;  // Skip the next hippo since it's paired
            } else {
                // The i-th hippo walks alone
                total_time += Ta;
                i += 1;  // Move to the next hippo
            }
        }
        
        // Output the result for this case
        cout << "Case" << case_num << ": " << total_time << endl;
    }
    
    return 0;
}
