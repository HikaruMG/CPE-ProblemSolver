#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Timetmp {
    int start, end;
};
/**
 * Compares two Timetmp objects. First, we compare the end times, because
 * we want to schedule the tasks that end earliest first. If the end times
 * are equal, we compare the start times, because if the end times are equal,
 * we want to schedule the task that starts earliest first (so that we can
 * fit in more tasks). This is a stable sort, meaning that if the end times
 * are equal, the order of the tasks is preserved.
 */
bool compare(const Timetmp &a, const Timetmp &b) {
    if (a.end == b.end) {
        // end times are equal, so sort by start time
        return a.start < b.start;
    } else {
        // end times are not equal, so sort by end time
        return a.end < b.end;
    }
}


int main() {
    // count how many tasks we can schedule
    int count = 0;

    // the time at which the last task ended
    int endTask = 0;

    int N;
    cin >> N;

    vector<Timetmp> Timetmps(N);
    for (int i = 0; i < N; ++i) {
        cin >> Timetmps[i].start >> Timetmps[i].end;
    }

    // sort the tasks by their end time
    sort(Timetmps.begin(), Timetmps.end(), compare);

    // go through the tasks in order of their end time
    for (const auto &Timetmp : Timetmps) {
        // if the task starts after the last task ended, we can schedule it
        if (Timetmp.start >= endTask) {
            // increment the count of scheduled tasks
            ++count;
            // set the time at which the last task ended to be the end time of the current task
            endTask = Timetmp.end;
        }
    }
    cout << count << endl;

    return 0;
}
