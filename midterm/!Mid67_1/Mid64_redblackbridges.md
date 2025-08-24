### การวิเคราะห์โจทย์

โจทย์นี้เป็นปัญหาการหาเส้นทางที่สั้นที่สุด (Shortest Path) บนกราฟ โดยมีเงื่อนไขพิเศษเกี่ยวกับสีของสะพาน ซึ่งสามารถมองเป็นกราฟแบบไม่มีทิศทาง (Undirected Graph) และใช้การค้นหาแบบ BFS (Breadth-First Search) ที่มีการจัดการสถานะเพิ่มเติมสำหรับสีที่เลือกใช้

#### ความหมายของโจทย์
- มีเกาะ N เกาะ (โหนด) และสะพาน M สะพาน (ขอบ)
- สะพานแต่ละเส้นมี 3 สถานะ:
  - ไม่ทาสี (Ci = 0)
  - ทาสีแดง (Ci = 1)
  - ทาสีดำ (Ci = 2)
- เริ่มต้นจากเกาะ S ไปยังเกาะ T
- เงื่อนไข: หากเลือกเดินผ่านสะพานที่มีสี (แดงหรือดำ) จะต้องไม่เดินผ่านสะพานที่มีสีต่างกัน (เช่น ถ้าเดินผ่านสะพานสีแดงแล้ว ห้ามเดินผ่านสะพานสีดำ)
- เป้าหมาย: หาจำนวนสะพานขั้นต่ำที่ต้องข้ามเพื่อไปถึง T หรือตอบ -1 ถ้าไปไม่ถึง

#### วิธีการแก้ปัญหา
- ใช้ BFS เพื่อหาเส้นทางที่สั้นที่สุด
- เพิ่มสถานะของสีที่เลือกใช้:
  - สถานะ 0: ยังไม่เลือกสีใด ๆ (สามารถใช้สะพานที่ไม่ทาสีได้)
  - สถานะ 1: เลือกใช้เฉพาะสีแดง (ห้ามใช้สีดำ)
  - สถานะ 2: เลือกใช้เฉพาะสีดำ (ห้ามใช้สีแดง)
- ใช้โครงสร้างข้อมูล:
  - กราฟ: เก็บข้อมูลสะพานด้วย adjacency list
  - คิว: ใช้สำหรับ BFS โดยเก็บข้อมูล (โหนด, สีที่เลือก, ระยะทาง)
  - อาร์เรย์ visited: ตรวจสอบว่าโหนดใดถูกเยี่ยมแล้วในสถานะสีใด

#### ขั้นตอนการคิด
1. **สร้างกราฟ**: ใช้ adjacency list เพื่อเก็บข้อมูลสะพาน โดยแต่ละโหนดจะมีรายการของ (โหนดปลายทาง, สีของสะพาน)
2. **กำหนดสถานะสี**:
   - 0: ยังไม่เลือกสี
   - 1: เลือกสีแดง
   - 2: เลือกสีดำ
3. **ใช้ BFS**:
   - เริ่มจากโหนด S ด้วยสถานะสี 0 และระยะทาง 0
   - สำรวจโหนดเพื่อนบ้านตามเงื่อนไขสี:
     - ถ้าสะพานไม่มีสี (0): ไปได้ทุกสถานะสี
     - ถ้าสะพานสีแดง (1): ไปได้เฉพาะสถานะ 0 (แล้วเปลี่ยนเป็น 1) หรือ 1
     - ถ้าสะพานสีดำ (2): ไปได้เฉพาะสถานะ 0 (แล้วเปลี่ยนเป็น 2) หรือ 2
   - บันทึกระยะทางและสถานะสีใน visited
4. **ตรวจสอบผลลัพธ์**:
   - หากถึงโหนด T ให้บันทึกระยะทางที่สั้นที่สุด
   - หากสำรวจครบแล้วยังไม่ถึง T ให้ตอบ -1

### โค้ด C++

```cpp
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
        for (auto [next_node, edge_color] : graph[node]) {
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
```

### อธิบายโค้ดทีละส่วน

#### 1. การกำหนดตัวแปรและโครงสร้างข้อมูล
```cpp
const int MAX_N = 50005;
vector<pair<int, int>> graph[MAX_N]; // (node, color)
int visited[MAX_N][3]; // visited[node][color_state]
```
- `MAX_N`: จำนวนโหนดสูงสุดตามโจทย์ (50,000)
- `graph`: Adjacency list เก็บข้อมูลกราฟ โดยแต่ละโหนดมี vector ของ (โหนดปลายทาง, สีของสะพาน)
- `visited`: อาร์เรย์ 2 มิติ เก็บระยะทางที่สั้นที่สุดไปยังโหนดในแต่ละสถานะสี (0, 1, 2) ค่าเริ่มต้น -1 หมายถึงยังไม่เยี่ยม

