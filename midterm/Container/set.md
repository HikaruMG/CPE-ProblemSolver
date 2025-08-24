ในภาษา C++ โครงสร้างข้อมูล **Set** ถูก implement ผ่าน Standard Template Library (STL) ด้วยคลาส `std::set` และ `std::multiset` ซึ่งอยู่ใน header `<set>` รวมถึงคลาสที่เกี่ยวข้องอย่าง `std::unordered_set` และ `std::unordered_multiset` (อยู่ใน header `<unordered_set>`) ซึ่งทั้งหมดนี้ใช้สำหรับเก็บข้อมูลที่ไม่ซ้ำกัน (หรือซ้ำได้ในกรณี multiset) และมีคุณสมบัติแตกต่างกันไปตามประเภท ผมจะรวมคำสั่ง (methods/functions) ที่เกี่ยวข้องกับ Set ใน C++ พร้อมคำอธิบายและตัวอย่างการใช้งาน

---

### 1. `std::set`
#### คำจำกัดความ
- `std::set` เป็น container ที่เก็บข้อมูลแบบ **ไม่ซ้ำกัน** (unique) และเรียงลำดับอัตโนมัติ (โดยค่าเริ่มต้นเรียงจากน้อยไปมาก)
- ใช้ **Red-Black Tree** เป็นโครงสร้างพื้นฐาน ทำให้การเพิ่ม, ลบ, และค้นหามีความซับซ้อน O(log n)

#### คำสั่งหลัก
| คำสั่ง/เมธอด              | คำอธิบาย                                           | ความซับซ้อน |
|---------------------------|---------------------------------------------------|-------------|
| `insert(value)`           | เพิ่มข้อมูลลงใน set (หากมีอยู่แล้วจะไม่เพิ่ม)       | O(log n)    |
| `erase(value)`            | ลบข้อมูลที่ระบุ (ตามค่า)                          | O(log n)    |
| `erase(iterator)`         | ลบข้อมูลที่ตำแหน่ง iterator                       | O(1) amortized |
| `erase(first, last)`      | ลบข้อมูลในช่วง [first, last)                     | O(log n + k) (k = จำนวนข้อมูลที่ลบ) |
| `find(value)`             | ค้นหาข้อมูล คืน iterator หากพบ หรือ end() หากไม่พบ | O(log n)    |
| `count(value)`            | นับจำนวนข้อมูลที่ระบุ (0 หรือ 1 เพราะไม่ซ้ำกัน)   | O(log n)    |
| `size()`                  | คืนค่าขนาดของ set                                 | O(1)        |
| `empty()`                 | ตรวจสอบว่า set ว่างหรือไม่                        | O(1)        |
| `clear()`                 | ลบข้อมูลทั้งหมดใน set                             | O(n)        |
| `begin()`                 | คืน iterator ชี้ไปยังข้อมูลแรก                     | O(1)        |
| `end()`                   | คืน iterator ชี้ไปยังตำแหน่งหลังข้อมูลสุดท้าย     | O(1)        |
| `rbegin()`                | คืน reverse iterator ชี้ไปยังข้อมูลสุดท้าย         | O(1)        |
| `rend()`                  | คืน reverse iterator ชี้ไปยังตำแหน่งก่อนข้อมูลแรก | O(1)        |
| `lower_bound(value)`      | คืน iterator ชี้ไปยังข้อมูลที่ >= value           | O(log n)    |
| `upper_bound(value)`      | คืน iterator ชี้ไปยังข้อมูลที่ > value            | O(log n)    |
| `equal_range(value)`      | คืน pair ของ lower_bound และ upper_bound          | O(log n)    |

#### ตัวอย่าง
```cpp
#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;
    
    // เพิ่มข้อมูล
    s.insert(5);
    s.insert(2);
    s.insert(9);
    s.insert(2); // 2 มีอยู่แล้ว จะไม่ถูกเพิ่มซ้ำ
    
    // แสดงข้อมูล (เรียงลำดับอัตโนมัติ)
    cout << "Set elements: ";
    for(int x : s) cout << x << " ";
    cout << endl;
    
    // ค้นหาและลบ
    if(s.find(5) != s.end()) {
        s.erase(5);
        cout << "After erasing 5: ";
        for(int x : s) cout << x << " ";
        cout << endl;
    }
    
    return 0;
}
```
**ผลลัพธ์**:
```
Set elements: 2 5 9
After erasing 5: 2 9
```

---

### 2. `std::multiset`
#### คำจำกัดความ
- `std::multiset` คล้าย `std::set` แต่สามารถเก็บข้อมูลที่ **ซ้ำกัน** ได้ และยังคงเรียงลำดับอัตโนมัติ
- ใช้ **Red-Black Tree** เช่นกัน

