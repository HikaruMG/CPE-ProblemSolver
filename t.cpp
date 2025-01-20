#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

/**
 * Perform a breadth-first search (BFS) of a graph to find the shortest path from
 * the start node to the goal node.
 *
 * @param graph The adjacency list of the graph, where graph[i] is a list of nodes
 *    connected to node i.
 * @param start The node to start the search from.
 * @param goal The node to find the shortest path to.
 */
void bfs(vector<vector<int>> &graph, int start, int goal) {
    // Create a queue to hold nodes to visit, and a vector to keep track of
    // whether each node has been visited or not.
    queue<int> q;
    vector<bool> visited(graph.size(), false);

    // Create a vector to keep track of the distance from the start node to each
    // node.  Initialize all distances to -1, indicating that they are
    // unreachable.
    vector<int> distance(graph.size(), -1);

    // Mark the start node as visited, and set its distance to 0.
    visited[start] = true;
    distance[start] = 0;
    // Add the start node to the queue to visit it first.
    q.push(start);

    // While there are still nodes to visit, visit each node in order of
    // increasing distance from the start node.
    while (!q.empty()) {
        // Pop the next node to visit off the queue.
        int curr = q.front();
        q.pop();

        // If the current node is the goal node, print out its distance and
        // return.
        if (curr == goal) { // reach or not
            cout << distance[curr] << endl; // shortest distance
            return;
        }

        // Iterate over all neighbors of the current node, and mark them as
        // visited if they haven't been visited before.
        for (int neighbor : graph[curr]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                // Set the distance of the neighbor to the distance of the
                // current node, plus one.
                distance[neighbor] = distance[curr] + 1;
                // Add the neighbor to the queue to visit it later.
                q.push(neighbor);
            }
        }
    }

    // If the loop completes without finding the goal node, print out -1 to
    // indicate that it is unreachable.
    cout << -1 << endl;
}

int main() {
    // Declare variables for the number of coordinates and the maximum allowed distance squared
    int n, r;
    cin >> n >> r; // Read the number of coordinates and the distance

    // Vector to store the coordinates as pairs of integers
    vector<pair<int, int>> coor;
    // Adjacency list representation of the graph
    vector<vector<int>> graph;

    // Read the coordinates from standard input
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b; // Read each coordinate pair
        coor.push_back({a, b}); // Add the coordinate to the vector
    }

    // Add the starting point (0,0) to the coordinates vector
    coor.push_back({0, 0});
    // Add the goal point (100,100) to the coordinates vector
    coor.push_back({100, 100});

    // Resize the graph to accommodate all coordinates
    graph.resize(coor.size());

    // Iterate over each pair of coordinates
    for (int j = 0; j < coor.size(); j++) {
        for (int k = j + 1; k < coor.size(); k++) {
            // Calculate the difference in x and y coordinates
            int dx = coor[j].first - coor[k].first;
            int dy = coor[j].second - coor[k].second;
            // Calculate the squared distance between the two points
            int sq_distance = dx * dx + dy * dy;
            // If the squared distance is less than the allowed distance squared, add an edge to the graph
            if (sq_distance < r * r) {
                graph[j].push_back(k); // Add k to adjacency list of j
                graph[k].push_back(j); // Add j to adjacency list of k (undirected edge)
            }
        }
    }

    // Define the start node as the second last coordinate (0,0)
    int start = coor.size() - 2;
    // Define the goal node as the last coordinate (100,100)
    int goal = coor.size() - 1;

    // Perform a breadth-first search to find the shortest path from start to goal
    bfs(graph, start, goal);
}
