### Priority Queue คืออะไร?

**Priority Queue** (คิวลำดับความสำคัญ) เป็นโครงสร้างข้อมูลชนิดหนึ่งที่คล้ายกับ **Queue** ทั่วไป แต่แตกต่างกันตรงที่แต่ละข้อมูลใน Priority Queue จะมี **ลำดับความสำคัญ (priority)** กำกับอยู่ และข้อมูลที่มีลำดับความสำคัญสูงสุดจะถูกนำออกจากคิวก่อนเสมอ โดยไม่สนใจลำดับการเพิ่มข้อมูล (ไม่ใช่ FIFO หรือ LIFO แบบ Queue หรือ Stack ทั่วไป)

ใน C++ STL โครงสร้างข้อมูลนี้ถูก implement เป็น `std::priority_queue` และมักใช้ **Heap** (โดยทั่วไปเป็น Max-Heap หรือ Min-Heap) เป็นโครงสร้างพื้นฐานในการจัดการข้อมูล

---

### คุณสมบัติของ Priority Queue
1. **การจัดลำดับตามความสำคัญ**:
   - ข้อมูลที่มีลำดับความสำคัญสูงสุด (อาจเป็นค่าสูงสุดหรือต่ำสุด ขึ้นอยู่กับการกำหนด) จะถูกนำออกก่อน
   - ลำดับความสำคัญถูกกำหนดโดย **การเปรียบเทียบ** (comparison) ซึ่งสามารถปรับแต่งได้
2. **โครงสร้างพื้นฐาน**:
   - โดยทั่วไปใช้ **Heap** (Binary Heap) ซึ่งอาจเป็น:
     - **Max-Heap**: ค่าสูงสุดอยู่ที่ root และถูกนำออกก่อน (ค่าเริ่มต้นของ `std::priority_queue`)
     - **Min-Heap**: ค่าต่ำสุดอยู่ที่ root และถูกนำออกก่อน (ต้องกำหนด comparator เพิ่มเติม)