#### คำสั่งหลัก
เหมือนกับ `std::set` แต่มีข้อแตกต่างในบางคำสั่ง:
| คำสั่ง/เมธอด              | คำอธิบาย                                           | ความซับซ้อน |
|---------------------------|---------------------------------------------------|-------------|
| `insert(value)`           | เพิ่มข้อมูล (ซ้ำได้)                              | O(log n)    |
| `count(value)`            | นับจำนวนข้อมูลที่ระบุ (อาจมากกว่า 1)              | O(log n + k) (k = จำนวนข้อมูลซ้ำ) |
| `erase(value)`            | ลบข้อมูลทั้งหมดที่มีค่าตรงกับ value              | O(log n + k) |

#### ตัวอย่าง
```cpp
#include <iostream>
#include <set>
using namespace std;

int main() {
    multiset<int> ms;
    
    // เพิ่มข้อมูล (ซ้ำได้)
    ms.insert(5);
    ms.insert(2);
    ms.insert(5);
    ms.insert(2);
    
    // แสดงข้อมูล
    cout << "Multiset elements: ";
    for(int x : ms) cout << x << " ";
    cout << endl;
    
    // นับจำนวน 5
    cout << "Count of 5: " << ms.count(5) << endl;
    
    // ลบ 5 ทั้งหมด
    ms.erase(5);
    cout << "After erasing 5: ";
    for(int x : ms) cout << x << " ";
    cout << endl;
    
    return 0;
}
```
**ผลลัพธ์**:
```
Multiset elements: 2 2 5 5
Count of 5: 2
After erasing 5: 2 2
```

---

### 3. `std::unordered_set`
#### คำจำกัดความ
- `std::unordered_set` เป็น container ที่เก็บข้อมูลแบบ **ไม่ซ้ำกัน** แต่ไม่มีการเรียงลำดับ
- ใช้ **Hash Table** เป็นโครงสร้างพื้นฐาน ทำให้การเพิ่ม, ลบ, และค้นหามีความซับซ้อน O(1) โดยเฉลี่ย

#### คำสั่งหลัก
| คำสั่ง/เมธอด              | คำอธิบาย                                           | ความซับซ้อน |
|---------------------------|---------------------------------------------------|-------------|
| `insert(value)`           | เพิ่มข้อมูล (หากมีอยู่แล้วจะไม่เพิ่ม)              | O(1) avg, O(n) worst |
| `erase(value)`            | ลบข้อมูลที่ระบุ (ตามค่า)                          | O(1) avg, O(n) worst |
| `erase(iterator)`         | ลบข้อมูลที่ตำแหน่ง iterator                       | O(1)        |
| `erase(first, last)`      | ลบข้อมูลในช่วง [first, last)                     | O(k) (k = จำนวนข้อมูลที่ลบ) |
| `find(value)`             | ค้นหาข้อมูล คืน iterator หากพบ หรือ end() หากไม่พบ | O(1) avg, O(n) worst |
| `count(value)`            | นับจำนวนข้อมูลที่ระบุ (0 หรือ 1 เพราะไม่ซ้ำกัน)   | O(1) avg, O(n) worst |
| `size()`                  | คืนค่าขนาดของ unordered_set                       | O(1)        |
| `empty()`                 | ตรวจสอบว่า unordered_set ว่างหรือไม่              | O(1)        |
| `clear()`                 | ลบข้อมูลทั้งหมดใน unordered_set                   | O(n)        |
| `begin()`                 | คืน iterator ชี้ไปยังข้อมูลแรก                     | O(1)        |
| `end()`                   | คืน iterator ชี้ไปยังตำแหน่งหลังข้อมูลสุดท้าย     | O(1)        |
| `bucket_count()`          | คืนจำนวน bucket ใน hash table                     | O(1)        |
| `load_factor()`           | คืนค่า load factor ปัจจุบัน                       | O(1)        |

#### ตัวอย่าง
```cpp
#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unordered_set<int> us;
    
    // เพิ่มข้อมูล
    us.insert(5);
    us.insert(2);
    us.insert(9);
    us.insert(2); // 2 มีอยู่แล้ว จะไม่ถูกเพิ่ม
    
    // แสดงข้อมูล (ไม่เรียงลำดับ)
    cout << "Unordered Set elements: ";
    for(int x : us) cout << x << " ";
    cout << endl;
    
    // ค้นหาและลบ
    if(us.find(5) != us.end()) {
        us.erase(5);
        cout << "After erasing 5: ";
        for(int x : us) cout << x << " ";
        cout << endl;
    }
    
    return 0;
}
```
**ผลลัพธ์** (ลำดับอาจแตกต่างกัน):
```
Unordered Set elements: 9 2 5
After erasing 5: 9 2
```

---

