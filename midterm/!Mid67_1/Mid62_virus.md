### คำอธิบายโจทย์และขั้นตอนการคิด

โจทย์นี้เกี่ยวข้องกับการจัดการรายการข้อมูลที่เก็บในรูปแบบจำนวนเต็มบวก โดยมีไวรัสที่สามารถแก้ไขข้อมูลในรายการได้ผ่านคำสั่ง 4 ประเภท: `reset`, `next`, `insertBefore(x)`, และ `insertAfter(x)` เราต้องออกแบบโปรแกรมในภาษา C++ เพื่อรับข้อมูลเริ่มต้นและคำสั่งจากไวรัส แล้วพิมพ์รายการข้อมูลสุดท้ายหลังจากประมวลผลคำสั่งทั้งหมด

#### การวิเคราะห์โจทย์
1. **ข้อมูลเริ่มต้น:**
   - รับจำนวนเต็ม `N` (ขนาดเริ่มต้นของรายการ) และ `M` (จำนวนคำสั่ง)
   - รับจำนวนเต็มบวก `N` จำนวน เป็นข้อมูลในรายการเริ่มต้น
   - ไวรัสเริ่มต้นที่ข้อมูลตัวแรก

2. **คำสั่งของไวรัส:**
   - `reset` (T=1): ย้ายไวรัสไปที่ข้อมูลตัวแรก
   - `next` (T=2): ย้ายไวรัสไปที่ข้อมูลตัวถัดไป ถ้าอยู่ท้ายรายการจะวนกลับไปตัวแรก
   - `insertBefore(x)` (T=3): แทรก `x` ก่อนตำแหน่งปัจจุบันของไวรัส โดยไวรัสยังอยู่ที่ข้อมูลตัวเดิม
   - `insertAfter(x)` (T=4): แทรก `x` หลังตำแหน่งปัจจุบันของไวรัส โดยไวรัสยังอยู่ที่ข้อมูลตัวเดิม

3. **ผลลัพธ์:**
   - พิมพ์รายการข้อมูลสุดท้าย โดยเริ่มจากข้อมูลตัวแรกและไล่ไปจนครบทุกตัว

4. **ข้อจำกัด:**
   - `1 <= N, M <= 100,000`
   - ข้อมูลทุกตัวอยู่ระหว่าง `0` ถึง `1,000,000,000`

#### การเลือกโครงสร้างข้อมูล
เนื่องจาก:
- `N` และ `M` มีขนาดใหญ่ (สูงสุด 100,000) ดังนั้นการดำเนินการแต่ละครั้งควรมีประสิทธิภาพสูง
- ต้องรองรับการแทรกข้อมูลทั้งก่อนและหลังตำแหน่งปัจจุบัน
- การเคลื่อนที่ด้วย `next` เป็นแบบวนลูป (circular)

โครงสร้างข้อมูลที่เหมาะสมคือ **Circular Doubly Linked List** เพราะ:
- **การแทรก:** สามารถแทรกก่อนหรือหลังโหนดได้ใน O(1) หากมี pointer ไปยังตำแหน่งปัจจุบัน
- **การวนลูป:** การเชื่อมโยงแบบวงกลมช่วยให้ `next` สามารถวนกลับไปตัวแรกได้โดยอัตโนมัติ
- **การย้ายตำแหน่ง:** สามารถเข้าถึงโหนดก่อนหน้าและถัดไปได้ทันทีผ่าน pointer `prev` และ `next`

#### ขั้นตอนการออกแบบโปรแกรม
1. **สร้าง Circular Doubly Linked List:**
   - โหนดแต่ละตัวมีข้อมูล (`value`), pointer ไปยังโหนดก่อนหน้า (`prev`), และโหนดถัดไป (`next`)
   - เก็บ pointer `head` (โหนดแรก) และ `current` (ตำแหน่งปัจจุบันของไวรัส)

2. **ฟังก์ชันที่ต้องพัฒนา:**
   - `reset`: ตั้ง `current` ไปที่ `head`
   - `next`: ย้าย `current` ไปที่ `current->next`
   - `insertBefore(x)`: แทรก `x` ก่อน `current` และอัพเดท pointer
   - `insertAfter(x)`: แทรก `x` หลัง `current` และอัพเดท pointer
   - `printList`: พิมพ์ข้อมูลทั้งหมดโดยเริ่มจาก `head`

3. **การประมวลผล:**
   - อ่านข้อมูลเริ่มต้น `N` จำนวน และสร้าง linked list
   - อ่านและประมวลผลคำสั่ง `M` คำสั่ง
   - พิมพ์ผลลัพธ์สุดท้าย

### โค้ด C++ และคำอธิบาย

