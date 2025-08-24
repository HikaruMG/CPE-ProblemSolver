#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Job {
    int Di, Ti;
};
bool compare(const Job &a, const Job &b) {
    return a.Di < b.Di;
}

int main() {
    // Read the number of jobs
    int N;
    cin >> N;

    // Get all the jobs
    vector<Job> jobs(N);
    for (int i = 0; i < N; ++i) {
        cin >> jobs[i].Di >> jobs[i].Ti;
    }

    // Sort the jobs by their deadlines
    sort(jobs.begin(), jobs.end(), compare);

    // Initialize variables to track the maximum penalty and the current time
    long long current_time = 0;
    long long max_penalty = 0;

    // Process each job
    for (const auto &job : jobs) {
        // Add the time it takes to complete this job to the current time
        current_time += job.Ti;

        // If the current time is after the deadline, then calculate the penalty
        if (current_time > job.Di + 10) {
            // Calculate the penalty
            long long penalty = (current_time - job.Di - 10) * 1000;

            // Update the maximum penalty
            max_penalty = max(max_penalty, penalty);
        }
    }

    // Print the maximum penalty
    cout << max_penalty << endl;

    return 0;
}
