#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/**
 * @brief Check if a graph is bipartite or not
 *
 * @param n The number of nodes in the graph
 * @param adj The adjacency list of the graph
 *
 * @return True if the graph is bipartite, false otherwise
 */
bool checkBi(int n, vector<vector<int>>& adj) {
    // Create a vector to store the color of each node
    // Initialize all nodes to -1, which means they haven't been colored yet
    vector<int> visited(n+1, -1);

    // Iterate over all nodes in the graph
    for (int i = 1; i <= n; i++) {
        // If a node hasn't been colored yet, start a BFS from it
        if (visited[i] == -1) {
            queue<int> q;
            q.push(i);
            // Color the current node as 0
            visited[i] = 0;

            // Start a BFS to color all nodes reachable from the current node
            while (!q.empty()) {
                int cur = q.front();
                q.pop();

                // For each neighbor of the current node
                for (int next : adj[cur]) {
                    // If the neighbor hasn't been colored yet
                    if (visited[next] == -1) {
                        // Color the neighbor as the opposite color of the current node
                        visited[next] = 1 - visited[cur];
                        // Add the neighbor to the queue to continue the BFS
                        q.push(next);
                    } else if (visited[next] == visited[cur]) {
                        // If the neighbor already has the same color as the current node, return false
                        return false;
                    }
                }
            }
        }
    }
    // If all nodes have been colored and no two adjacent nodes have the same color, return true
    return true;
}

int main() {
    // Read the number of test cases
    int k;
    cin >> k;

    // Loop over each test case
    while (k--) {
        // Read the number of nodes and edges in the current test case
        int n, m;
        cin >> n >> m;

        // Initialize the adjacency list for the graph with n+1 nodes (1-based indexing)
        vector<vector<int>> adj(n+1);

        // Read each edge and update the adjacency list
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v); // Add v to the adjacency list of u
            adj[v].push_back(u); // Add u to the adjacency list of v (since the graph is undirected)
        }

        // Check if the graph is bipartite using the checkBi function
        if (checkBi(n, adj)) {
            // If the graph is bipartite, output "yes"
            cout << "yes\n";
        } else {
            // If the graph is not bipartite, output "no"
            cout << "no\n";
        }
    }

    // Return 0 to indicate successful completion of the program
    return 0;
}