#### 2. ฟังก์ชัน BFS
```cpp
int bfs(int N, int S, int T) {
    queue<tuple<int, int, int>> q; // (node, color_state, distance)
    memset(visited, -1, sizeof(visited)); // -1 means unvisited
```
- ใช้ `queue` เก็บ tuple ของ (โหนด, สถานะสี, ระยะทาง)
- รีเซ็ต `visited` เป็น -1

```cpp
    q.push({S, 0, 0});
    visited[S][0] = 0;
```
- เริ่มจากโหนด S ด้วยสถานะสี 0 (ยังไม่เลือกสี) และระยะทาง 0

```cpp
    while (!q.empty()) {
        int node, color_state, dist;
        tie(node, color_state, dist) = q.front();
        q.pop();

        if (node == T) return dist;
```
- ดึงข้อมูลจากคิวและตรวจสอบว่าถึง T หรือยัง

```cpp
        for (auto [next_node, edge_color] : graph[node]) {
            int new_color_state = color_state;

            if (edge_color == 0) {
                // No color edge, can use with any state
            } else if (edge_color == 1) {
                if (color_state == 2) continue;
                new_color_state = 1;
            } else if (edge_color == 2) {
                if (color_state == 1) continue;
                new_color_state = 2;
            }
```
- สำรวจโหนดเพื่อนบ้าน:
  - ถ้าสะพานไม่มีสี: ใช้สถานะสีเดิม
  - ถ้าสะพานสีแดง: ห้ามใช้ถ้าสถานะเป็น 2 (เลือกสีดำแล้ว) และเปลี่ยนสถานะเป็น 1
  - ถ้าสะพานสีดำ: ห้ามใช้ถ้าสถานะเป็น 1 (เลือกสีแดงแล้ว) และเปลี่ยนสถานะเป็น 2

```cpp
            if (visited[next_node][new_color_state] == -1) {
                visited[next_node][new_color_state] = dist + 1;
                q.push({next_node, new_color_state, dist + 1});
            }
```
- หากโหนดในสถานะสีใหม่ยังไม่ถูกเยี่ยม ให้เพิ่มเข้าไปในคิว

```cpp
    return -1;
```
- หากไม่สามารถไปถึง T ได้ คืนค่า -1

#### 3. ฟังก์ชัน Main
```cpp
    int N, M, S, T;
    scanf("%d %d %d %d", &N, &M, &S, &T);

    for (int i = 0; i < M; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
```
- รับข้อมูล N, M, S, T และสร้างกราฟแบบไม่มีทิศทาง

```cpp
    int result = bfs(N, S, T);
    printf("%d\n", result);
```
- เรียก BFS และพิมพ์ผลลัพธ์

### ตัวอย่างการทำงาน

#### Input 1:
```
6 7 2 4
2 5 0
3 4 2
6 5 0
3 6 0
1 4 1
2 1 2
1 3 0
```
- กราฟ:
  - 2 --(0)-- 5 --(0)-- 6 --(0)-- 3 --(2)-- 4
  - 2 --(2)-- 1 --(1)-- 4
  - 1 --(0)-- 3
- BFS:
  - เริ่มที่ 2, สถานะ 0, ระยะ 0
  - ไป 5 (สี 0), สถานะ 0, ระยะ 1
  - ไป 1 (สี 2), สถานะ 2, ระยะ 1
  - จาก 1 ไป 3 (สี 0), สถานะ 2, ระยะ 2
  - จาก 3 ไป 4 (สี 2), สถานะ 2, ระยะ 3
- ผลลัพธ์: 3

#### Input 2:
```
3 2 1 3
1 2 1
2 3 2
```
- กราฟ:
  - 1 --(1)-- 2 --(2)-- 3
- BFS:
  - เริ่มที่ 1, สถานะ 0, ระยะ 0
  - ไป 2 (สี 1), สถานะ 1, ระยะ 1
  - จาก 2 ไม่สามารถไป 3 ได้ (สี 2 แต่สถานะ 1)
- ผลลัพธ์: -1

### สรุป
โค้ดนี้แก้ปัญหาด้วย BFS โดยเพิ่มการจัดการสถานะสีเพื่อให้สอดคล้องกับเงื่อนไขของโจทย์ และสามารถจัดการกรณีที่มีสะพานไม่มีสีได้อย่างถูกต้องตามโจทย์กำหนด