3. **การใช้งาน**:
   - เหมาะกับงานที่ต้องการจัดการข้อมูลตามลำดับความสำคัญ เช่น การจัดตารางงาน (scheduling), อัลกอริทึมกราฟ (เช่น Dijkstra's algorithm), หรือการประมวลผลงานตามลำดับความสำคัญ

---

### คำสั่งหลักใน `std::priority_queue` (C++)
| คำสั่ง           | คำอธิบาย                                          | ความซับซ้อน |
|------------------|--------------------------------------------------|-------------|
| `push(value)`    | เพิ่มข้อมูลลงใน priority queue                  | O(log n)    |
| `pop()`          | ลบข้อมูลที่มีลำดับความสำคัญสูงสุดออกจากคิว       | O(log n)    |
| `top()`          | ดูข้อมูลที่มีลำดับความสำคัญสูงสุด (ไม่ลบ)        | O(1)        |
| `size()`         | คืนค่าขนาดของ priority queue                   | O(1)        |
| `empty()`        | ตรวจสอบว่า priority queue ว่างหรือไม่           | O(1)        |

#### หมายเหตุ
- `std::priority_queue` ไม่มีคำสั่ง `front()` หรือ `back()` เหมือน `std::queue` เพราะการเข้าถึงข้อมูลขึ้นอยู่กับลำดับความสำคัญ ไม่ใช่ตำแหน่งหน้า/ท้าย
- ค่าเริ่มต้นเป็น **Max-Heap** (ข้อมูลที่มีค่าสูงสุดจะถูกนำออกก่อน)

---

### การ Implement ใน C++
#### ตัวอย่าง 1: Priority Queue แบบ Max-Heap (ค่าเริ่มต้น)
```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
    // สร้าง priority queue แบบ Max-Heap (default)
    priority_queue<int> pq;
    
    // รับข้อมูลจากผู้ใช้
    int n, value;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++) {
        cin >> value;
        pq.push(value);
    }
    
    // แสดงข้อมูลตามลำดับความสำคัญ (สูงสุด -> ต่ำสุด)
    cout << "Priority Queue elements (Max-Heap): ";
    while(!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
    
    return 0;
}
```

##### ผลลัพธ์ตัวอย่าง
```
Enter the number of elements: 5
Enter 5 elements: 3 1 4 1 5
Priority Queue elements (Max-Heap): 5 4 3 1 1
```
- ข้อมูลถูกเรียงตามลำดับความสำคัญ (สูงสุด -> ต่ำสุด) โดยไม่สนใจลำดับการเพิ่ม

---

#### ตัวอย่าง 2: Priority Queue แบบ Min-Heap
```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
    // สร้าง priority queue แบบ Min-Heap (ใช้ greater<int>)
    priority_queue<int, vector<int>, greater<int>> pq;
    
    // รับข้อมูลจากผู้ใช้
    int n, value;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++) {
        cin >> value;
        pq.push(value);
    }
    
    // แสดงข้อมูลตามลำดับความสำคัญ (ต่ำสุด -> สูงสุด)
    cout << "Priority Queue elements (Min-Heap): ";
    while(!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
    
    return 0;
}
```

##### ผลลัพธ์ตัวอย่าง
```
Enter the number of elements: 5
Enter 5 elements: 3 1 4 1 5
Priority Queue elements (Min-Heap): 1 1 3 4 5
```
- ข้อมูลถูกเรียงตามลำดับความสำคัญ (ต่ำสุด -> สูงสุด) โดยใช้ `greater<int>` เป็น comparator

---

### การกำหนดลำดับความสำคัญแบบกำหนดเอง (Custom Comparator)
หากต้องการกำหนดลำดับความสำคัญตามเกณฑ์ที่ไม่ใช่ตัวเลขธรรมดา (เช่น วัตถุหรือโครงสร้างข้อมูล) สามารถใช้ **custom comparator** ได้

#### ตัวอย่าง: Priority Queue กับโครงสร้างข้อมูลกำหนดเอง
```cpp
#include <iostream>
#include <queue>
using namespace std;

struct Task {
    int priority;
    string name;
    Task(int p, string n) : priority(p), name(n) {}
    
    // กำหนด operator< เพื่อใช้ใน Max-Heap
    bool operator<(const Task& other) const {
        return priority < other.priority; // Max-Heap: priority สูงสุดมาก่อน
    }
};

int main() {
    priority_queue<Task> pq;
    
    // เพิ่มข้อมูล
    pq.push(Task(3, "Task A"));
    pq.push(Task(1, "Task B"));
    pq.push(Task(4, "Task C"));
    
    // แสดงข้อมูล
    cout << "Priority Queue elements (Max-Heap):" << endl;
    while(!pq.empty()) {
        cout << "Priority: " << pq.top().priority << ", Name: " << pq.top().name << endl;
        pq.pop();
    }
    
    return 0;
}
```

##### ผลลัพธ์
```
Priority Queue elements (Max-Heap):
Priority: 4, Name: Task C
Priority: 3, Name: Task A
Priority: 1, Name: Task B
```

---

### ข้อดีของ Priority Queue
- **ประสิทธิภาพสูง**: การเพิ่มและลบข้อมูลใช้เวลา O(log n) ด้วยโครงสร้าง Heap
- **ความยืดหยุ่น**: สามารถกำหนดลำดับความสำคัญได้ตามต้องการ
- **เหมาะกับงานที่มีลำดับความสำคัญ**: เช่น การจัดการงานตามความเร่งด่วน หรือการหาเส้นทางในกราฟ

### ข้อเสียของ Priority Queue
- **ไม่สามารถเข้าถึงข้อมูลทั้งหมดได้**: สามารถดูได้เฉพาะข้อมูลที่มีลำดับความสำคัญสูงสุด (`top`)
- **ไม่มี iterator**: ไม่สามารถวนลูปดูข้อมูลทั้งหมดได้โดยตรง (ต้องใช้ `pop` เพื่อดูข้อมูลทีละตัว)
- **ความซับซ้อนสูงกว่า Queue ธรรมดา**: ใช้ Heap ซึ่งซับซ้อนกว่าโครงสร้างข้อมูลแบบ FIFO หรือ LIFO

---

### ความซับซ้อน
| การดำเนินการ     | ความซับซ้อน |
|-----------------|-------------|
| การเพิ่ม (`push`) | O(log n)    |
| การลบ (`pop`)   | O(log n)    |
| การดู (`top`)   | O(1)        |
| การตรวจสอบขนาด (`size`) | O(1)        |
| การตรวจสอบความว่าง (`empty`) | O(1)        |

---

### การใช้งานจริง
1. **อัลกอริทึมกราฟ**:
   - **Dijkstra's Algorithm**: หาเส้นทางที่สั้นที่สุดโดยใช้ Min-Heap เพื่อเลือกโหนดที่มีระยะทางน้อยที่สุด
   - **Prim's Algorithm**: หา Minimum Spanning Tree
2. **การจัดการงาน**:
   - การจัดตารางงานในระบบปฏิบัติการ โดยงานที่มีความสำคัญสูงสุดจะถูกประมวลผลก่อน
3. **การประมวลผลข้อมูลตามลำดับความสำคัญ**:
   - เช่น การประมวลผลคำสั่งในระบบที่มีระดับความสำคัญแตกต่างกัน

---

### เปรียบเทียบกับ Queue ธรรมดา
| คุณสมบัติ         | Queue (std::queue)       | Priority Queue (std::priority_queue) |
|-------------------|--------------------------|--------------------------------------|
| **ลักษณะ**       | FIFO (First In, First Out) | ตามลำดับความสำคัญ                  |
| **การเพิ่มข้อมูล** | ท้าย                    | ตามลำดับความสำคัญ (Heap)            |
| **การลบข้อมูล**   | หน้า                    | ข้อมูลที่มีลำดับความสำคัญสูงสุด      |
| **การเข้าถึง**    | `front()`, `back()`     | `top()` (เฉพาะข้อมูลสูงสุด)         |
| **ความซับซ้อน**   | O(1) (เพิ่ม/ลบ)         | O(log n) (เพิ่ม/ลบ)                 |

---

### สรุป
**Priority Queue** เป็นโครงสร้างข้อมูลที่มีประโยชน์เมื่อต้องการจัดการข้อมูลตามลำดับความสำคัญ โดยใช้ Heap เป็นโครงสร้างพื้นฐานเพื่อให้การเพิ่มและลบข้อมูลมีประสิทธิภาพ (O(log n)) ใน C++ สามารถใช้งานได้ง่ายผ่าน `std::priority_queue` และสามารถปรับแต่งลำดับความสำคัญได้ตามต้องการด้วย custom comparator เหมาะสำหรับงานที่ต้องการการประมวลผลตามลำดับความสำคัญ เช่น การจัดการงานหรืออัลกอริทึมกราฟ

หากต้องการตัวอย่างเพิ่มเติมหรือคำอธิบายในส่วนใดเพิ่มเติม สามารถแจ้งได้ครับ!