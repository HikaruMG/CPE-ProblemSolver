ผมจะอธิบายวิธีการเรียงลำดับ (sorting) โครงสร้างข้อมูลใน C++ ได้แก่ **Array**, **List**, **Set**, **Queue**, **Stack**, และ **Map** (ทั้งตาม key และ value) พร้อมตัวอย่างโค้ดและคำอธิบายการใช้งาน โดยแต่ละโครงสร้างข้อมูลมีวิธีการจัดการที่แตกต่างกันไปตามลักษณะของมัน

---

### 1. Array
#### ลักษณะ
- Array เป็นโครงสร้างข้อมูลแบบคงที่ (static) ที่เก็บข้อมูลในหน่วยความจำต่อเนื่อง

#### วิธีการเรียงลำดับ
- ใช้ `std::sort` จาก `<algorithm>` ซึ่งเหมาะกับข้อมูลที่ต่อเนื่องและมี Random Access Iterator

#### ตัวอย่าง
```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // เรียงจากน้อยไปมาก
    sort(arr, arr + n);
    cout << "Sorted Array (ascending): ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    
    // เรียงจากมากไปน้อย
    sort(arr, arr + n, greater<int>());
    cout << "Sorted Array (descending): ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    
    return 0;
}
```
**ผลลัพธ์**:
```
Sorted Array (ascending): 1 2 5 5 6 9
Sorted Array (descending): 9 6 5 5 2 1
```

#### ความซับซ้อน
- O(n log n)

---

### 2. List (std::list)
#### ลักษณะ
- `std::list` เป็น doubly linked list ที่ไม่มีการเข้าถึงแบบสุ่ม (random access)

#### วิธีการเรียงลำดับ
- ใช้เมธอด `sort()` ที่มีอยู่ใน `std::list` (ใช้ Merge Sort)

#### ตัวอย่าง
```cpp
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> lst = {5, 2, 9, 1, 5, 6};
    
    // เรียงจากน้อยไปมาก
    lst.sort();
    cout << "Sorted List (ascending): ";
    for(int x : lst) cout << x << " ";
    cout << endl;
    
    // เรียงจากมากไปน้อย
    lst.sort(greater<int>());
    cout << "Sorted List (descending): ";
    for(int x : lst) cout << x << " ";
    cout << endl;
    
    return 0;
}
```
**ผลลัพธ์**:
```
Sorted List (ascending): 1 2 5 5 6 9
Sorted List (descending): 9 6 5 5 2 1
```

#### ความซับซ้อน
- O(n log n)

#### หมายเหตุ
- ไม่สามารถใช้ `std::sort` กับ `std::list` ได้ เพราะไม่มี Random Access Iterator

---

### 3. Set (std::set)
#### ลักษณะ
- `std::set` เก็บข้อมูลที่ไม่ซ้ำกันและเรียงลำดับอัตโนมัติ (ใช้ Red-Black Tree)

#### วิธีการเรียงลำดับ
- ไม่จำเป็นต้องเรียงลำดับด้วยตัวเอง เพราะข้อมูลถูกเรียงลำดับโดยอัตโนมัติเมื่อเพิ่มเข้าไป
- หากต้องการเปลี่ยนลำดับ (เช่น จากมากไปน้อย) ให้กำหนด comparator ใหม่

#### ตัวอย่าง
```cpp
#include <iostream>
#include <set>
using namespace std;

int main() {
    // Set แบบเรียงจากน้อยไปมาก (default)
    set<int> s1 = {5, 2, 9, 1, 5, 6};
    cout << "Sorted Set (ascending): ";
    for(int x : s1) cout << x << " ";
    cout << endl;
    
    // Set แบบเรียงจากมากไปน้อย
    set<int, greater<int>> s2 = {5, 2, 9, 1, 5, 6};
    cout << "Sorted Set (descending): ";
    for(int x : s2) cout << x << " ";
    cout << endl;
    
    return 0;
}
```
**ผลลัพธ์**:
```
Sorted Set (ascending): 1 2 5 6 9
Sorted Set (descending): 9 6 5 2 1
```

#### ความซับซ้อน
- การเพิ่มข้อมูล: O(log n)
- ข้อมูลถูกเรียงลำดับโดยอัตโนมัติ

---

### 4. Queue (std::queue)
#### ลักษณะ
- `std::queue` เป็นโครงสร้างข้อมูลแบบ FIFO (First In, First Out) ที่ไม่มีเมธอดสำหรับการเรียงลำดับในตัว

