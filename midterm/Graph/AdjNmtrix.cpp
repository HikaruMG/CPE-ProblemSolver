#include <iostream>
#include <vector>
using namespace std;

// ฟังก์ชันแสดง Adjacency List
void printAdjList(vector<int> adj[], int V) {
    cout << "Adjacency List:" << endl;
    for (int i = 1; i <= V; i++) {
        cout << "Vertex " << i << ": ";
        for (int j : adj[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
}

// ฟังก์ชันแสดง Adjacency Matrix
void printAdjMatrix(int** adjMatrix, int V) {
    cout << "\nAdjacency Matrix:" << endl;
    cout << "  ";
    for (int i = 1; i <= V; i++) {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 1; i <= V; i++) {
        cout << i << " ";
        for (int j = 1; j <= V; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

// int main() {
//     int V = 6; // จำนวนจุดยอด (ปรับเป็น 6 เพื่อให้ครอบคลุมเส้นเชื่อม (5, 6))
//     int E = 5; // จำนวนเส้นเชื่อม

//     // สร้าง Adjacency List
//     vector<int> adjList[V + 1]; // ใช้ index เริ่มที่ 1

//     // สร้าง Adjacency Matrix
//     int** adjMatrix = new int*[V + 1];
//     for (int i = 0; i <= V; i++) {
//         adjMatrix[i] = new int[V + 1]();
//     }

//     // รับข้อมูลเส้นเชื่อมและเพิ่มเข้าไปใน Adjacency List และ Matrix
//     int edges[5][2] = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}}; // ข้อมูลจาก input
//     for (int i = 0; i < E; i++) {
//         int u = edges[i][0];
//         int v = edges[i][1];

//         // เพิ่มใน Adjacency List (กราฟไม่มุ่ง)
//         adjList[u].push_back(v);
//         adjList[v].push_back(u);

//         // เพิ่มใน Adjacency Matrix (กราฟไม่มุ่ง)
//         adjMatrix[u][v] = 1;
//         adjMatrix[v][u] = 1;
//     }

//     // แสดงผล Adjacency List
//     printAdjList(adjList, V);

//     // แสดงผล Adjacency Matrix
//     printAdjMatrix(adjMatrix, V);

//     // คืนหน่วยความจำของ Adjacency Matrix
//     for (int i = 0; i <= V; i++) {
//         delete[] adjMatrix[i];
//     }
//     delete[] adjMatrix;

//     return 0;
// }

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<int> adjList[V + 1];
    int** adjMatrix = new int*[V + 1];
    for (int i = 0; i <= V; i++) {
        adjMatrix[i] = new int[V + 1]();
    }

    cout << "Enter " << E << " edges (u v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    printAdjList(adjList, V);
    printAdjMatrix(adjMatrix, V);

    for (int i = 0; i <= V; i++) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;

    return 0;
}