#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// โครงสร้างข้อมูลสำหรับ interval
struct Interval {
    int start;
    int end;
};

// ฟังก์ชันเปรียบเทียบสำหรับการเรียงลำดับตาม end time
bool compare(Interval a, Interval b) {
    return a.end < b.end;
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

int main() {
    int n;
    cout << "Enter number of intervals: ";
    cin >> n;
    
    vector<Interval> intervals(n);
    cout << "Enter start time and end time for each interval:\n";
    for (int i = 0; i < n; i++) {
        cout << "Interval " << i + 1 << ": ";
        cin >> intervals[i].start >> intervals[i].end;
    }
    
    // Interval Scheduling
    cout << "\nInterval Scheduling Result (Maximum number of non-conflicting intervals):\n";
    vector<Interval> result = intervalScheduling(intervals);
    for (auto interval : result) {
        cout << "[" << interval.start << ", " << interval.end << "] ";
    }
    cout << "\nTotal intervals selected: " << result.size() << endl;
    
    return 0;
}