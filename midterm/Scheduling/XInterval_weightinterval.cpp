#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// โครงสร้างข้อมูลสำหรับ interval
struct Interval {
    int start;
    int end;
    int weight;
};

// ฟังก์ชันเปรียบเทียบสำหรับการเรียงลำดับตาม end time
bool compare(Interval a, Interval b) {
    return a.end < b.end;
}

// ฟังก์ชันหา interval ก่อนหน้าที่ไม่ทับซ้อน
int findLastNonConflicting(vector<Interval>& intervals, int index) {
    for (int j = index - 1; j >= 0; j--) {
        if (intervals[j].end <= intervals[index].start) {
            return j;
        }
    }
    return -1;
}

// Interval Scheduling (Greedy)
vector<Interval> intervalScheduling(vector<Interval>& intervals) {
    // เรียงตาม end time
    sort(intervals.begin(), intervals.end(), compare);
    
    vector<Interval> result;
    result.push_back(intervals[0]); // เลือก interval แรก
    
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i].start >= result.back().end) {
            result.push_back(intervals[i]);
        }
    }
    return result;
}

// Weighted Interval Scheduling (Dynamic Programming)
int weightedIntervalScheduling(vector<Interval>& intervals) {
    // เรียงตาม end time
    sort(intervals.begin(), intervals.end(), compare);
    
    // สร้างตาราง DP
    vector<int> dp(intervals.size());
    dp[0] = intervals[0].weight; // กรณีฐาน
    
    // เติมตาราง DP
    for (int i = 1; i < intervals.size(); i++) {
        // หาน้ำหนักถ้าเลือก interval ปัจจุบัน
        int inclProfit = intervals[i].weight;
        int last = findLastNonConflicting(intervals, i);
        if (last != -1) {
            inclProfit += dp[last];
        }
        
        // เปรียบเทียบระหว่างเลือกและไม่เลือก
        dp[i] = max(inclProfit, dp[i-1]);
    }
    
    return dp[intervals.size() - 1];
}

int main() {
    int n;
    cout << "Enter number of intervals: ";
    cin >> n;
    
    vector<Interval> intervals(n);
    cout << "Enter start time, end time, and weight for each interval:\n";
    for (int i = 0; i < n; i++) {
        cout << "Interval " << i + 1 << ": ";
        cin >> intervals[i].start >> intervals[i].end >> intervals[i].weight;
    }
    
    // Interval Scheduling
    cout << "\nInterval Scheduling Result (Maximum number of non-conflicting intervals):\n";
    vector<Interval> result1 = intervalScheduling(intervals);
    for (auto interval : result1) {
        cout << "[" << interval.start << ", " << interval.end << "] ";
    }
    
    // Weighted Interval Scheduling
    cout << "\n\nWeighted Interval Scheduling Result (Maximum total weight):\n";
    int maxWeight = weightedIntervalScheduling(intervals);
    cout << "Maximum weight: " << maxWeight << endl;
    
    return 0;
}