#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct jumppoint {
    int x, y;
};

long long dist(jumppoint a, jumppoint b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

/**
 * @brief Computes the minimum number of jumps required to reach the last jump point
 *        from the first jump point, given a set of jump points and a maximum jump distance.
 *
 * @param jumppoints A vector of jump points
 * @param k The maximum jump distance
 *
 * @return The minimum number of jumps required to reach the last jump point from the first jump point.
 *         Returns -1 if it is impossible to reach the last jump point.
 */
int minjump(vector<jumppoint>& jumppoints, long long k) {
    int n = jumppoints.size();
    vector<vector<int>> g(n);

    // Build the graph of jump points, where two nodes are connected if the
    // distance between them is less than or equal to the square of the maximum jump distance.
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (dist(jumppoints[i], jumppoints[j]) <= k * k) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }

    // Perform a breadth-first search (BFS) to find the minimum number of jumps required
    // to reach the last jump point from the first jump point.
    vector<bool> visited(n, false);
    queue<pair<int, int>> q;
    q.push({0, 0});

    while (!q.empty()) {
        int current = q.front().first;
        int jumps = q.front().second;
        q.pop();

        // If we have already visited this node, skip it.
        if (visited[current]) continue;
        visited[current] = true;

        // If we have reached the last jump point, return the number of jumps.
        if (current == n - 1) {
            return jumps;
        }

        // Add all unvisited neighbors of the current node to the queue.
        for (int neighbor : g[current]) {
            if (!visited[neighbor]) {
                q.push({neighbor, jumps + 1});
            }
        }
    }

    // If we have not reached the last jump point after visiting all nodes, return -1.
    return -1;
}

/**
 * Main function.
 *
 * @return 0 if successful, -1 otherwise.
 */
int main() {
    // Read the number of jump points and the maximum jump distance from standard input
    int n; // number of jump points
    long long k; // maximum jump distance

    // Read the number of jump points and the maximum jump distance from standard input
    cin >> n >> k;

    // Read the coordinates of each jump point from standard input
    vector<jumppoint> jumppoints(n);
    for (int i = 0; i < n; i++) {
        // Read the x and y coordinates of the ith jump point
        cin >> jumppoints[i].x >> jumppoints[i].y;
    }

    // Add a jump point at the origin (0, 0)
    jumppoints.insert(jumppoints.begin(), {0, 0});

    // Add a jump point at the end point (100, 100)
    jumppoints.push_back({100, 100});

    // If the maximum jump distance is 0, we can't make any jumps
    if (k == 0) {
        cout << -1 << endl;
        return 0;
    }

    // Find the minimum number of jumps needed to reach the end point
    int result = minjump(jumppoints, k);

    // Print the result to standard output
    cout << result << endl;

    return 0;
}
