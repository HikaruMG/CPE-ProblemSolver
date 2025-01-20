#include <iostream>
using namespace std;
#include <vector>
#include <queue>

/**
 * @brief Perform a topological sort on a directed acyclic graph (DAG)
 *
 * @param n The number of nodes in the graph
 * @param m The number of edges in the graph
 * @param es A vector of pairs of nodes representing the edges in the graph
 *
 * The algorithm first builds the adjacency list of the graph. The adjacency
 * list is a vector of vectors of integers. The ith element of the outer vector
 * is a vector of integers, where each integer is a node to which there is an
 * edge from node i.
 *
 * After building the adjacency list, the algorithm performs a depth-first
 * search (DFS) starting from each node with no incoming edges. The algorithm
 * uses a queue to keep track of the nodes to visit. If the queue is empty, the
 * algorithm prints out "no", indicating that the graph has a cycle. Otherwise,
 * the algorithm prints out the nodes in the order they were visited.
 */
void topo(int n, int m, vector<pair<int, int>>& es) {
    // Build adjacency list
    // A vector of vectors of integers. The ith element of the outer vector
    // is a vector of integers, where each integer is a node to which there
    // is an edge from node i.
    vector<vector<int>> adj(n + 1);

    // A vector of integers, where each integer is the degree of the
    // corresponding node.
    // The degree of a node is the number of incoming edges to that node.
    vector<int> deg(n + 1, 0);

    // Iterate over each edge in the graph and increment the degree of the
    // destination node.
    for (auto& e : es) {
        int u = e.first, v = e.second;
        adj[u].push_back(v);
        deg[v]++; // increment degree of node v
    }

    // Perform DFS
    // A queue to keep track of the nodes to visit.
    queue<int> q;

    // Iterate over each node in the graph and add it to the queue if it has
    // no incoming edges.
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) { // if node has no incoming edges
            q.push(i);
        }
    }

    // A vector to store the result of the topological sort.
    vector<int> res;

    // While the queue is not empty, pop the front node and add it to the
    // result vector. Then, iterate over all of its neighbors and decrement
    // their degree. If a neighbor's degree is now 0, add it to the queue.
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        res.push_back(cur);

        // Iterate over all neighbors of the current node and decrement their
        // degree. If a neighbor's degree is now 0, add it to the queue.
        for (int next : adj[cur]) {
            deg[next]--; // decrement degree of node next
            if (deg[next] == 0) {
                q.push(next);
            }
        }
    }

    // Check if there is a cycle in the graph. If the size of the result vector
    // is not equal to the number of nodes in the graph, then there is a cycle.
    if ((int)res.size() != n) {
        cout << "no" << endl;
    } else {
        // Print out the nodes in topological order
        for (int node : res) {
            cout << node << endl;
        }
    }
}

/**
 * @brief Main function to test the topological sort algorithm
 *
 * @return 0 if successful, -1 otherwise
 */
int main() {
    int n, m;
    // Read the number of nodes and edges from standard input
    cin >> n >> m;

    // Vector of pairs of nodes representing the edges in the graph
    vector<pair<int, int>> es(m);

    // Read each edge from standard input and store it in the vector
    for (int i = 0; i < m; i++) {
        cin >> es[i].first >> es[i].second;
    }

    // Call the topological sort function
    topo(n, m, es);

    // Return 0 to indicate successful completion of the program
    return 0;
}