#### วิธีการเรียงลำดับ
- ไม่มีวิธีเรียงลำดับโดยตรง ต้องย้ายข้อมูลไปยัง container อื่น (เช่น vector) แล้วเรียงลำดับ จากนั้นสร้าง queue ใหม่

#### ตัวอย่าง
```cpp
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    queue<int> q;
    q.push(5);
    q.push(2);
    q.push(9);
    q.push(1);
    
    // ย้ายข้อมูลไป vector
    vector<int> vec;
    while(!q.empty()) {
        vec.push_back(q.front());
        q.pop();
    }
    
    // เรียงลำดับ
    sort(vec.begin(), vec.end());
    
    // สร้าง queue ใหม่
    for(int x : vec) q.push(x);
    
    // แสดงผล
    cout << "Sorted Queue (ascending): ";
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    
    return 0;
}
```
**ผลลัพธ์**:
```
Sorted Queue (ascending): 1 2 5 9
```

#### ความซับซ้อน
- O(n log n) (จาก `std::sort`)
- การย้ายข้อมูล: O(n)

#### หมายเหตุ
- หากต้องการเรียงลำดับตามลำดับความสำคัญ ควรใช้ `std::priority_queue` แทน

---

### 5. Stack (std::stack)
#### ลักษณะ
- `std::stack` เป็นโครงสร้างข้อมูลแบบ LIFO (Last In, First Out) ที่ไม่มีเมธอดสำหรับการเรียงลำดับในตัว

#### วิธีการเรียงลำดับ
- คล้ายกับ queue ต้องย้ายข้อมูลไปยัง container อื่น (เช่น vector) แล้วเรียงลำดับ จากนั้นสร้าง stack ใหม่

#### ตัวอย่าง
```cpp
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    stack<int> s;
    s.push(5);
    s.push(2);
    s.push(9);
    s.push(1);
    
    // ย้ายข้อมูลไป vector
    vector<int> vec;
    while(!s.empty()) {
        vec.push_back(s.top());
        s.pop();
    }
    
    // เรียงลำดับ (จากน้อยไปมาก)
    sort(vec.begin(), vec.end());
    
    // สร้าง stack ใหม่
    for(int x : vec) s.push(x);
    
    // แสดงผล
    cout << "Sorted Stack (top is largest): ";
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    
    return 0;
}
```
**ผลลัพธ์**:
```
Sorted Stack (top is largest): 9 5 2 1
```

#### ความซับซ้อน
- O(n log n) (จาก `std::sort`)
- การย้ายข้อมูล: O(n)

#### หมายเหตุ
- Stack ไม่เหมาะกับการเรียงลำดับโดยธรรมชาติ เพราะเน้นการเข้าถึงข้อมูลจากด้านบนเท่านั้น

---

### 6. Map (std::map) - Sort by Key
#### ลักษณะ
- `std::map` เป็น container ที่เก็บข้อมูลแบบ key-value pair และเรียงลำดับตาม **key** โดยอัตโนมัติ (ใช้ Red-Black Tree)

#### วิธีการเรียงลำดับ
- ไม่จำเป็นต้องเรียงลำดับด้วยตัวเอง เพราะ key ถูกเรียงลำดับอัตโนมัติ
- หากต้องการเปลี่ยนลำดับ (เช่น จากมากไปน้อย) ให้กำหนด comparator

#### ตัวอย่าง
```cpp
#include <iostream>
#include <map>
using namespace std;

int main() {
    // Map แบบเรียง key จากน้อยไปมาก (default)
    map<int, string> m1;
    m1[5] = "Five";
    m1[2] = "Two";
    m1[9] = "Nine";
    
    cout << "Map sorted by key (ascending): ";
    for(auto p : m1) cout << "{" << p.first << ", " << p.second << "} ";
    cout << endl;
    
    // Map แบบเรียง key จากมากไปน้อย
    map<int, string, greater<int>> m2;
    m2[5] = "Five";
    m2[2] = "Two";
    m2[9] = "Nine";
    
    cout << "Map sorted by key (descending): ";
    for(auto p : m2) cout << "{" << p.first << ", " << p.second << "} ";
    cout << endl;
    
    return 0;
}
```
**ผลลัพธ์**:
```
Map sorted by key (ascending): {2, Two} {5, Five} {9, Nine}
Map sorted by key (descending): {9, Nine} {5, Five} {2, Two}
```

