ด้านล่างนี้เป็นแนวทางแก้ปัญหาโดยใช้แนวคิด “ตรวจสอบความเป็น Bipartite” บนกราฟที่ประกอบด้วยนักเรียนที่มีประสบการณ์ (จำนวนคู่) น้อยกว่า K เท่านั้น เพราะนักเรียนที่มีประสบการณ์ ≥ K นั้นโรงเรียนยอมให้จัดอยู่ในทีมใดก็ได้โดยไม่คำนึงถึงประวัติการทำงานคู่

---

## แนวคิดและขั้นตอนการแก้ปัญหา

1. **อ่านข้อมูลและคำนวณค่า degree**  
   - รับอินพุต N (จำนวนนักเรียน), M (จำนวนคู่ที่เคยทำงาน) และ K  
   - สำหรับแต่ละคู่ (a, b) ให้นับจำนวนครั้งที่นักเรียนแต่ละคนเคยทำงานคู่ (คือ degree ของนักเรียนแต่ละคน)

2. **แบ่งประเภทนักเรียน**  
   - **Constrained (มีข้อจำกัด)**: นักเรียนที่มี degree น้อยกว่า K  
   - **Unconstrained (ไม่มีข้อจำกัด)**: นักเรียนที่มี degree มากกว่าหรือเท่ากับ K  
   - เนื่องจากนักเรียน unconstrained สามารถอยู่ในทีมใดก็ได้ แม้จะมี edge กับเพื่อนร่วมงานที่อยู่ในทีมเดียวกันก็ตาม  
   - ดังนั้น เฉพาะ edge ที่เชื่อมระหว่างนักเรียน constrained ทั้งสองเท่านั้นที่ต้องตรวจสอบให้แน่ใจว่าอยู่อย่างแยกทีม

3. **สร้างกราฟสำหรับนักเรียน constrained**  
   - สำหรับแต่ละคู่ (a, b) ถ้า **ทั้งสองคน**เป็น constrained (degree < K) ให้เพิ่ม edge ระหว่าง a กับ b

4. **ตรวจสอบความเป็น Bipartite**  
   - ใช้วิธี BFS หรือ DFS ไปท่องกราฟที่สร้างขึ้นแล้วกำหนดสี 2 สี (เช่น 0 กับ 1) ให้กับแต่ละ vertex  
   - ถ้าในระหว่างการท่องกราฟพบว่าสอง vertex ที่มี edge เชื่อมกันมีสีเดียวกัน แสดงว่าไม่สามารถแบ่งทีมได้ (เนื่องจากมีนักเรียนที่เคยทำงานด้วยกันอยู่ในทีมเดียวกัน)  
   - หากสามารถกำหนดสีให้กับทุก vertex ได้โดยไม่ขัดแย้งกัน แสดงว่าสามารถแบ่งทีมได้

5. **แสดงผล**  
   - ถ้าแบ่งทีมได้ตามเงื่อนไขให้แสดง “yes”  
   - หากไม่สามารถแบ่งได้ ให้แสดง “no”

---

