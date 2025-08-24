#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 50005;
vector<pair<int, int>> graph[MAX_N]; // (node, color)
int visited[MAX_N][3]; // visited[node][color_state]

int bfs(int N, int S, int T) {
    queue<tuple<int, int, int>> q; // (node, color_state, distance)
    memset(visited, -1, sizeof(visited)); // -1 means unvisited

    // Start from node S with no color chosen (state 0)
    q.push({S, 0, 0});
    visited[S][0] = 0;

    while (!q.empty()) {
        int node, color_state, dist;
        tie(node, color_state, dist) = q.front();
        q.pop();

        // If reached target
        if (node == T) return dist;

        // Explore neighbors
        for (auto temp : graph[node]) {
            int next_node = temp.first;
            int edge_color = temp.second;
            int new_color_state = color_state;
            // Determine new color state based on edge color
            if (edge_color == 0) {
                // No color edge, can use with any state
            } else if (edge_color == 1) {
                // Red edge
                if (color_state == 2) continue; // Cannot use red if black is chosen
                new_color_state = 1; // Switch to red state
            } else if (edge_color == 2) {
                // Black edge
                if (color_state == 1) continue; // Cannot use black if red is chosen
                new_color_state = 2; // Switch to black state
            }

            // If this state is unvisited or we found a shorter path
            if (visited[next_node][new_color_state] == -1) {
                visited[next_node][new_color_state] = dist + 1;
                q.push({next_node, new_color_state, dist + 1});
            }
        }
    }

    // If target is not reachable
    return -1;
}

int main() {
    int N, M, S, T;
    scanf("%d %d %d %d", &N, &M, &S, &T);

    // Input edges
    for (int i = 0; i < M; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back({b, c});
        graph[b].push_back({a, c}); // Undirected graph
    }

    // Run BFS and output result
    int result = bfs(N, S, T);
    printf("%d\n", result);

    return 0;
}