```cpp
#include <iostream>
using namespace std;

class Node {
public:
    int value;         // ค่าข้อมูล
    Node* prev;        // pointer ไปยังโหนดก่อนหน้า
    Node* next;        // pointer ไปยังโหนดถัดไป
    Node(int val) : value(val), prev(nullptr), next(nullptr) {} // Constructor
};

class CircularDoublyLinkedList {
public:
    Node* head;    // โหนดแรกของรายการ
    Node* current; // ตำแหน่งปัจจุบันของไวรัส

    CircularDoublyLinkedList() : head(nullptr), current(nullptr) {}

    // เพิ่มโหนดใหม่ที่ท้ายรายการและทำให้เป็นวงกลม
    void append(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            head->next = head;
            head->prev = head;
            current = head;
        } else {
            Node* tail = head->prev;
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
        }
    }

    // ย้ายไวรัสไปที่ข้อมูลตัวแรก
    void reset() {
        current = head;
    }

    // ย้ายไวรัสไปที่ข้อมูลตัวถัดไป
    void next() {
        current = current->next;
    }

    // แทรก x ก่อนตำแหน่งปัจจุบัน
    void insertBefore(int x) {
        Node* newNode = new Node(x);
        Node* prevNode = current->prev;
        prevNode->next = newNode;
        newNode->prev = prevNode;
        newNode->next = current;
        current->prev = newNode;
        if (current == head) {
            head = newNode; // อัพเดท head ถ้าแทรกก่อนตัวแรก
        }
    }

    // แทรก x หลังตำแหน่งปัจจุบัน
    void insertAfter(int x) {
        Node* newNode = new Node(x);
        Node* nextNode = current->next;
        current->next = newNode;
        newNode->prev = current;
        newNode->next = nextNode;
        nextNode->prev = newNode;
    }

    // พิมพ์รายการทั้งหมด
    void printList() {
        if (!head) return;
        Node* temp = head;
        do {
            cout << temp->value << endl;
            temp = temp->next;
        } while (temp != head);
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    CircularDoublyLinkedList list;

    // อ่านข้อมูลเริ่มต้น
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        list.append(val);
    }

    // ประมวลผลคำสั่ง
    for (int i = 0; i < M; ++i) {
        int T;
        cin >> T;
        if (T == 1) {
            list.reset();
        } else if (T == 2) {
            list.next();
        } else if (T == 3 || T == 4) {
            int x;
            cin >> x;
            if (T == 3) {
                list.insertBefore(x);
            } else {
                list.insertAfter(x);
            }
        }
    }

    // พิมพ์ผลลัพธ์
    list.printList();
    return 0;
}
```

#### คำอธิบายโค้ดทีละส่วน
1. **class Node:**
   - ตัวแปร:
     - `int value`: เก็บค่าข้อมูล
     - `Node* prev`: ชี้ไปยังโหนดก่อนหน้า
     - `Node* next`: ชี้ไปยังโหนดถัดไป
   - Constructor: กำหนดค่าเริ่มต้นให้ `value` และตั้ง `prev`, `next` เป็น `nullptr`

2. **class CircularDoublyLinkedList:**
   - ตัวแปร:
     - `Node* head`: ชี้ไปยังโหนดแรก
     - `Node* current`: ชี้ไปยังตำแหน่งปัจจุบันของไวรัส
   - ฟังก์ชัน:
     - **`append(int val)`**: เพิ่มโหนดใหม่
       - ถ้าเป็นโหนดแรก: ตั้ง `head` และทำให้ `next`, `prev` ชี้กลับมาที่ตัวเอง
       - ถ้ามีโหนดอยู่แล้ว: แทรกที่ท้ายและเชื่อมโยงให้เป็นวงกลม
     - **`reset()`**: ตั้ง `current` เป็น `head`
     - **`next()`**: ย้าย `current` ไปที่ `current->next`
     - **`insertBefore(int x)`**: แทรก `x` ก่อน `current`
       - สร้างโหนดใหม่และเชื่อมโยงกับ `current->prev` และ `current`
       - อัพเดท `head` หาก `current` เป็นโหนดแรก
     - **`insertAfter(int x)`**: แทรก `x` หลัง `current`
       - สร้างโหนดใหม่และเชื่อมโยงกับ `current` และ `current->next`
     - **`printList()`**: พิมพ์ข้อมูลทั้งหมด
       - เริ่มจาก `head` และวนจนครบรอบ

3. **main:**
   - อ่าน `N` และ `M`
   - สร้าง linked list และเพิ่มข้อมูลเริ่มต้น `N` จำนวน
   - อ่านคำสั่ง `M` คำสั่งและดำเนินการตาม `T`
   - พิมพ์ผลลัพธ์

### ตัวอย่างการทำงาน
**Input:**
```
3 11
1 2 3
3 100
2
4 500
1
2
2
2
2
3 50
2
4 99
```

**ขั้นตอนการทำงาน:**
1. **สร้างรายการเริ่มต้น:** `1 <-> 2 <-> 3 <-> 1...`, `current = 1`
2. **3 100:** `insertBefore(100)` → `100 <-> 1 <-> 2 <-> 3 <-> 100...`, `current = 1`
3. **2:** `next` → `current = 2`
4. **4 500:** `insertAfter(500)` → `100 <-> 1 <-> 2 <-> 500 <-> 3 <-> 100...`, `current = 2`
5. **1:** `reset` → `current = 100`
6. **2:** `next` → `current = 1`
7. **2:** `next` → `current = 2`
8. **2:** `next` → `current = 500`
9. **2:** `next` → `current = 3`
10. **3 50:** `insertBefore(50)` → `100 <-> 1 <-> 2 <-> 500 <-> 50 <-> 3 <-> 100...`, `current = 3`
11. **2:** `next` → `current = 100`
12. **4 99:** `insertAfter(99)` → `100 <-> 99 <-> 1 <-> 2 <-> 500 <-> 50 <-> 3 <-> 100...`, `current = 100`

**Output:**
```
100
99
1
2
500
50
3
```

### สรุป
การใช้ **Circular Doubly Linked List** ทำให้สามารถจัดการคำสั่งทั้งหมดได้ในเวลา O(1) ต่อการดำเนินการ ซึ่งเหมาะสมกับข้อจำกัดของโจทย์ที่มี `N` และ `M` สูงสุดถึง 100,000 และโค้ดนี้สามารถรับมือกับกรณีต่าง ๆ ได้อย่างถูกต้องตามที่โจทย์ระบุ