#### ความซับซ้อน
- การเพิ่มข้อมูล: O(log n)
- Key ถูกเรียงลำดับโดยอัตโนมัติ

---

### 7. Map (std::map) - Sort by Value
#### ลักษณะ
- `std::map` เรียงลำดับตาม key โดยอัตโนมัติ แต่ถ้าต้องการเรียงตาม value ต้องย้ายข้อมูลไปยัง container อื่น (เช่น vector) แล้วเรียงลำดับ

#### วิธีการเรียงลำดับ
- ย้ายข้อมูลจาก map ไปยัง `std::vector<std::pair>` แล้วใช้ `std::sort` พร้อม comparator เพื่อเรียงตาม value

#### ตัวอย่าง
```cpp
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    map<int, string> m;
    m[5] = "Five";
    m[2] = "Two";
    m[9] = "Nine";
    
    // ย้ายข้อมูลไป vector
    vector<pair<int, string>> vec(m.begin(), m.end());
    
    // เรียงตาม value (ascending)
    sort(vec.begin(), vec.end(), [](pair<int, string> a, pair<int, string> b) {
        return a.second < b.second;
    });
    
    cout << "Map sorted by value (ascending): ";
    for(auto p : vec) cout << "{" << p.first << ", " << p.second << "} ";
    cout << endl;
    
    // เรียงตาม value (descending)
    sort(vec.begin(), vec.end(), [](pair<int, string> a, pair<int, string> b) {
        return a.second > b.second;
    });
    
    cout << "Map sorted by value (descending): ";
    for(auto p : vec) cout << "{" << p.first << ", " << p.second << "} ";
    cout << endl;
    
    return 0;
}
```
**ผลลัพธ์**:
```
Map sorted by value (ascending): {5, Five} {9, Nine} {2, Two}
Map sorted by value (descending): {2, Two} {9, Nine} {5, Five}
```

#### ความซับซ้อน
- O(n log n) (จาก `std::sort`)
- การย้ายข้อมูล: O(n)

#### หมายเหตุ
- หากต้องการเก็บข้อมูลที่เรียงตาม value โดยอัตโนมัติ อาจต้องพิจารณาโครงสร้างข้อมูลอื่น (เช่น `std::multimap` หรือ custom container)

---

### สรุปวิธีการเรียงลำดับ
| โครงสร้างข้อมูล    | วิธีการเรียงลำดับ                              | ความซับซ้อน       | หมายเหตุ                              |
|-------------------|------------------------------------------------|-------------------|---------------------------------------|
| **Array**         | `std::sort`                                   | O(n log n)        | ใช้ได้โดยตรง                          |
| **List**          | `list::sort`                                  | O(n log n)        | มีเมธอดในตัว                         |
| **Set**           | เรียงลำดับอัตโนมัติตาม key                    | O(log n) (เพิ่ม)  | ไม่ต้องเรียงเอง                        |
| **Queue**         | ย้ายไป vector แล้วใช้ `std::sort`              | O(n log n)        | ไม่มีเมธอดในตัว                       |
| **Stack**         | ย้ายไป vector แล้วใช้ `std::sort`              | O(n log n)        | ไม่มีเมธอดในตัว                       |
| **Map (by key)**  | เรียงลำดับอัตโนมัติตาม key                    | O(log n) (เพิ่ม)  | ไม่ต้องเรียงเอง                        |
| **Map (by value)**| ย้ายไป vector แล้วใช้ `std::sort` ด้วย comparator | O(n log n)        | ต้องจัดการเอง                          |

---

### ข้อสังเกต
- **Container ที่เรียงลำดับอัตโนมัติ**: `std::set` และ `std::map` ไม่ต้องเรียงลำดับด้วยตัวเอง เพราะโครงสร้างพื้นฐาน (Red-Black Tree) จัดการให้
- **Container ที่ไม่มีเมธอดในตัว**: `std::queue` และ `std::stack` ต้องย้ายข้อมูลไปยัง container อื่นเพื่อเรียงลำดับ
- **Comparator**: สามารถใช้ `greater<T>` หรือ lambda function เพื่อกำหนดลำดับการเรียง (ascending หรือ descending)

หากต้องการตัวอย่างเพิ่มเติมหรือคำอธิบายในส่วนใดเพิ่มเติม สามารถแจ้งได้ครับ!