### 4. `std::unordered_multiset`
#### คำจำกัดความ
- `std::unordered_multiset` คล้าย `std::unordered_set` แต่สามารถเก็บข้อมูลที่ **ซ้ำกัน** ได้ และไม่มีการเรียงลำดับ
- ใช้ **Hash Table** เช่นกัน

#### คำสั่งหลัก
เหมือนกับ `std::unordered_set` แต่มีข้อแตกต่าง:
| คำสั่ง/เมธอด              | คำอธิบาย                                           | ความซับซ้อน |
|---------------------------|---------------------------------------------------|-------------|
| `insert(value)`           | เพิ่มข้อมูล (ซ้ำได้)                              | O(1) avg, O(n) worst |
| `count(value)`            | นับจำนวนข้อมูลที่ระบุ (อาจมากกว่า 1)              | O(1) avg, O(n) worst |
| `erase(value)`            | ลบข้อมูลทั้งหมดที่มีค่าตรงกับ value              | O(1) avg, O(n) worst |

#### ตัวอย่าง
```cpp
#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unordered_multiset<int> ums;
    
    // เพิ่มข้อมูล (ซ้ำได้)
    ums.insert(5);
    ums.insert(2);
    ums.insert(5);
    ums.insert(2);
    
    // แสดงข้อมูล
    cout << "Unordered Multiset elements: ";
    for(int x : ums) cout << x << " ";
    cout << endl;
    
    // นับจำนวน 5
    cout << "Count of 5: " << ums.count(5) << endl;
    
    // ลบ 5 ทั้งหมด
    ums.erase(5);
    cout << "After erasing 5: ";
    for(int x : ums) cout << x << " ";
    cout << endl;
    
    return 0;
}
```
**ผลลัพธ์** (ลำดับอาจแตกต่างกัน):
```
Unordered Multiset elements: 5 5 2 2
Count of 5: 2
After erasing 5: 2 2
```

---

### 5. การกำหนด Comparator หรือ Hash Function
- **`std::set` และ `std::multiset`**:
  - สามารถกำหนด comparator เพื่อเปลี่ยนลำดับการเรียงได้
  - ตัวอย่าง: `set<int, greater<int>>` (เรียงจากมากไปน้อย)
- **`std::unordered_set` และ `std::unordered_multiset`**:
  - สามารถกำหนด hash function และ equality predicate ได้
  - ตัวอย่าง: `unordered_set<int, MyHash, MyEqual>`

#### ตัวอย่าง Custom Comparator
```cpp
#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int, greater<int>> s; // เรียงจากมากไปน้อย
    
    s.insert(5);
    s.insert(2);
    s.insert(9);
    
    cout << "Set elements (descending): ";
    for(int x : s) cout << x << " ";
    cout << endl;
    
    return 0;
}
```
**ผลลัพธ์**:
```
Set elements (descending): 9 5 2
```

---

### สรุปเปรียบเทียบ
| คุณสมบัติ                  | `std::set`            | `std::multiset`       | `std::unordered_set`  | `std::unordered_multiset` |
|---------------------------|-----------------------|-----------------------|-----------------------|---------------------------|
| **การเก็บข้อมูลซ้ำ**       | ไม่ได้                | ได้                   | ไม่ได้                | ได้                       |
| **การเรียงลำดับ**         | เรียงลำดับ (O(log n))| เรียงลำดับ (O(log n))| ไม่เรียงลำดับ (O(1)) | ไม่เรียงลำดับ (O(1))     |
| **โครงสร้างพื้นฐาน**       | Red-Black Tree       | Red-Black Tree       | Hash Table           | Hash Table               |
| **ความซับซ้อน (เพิ่ม/ลบ)** | O(log n)             | O(log n)             | O(1) avg             | O(1) avg                 |
| **ความซับซ้อน (ค้นหา)**   | O(log n)             | O(log n)             | O(1) avg             | O(1) avg                 |

---

### การใช้งานจริง
- **`std::set`**: ใช้เมื่อต้องการข้อมูลที่ไม่ซ้ำกันและเรียงลำดับ เช่น การเก็บคำศัพท์ในพจนานุกรม
- **`std::multiset`**: ใช้เมื่อต้องการข้อมูลที่ซ้ำกันได้และเรียงลำดับ เช่น การนับความถี่ของคำ
- **`std::unordered_set`**: ใช้เมื่อต้องการความเร็วในการค้นหาและไม่สนใจลำดับ เช่น การตรวจสอบการมีอยู่ของข้อมูล
- **`std::unordered_multiset`**: ใช้เมื่อต้องการนับจำนวนข้อมูลที่ซ้ำกันและไม่สนใจลำดับ เช่น การนับความถี่แบบไม่เรียง

คำสั่งเหล่านี้ครอบคลุมการใช้งาน Set ใน C++ อย่างสมบูรณ์ หากต้องการตัวอย่างเพิ่มเติมหรือคำอธิบายในส่วนใด สามารถแจ้งได้ครับ!