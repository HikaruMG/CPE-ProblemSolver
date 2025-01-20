#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

// ใช้ adjacency list แทนกราฟแบบสองมิติ
int *graph[MAX_N + 1];  // เก็บ pointer ของแต่ละจุดยอด
int visited[MAX_N + 1];  // เก็บสถานะการเยี่ยมชมจุดยอด

void dfs(int node) {
    visited[node] = 1; // ทำเครื่องหมายว่าเยี่ยมชมแล้ว
    for (int i = 0; graph[node][i] != -1; i++) {
        int neighbor = graph[node][i];
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // เตรียม adjacency list
    for (int i = 1; i <= n; i++) {
        graph[i] = (int *)malloc((n + 1) * sizeof(int));  // จองหน่วยความจำสำหรับแต่ละจุดยอด
        for (int j = 0; j <= n; j++) {
            graph[i][j] = -1; // กำหนดค่าเริ่มต้นให้เป็น -1 (หมายถึงจุดยอดนี้ยังไม่มีการเชื่อมต่อ)
        }
    }

    // อ่านข้อมูลเส้นเชื่อม
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        
        // เพิ่มเส้นเชื่อมใน adjacency list
        int j = 0;
        while (graph[a][j] != -1) {
            j++;
        }
        graph[a][j] = b;
        
        j = 0;
        while (graph[b][j] != -1) {
            j++;
        }
        graph[b][j] = a;
    }

    int component_count = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) { // ถ้ายังไม่ได้เยี่ยมชมจุดยอด
            dfs(i); // เริ่ม DFS ที่จุดยอด i
            component_count++; // เพิ่มจำนวน connected component
        }
    }

    printf("%d\n", component_count);

    // Free memory
    for (int i = 1; i <= n; i++) {
        free(graph[i]);
    }

    return 0;
}