## โค้ดภาษา C++

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;
    
    // เก็บจำนวนคู่ (degree) ของแต่ละนักเรียน
    vector<int> degree(N + 1, 0);
    // เก็บรายการคู่ทั้งหมด (เพื่อที่จะนำไปพิจารณาเฉพาะ constrained)
    vector<pair<int, int>> pairs;
    
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        degree[a]++;
        degree[b]++;
        pairs.push_back({a, b});
    }
    
    // สร้างกราฟเฉพาะสำหรับ constrained: นักเรียนที่ degree < K
    vector<vector<int>> graph(N + 1);
    for(auto &p : pairs){
        int a = p.first, b = p.second;
        // เพิ่ม edge เฉพาะเมื่อทั้ง a และ b เป็น constrained
        if(degree[a] < K && degree[b] < K){
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
    }
    
    // array สำหรับเก็บสีของแต่ละ vertex (-1 หมายถึงยังไม่ระบุสี)
    vector<int> color(N + 1, -1);
    
    // ฟังก์ชันตรวจสอบความเป็น bipartite สำหรับ component ที่มี vertex u เป็นจุดเริ่มต้น
    auto bfs = [&](int start) -> bool {
        queue<int> q;
        color[start] = 0;
        q.push(start);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v : graph[u]){
                // ถ้ายังไม่ได้กำหนดสี
                if(color[v] == -1){
                    color[v] = 1 - color[u];
                    q.push(v);
                } else if(color[v] == color[u]){
                    // พบว่ามี edge ที่เชื่อม vertex ที่มีสีเดียวกัน
                    return false;
                }
            }
        }
        return true;
    };
    
    // ตรวจสอบทุก vertex ที่เป็น constrained
    for(int i = 1; i <= N; i++){
        if(degree[i] < K && color[i] == -1){
            if(!bfs(i)){
                cout << "no";
                return 0;
            }
        }
    }
    
    cout << "yes";
    return 0;
}
```

---

## อธิบายโค้ดทีละส่วน

1. **ส่วนของการอ่านข้อมูลและคำนวณ degree**  
   ```cpp
    int N, M, K;
    cin >> N >> M >> K;
    
    vector<int> degree(N + 1, 0);
    vector<pair<int, int>> pairs;
    
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        degree[a]++;
        degree[b]++;
        pairs.push_back({a, b});
    }
   ```  
   - อ่านจำนวน N, M, K  
   - สำหรับแต่ละคู่ที่ป้อนเข้ามา จะนับ degree ของนักเรียนที่เกี่ยวข้องและเก็บคู่ไว้ใน vector pairs เพื่อใช้งานต่อไป

2. **สร้างกราฟสำหรับนักเรียน constrained**  
   ```cpp
    vector<vector<int>> graph(N + 1);
    for(auto &p : pairs){
        int a = p.first, b = p.second;
        if(degree[a] < K && degree[b] < K){
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
    }
   ```  
   - วนลูปดูแต่ละคู่ หากทั้งสองนักเรียนมี degree น้อยกว่า K (คือ constrained) ให้เพิ่ม edge ระหว่างกันในกราฟ

3. **ตรวจสอบความเป็น Bipartite**  
   ```cpp
    vector<int> color(N + 1, -1);
    
    auto bfs = [&](int start) -> bool {
        queue<int> q;
        color[start] = 0;
        q.push(start);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v : graph[u]){
                if(color[v] == -1){
                    color[v] = 1 - color[u];
                    q.push(v);
                } else if(color[v] == color[u]){
                    return false;
                }
            }
        }
        return true;
    };
    
    for(int i = 1; i <= N; i++){
        if(degree[i] < K && color[i] == -1){
            if(!bfs(i)){
                cout << "no";
                return 0;
            }
        }
    }
   ```  
   - ใช้ vector `color` เพื่อเก็บสีของแต่ละ vertex โดยเริ่มต้นด้วย -1 (ยังไม่ระบุสี)
   - ฟังก์ชัน `bfs` จะเริ่มที่ vertex ใด vertex หนึ่งแล้วทำการกำหนดสีให้กับ vertex ที่ติดกันแบบสลับสี  
   - ถ้าใน component ใดพบว่ามี vertex ที่มีสีเดียวกันอยู่ติดกัน แสดงว่ากราฟไม่เป็น bipartite และจึงไม่สามารถแบ่งทีมได้

4. **แสดงผล**  
   ```cpp
    cout << "yes";
    return 0;
   ```  
   - หากผ่านการตรวจสอบทุก component โดยไม่พบปัญหา ให้แสดง “yes” ว่าสามารถแบ่งทีมได้

---

## ตัวอย่างการทำงาน

### ตัวอย่างที่ 1
**Input:**  
```
5 6 4
1 2
1 3
1 4
1 5
2 3
4 5
```

**ขั้นตอน:**  
- **คำนวณ degree:**  
  - นักเรียน 1: degree = 4 (unconstrained เพราะ 4 ≥ 4)  
  - นักเรียน 2: degree = 2 (constrained)  
  - นักเรียน 3: degree = 2 (constrained)  
  - นักเรียน 4: degree = 2 (constrained)  
  - นักเรียน 5: degree = 2 (constrained)
- **สร้างกราฟ:**  
  - พิจารณาคู่ที่มีทั้งสองคนเป็น constrained  
  - คู่ที่เกิดขึ้น: (2,3) และ (4,5)
- **ตรวจสอบ Bipartite:**  
  - Component แรก: {2, 3} สามารถกำหนดสีได้ (2 สีแตกต่างกัน)  
  - Component ที่สอง: {4, 5} กำหนดสีได้เช่นกัน
- **ผลลัพธ์:**  
  - แบ่งทีมได้ จึงแสดง “yes”

### ตัวอย่างที่ 2
**Input:**  
```
6 10 4
1 2
1 3
1 4
1 5
1 6
2 3
3 4
4 5
5 6
6 2
```

**ขั้นตอน:**  
- **คำนวณ degree:**  
  - นักเรียน 1: degree = 5 (unconstrained)  
  - นักเรียน 2: degree = 3 (constrained)  
  - นักเรียน 3: degree = 3 (constrained)  
  - นักเรียน 4: degree = 3 (constrained)  
  - นักเรียน 5: degree = 3 (constrained)  
  - นักเรียน 6: degree = 3 (constrained)
- **สร้างกราฟ:**  
  - พิจารณาคู่ที่มีทั้งสอง constrained  
  - กราฟ constrained จะมี edge: (2,3), (3,4), (4,5), (5,6) และ (6,2)  
  - กราฟนี้เป็น cycle ที่มีจำนวน vertex 5 (cycle คี่) ซึ่งไม่เป็น bipartite
- **ผลลัพธ์:**  
  - ไม่สามารถแบ่งทีมได้ จึงแสดง “no”

---

แนวทางและโค้ดนี้จะช่วยให้คุณเข้าใจวิธีการแก้ปัญหาด้วยการใช้กราฟและการตรวจสอบ bipartite ในการแบ่งทีมตามเงื่อนไขที่กำหนดไว้ในโจทย์