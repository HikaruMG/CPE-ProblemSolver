ในภาษา C++ มีฟังก์ชันและเมธอดที่เกี่ยวข้องกับการ **เรียงลำดับ (sorting)** อยู่หลายตัว โดยส่วนใหญ่มาจาก Standard Template Library (STL) ซึ่งอยู่ใน header `<algorithm>` และบางส่วนอยู่ใน container เฉพาะ เช่น `std::list` หรือ `std::priority_queue` ผมจะรวมฟังก์ชันหลักที่ใช้สำหรับการเรียงลำดับทั้งหมด พร้อมคำอธิบายและตัวอย่างการใช้งาน

---

### 1. ฟังก์ชันใน `<algorithm>`
Header `<algorithm>` มีฟังก์ชันที่ใช้สำหรับการเรียงลำดับข้อมูลใน container ต่างๆ เช่น array, vector, หรือ iterator range

#### 1.1 `std::sort`
- **คำอธิบาย**: เรียงลำดับข้อมูลในช่วง (range) ที่กำหนด โดยค่าเริ่มต้นจะเรียงจากน้อยไปมาก (ascending order)
- **รูปแบบ**:
  ```cpp
  void sort(RandomAccessIterator first, RandomAccessIterator last);
  void sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp);
  ```
- **พารามิเตอร์**:
  - `first`: Iterator ชี้ไปยังตำแหน่งเริ่มต้น
  - `last`: Iterator ชี้ไปยังตำแหน่งสิ้นสุด (ไม่รวมตำแหน่งนี้)
  - `comp` (optional): ฟังก์ชันเปรียบเทียบ (comparator) เพื่อกำหนดลำดับการเรียง
- **ความซับซ้อน**: O(n log n) โดยเฉลี่ย (ใช้ Introsort ซึ่งผสม QuickSort, HeapSort, และ Insertion Sort)
- **ตัวอย่าง**:
  ```cpp
  #include <iostream>
  #include <vector>
  #include <algorithm>
  using namespace std;

  int main() {
      vector<int> vec = {5, 2, 9, 1, 5, 6};
      
      // เรียงจากน้อยไปมาก (default)
      sort(vec.begin(), vec.end());
      cout << "Ascending: ";
      for(int x : vec) cout << x << " ";
      cout << endl;
      
      // เรียงจากมากไปน้อย (ใช้ comparator)
      sort(vec.begin(), vec.end(), greater<int>());
      cout << "Descending: ";
      for(int x : vec) cout << x << " ";
      cout << endl;
      
      return 0;
  }
  ```
  **ผลลัพธ์**:
  ```
  Ascending: 1 2 5 5 6 9
  Descending: 9 6 5 5 2 1
  ```

#### 1.2 `std::stable_sort`
- **คำอธิบาย**: คล้าย `std::sort` แต่รักษาลำดับสัมพัทธ์ (relative order) ของข้อมูลที่มีค่าเท่ากัน (stable sorting)
- **รูปแบบ**:
  ```cpp
  void stable_sort(RandomAccessIterator first, RandomAccessIterator last);
  void stable_sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp);
  ```
- **ความซับซ้อน**: O(n log n) หากมีหน่วยความจำเพียงพอ, O(n log² n) หากหน่วยความจำจำกัด
- **ตัวอย่าง**:
  ```cpp
  #include <iostream>
  #include <vector>
  #include <algorithm>
  using namespace std;

  struct Item {
      int value;
      int index;
  };

  int main() {
      vector<Item> vec = {{2, 1}, {1, 2}, {2, 3}, {1, 4}};
      
      // เรียงตาม value และรักษาลำดับ index
      stable_sort(vec.begin(), vec.end(), [](Item a, Item b) {
          return a.value < b.value;
      });
      
      cout << "Stable sorted: ";
      for(auto item : vec) {
          cout << "(" << item.value << ", " << item.index << ") ";
      }
      cout << endl;
      
      return 0;
  }
  ```
  **ผลลัพธ์**:
  ```
  Stable sorted: (1, 2) (1, 4) (2, 1) (2, 3)
  ```

#### 1.3 `std::partial_sort`
- **คำอธิบาย**: เรียงลำดับบางส่วนของข้อมูล โดยเรียงเฉพาะ k ตัวแรกให้ถูกต้องตามลำดับ ส่วนที่เหลือไม่จำเป็นต้องเรียง
- **รูปแบบ**:
  ```cpp
  void partial_sort(RandomAccessIterator first, RandomAccessIterator middle, RandomAccessIterator last);
  void partial_sort(RandomAccessIterator first, RandomAccessIterator middle, RandomAccessIterator last, Compare comp);
  ```
- **พารามิเตอร์**:
  - `middle`: Iterator ชี้ไปยังตำแหน่งที่ต้องการให้เรียงถึง
- **ความซับซ้อน**: O(n log k) โดย k คือระยะห่างจาก `first` ถึง `middle`
- **ตัวอย่าง**:
  ```cpp
  #include <iostream>
  #include <vector>
  #include <algorithm>
  using namespace std;

  int main() {
      vector<int> vec = {5, 2, 9, 1, 5, 6};
      
      // เรียง 3 ตัวแรกให้ถูกต้อง
      partial_sort(vec.begin(), vec.begin() + 3, vec.end());
      cout << "Partial sorted (3 elements): ";
      for(int x : vec) cout << x << " ";
      cout << endl;
      
      return 0;
  }
  ```
  **ผลลัพธ์**:
  ```
  Partial sorted (3 elements): 1 2 5 9 5 6
  ```

#### 1.4 `std::nth_element`
- **คำอธิบาย**: จัดเรียงข้อมูลให้ตำแหน่งที่ n เป็นตำแหน่งที่ถูกต้องตามลำดับ (ข้อมูลก่อน n จะน้อยกว่า และหลัง n จะมากกว่า)
- **รูปแบบ**:
  ```cpp
  void nth_element(RandomAccessIterator first, RandomAccessIterator nth, RandomAccessIterator last);
  void nth_element(RandomAccessIterator first, RandomAccessIterator nth, RandomAccessIterator last, Compare comp);
  ```
- **ความซับซ้อน**: O(n) โดยเฉลี่ย
- **ตัวอย่าง**:
  ```cpp
  #include <iostream>
  #include <vector>
  #include <algorithm>
  using namespace std;

  int main() {
      vector<int> vec = {5, 2, 9, 1, 5, 6};
      
      // จัดให้ตำแหน่งที่ 3 (index 2) ถูกต้อง
      nth_element(vec.begin(), vec.begin() + 2, vec.end());
      cout << "After nth_element (n=2): ";
      for(int x : vec) cout << x << " ";
      cout << endl;
      cout << "Element at position 2: " << vec[2] << endl;
      
      return 0;
  }
  ```
  **ผลลัพธ์**:
  ```
  After nth_element (n=2): 2 1 5 9 5 6
  Element at position 2: 5
  ```

#### 1.5 `std::is_sorted`
- **คำอธิบาย**: ตรวจสอบว่าข้อมูลในช่วงที่กำหนดถูกเรียงลำดับแล้วหรือไม่
- **รูปแบบ**:
  ```cpp
  bool is_sorted(ForwardIterator first, ForwardIterator last);
  bool is_sorted(ForwardIterator first, ForwardIterator last, Compare comp);
  ```
- **ความซับซ้อน**: O(n)
- **ตัวอย่าง**:
  ```cpp
  #include <iostream>
  #include <vector>
  #include <algorithm>
  using namespace std;

  int main() {
      vector<int> vec = {1, 2, 3, 4, 5};
      cout << "Is sorted? " << (is_sorted(vec.begin(), vec.end()) ? "Yes" : "No") << endl;
      
      vector<int> vec2 = {5, 2, 9, 1};
      cout << "Is sorted? " << (is_sorted(vec2.begin(), vec2.end()) ? "Yes" : "No") << endl;
      
      return 0;
  }
  ```
  **ผลลัพธ์**:
  ```
  Is sorted? Yes
  Is sorted? No
  ```

---

### 2. การเรียงลำดับใน Container เฉพาะ
บาง container มีเมธอดในตัวสำหรับการเรียงลำดับ

#### 2.1 `std::list::sort`
- **คำอธิบาย**: เรียงลำดับข้อมูลใน `std::list` (ใช้ Merge Sort ซึ่งเป็น stable sorting)
- **รูปแบบ**:
  ```cpp
  void sort();
  void sort(Compare comp);
  ```
- **ความซับซ้อน**: O(n log n)
- **ตัวอย่าง**:
  ```cpp
  #include <iostream>
  #include <list>
  using namespace std;

  int main() {
      list<int> lst = {5, 2, 9, 1, 5, 6};
      
      // เรียงจากน้อยไปมาก
      lst.sort();
      cout << "Ascending: ";
      for(int x : lst) cout << x << " ";
      cout << endl;
      
      // เรียงจากมากไปน้อย
      lst.sort(greater<int>());
      cout << "Descending: ";
      for(int x : lst) cout << x << " ";
      cout << endl;
      
      return 0;
  }
  ```
  **ผลลัพธ์**:
  ```
  Ascending: 1 2 5 5 6 9
  Descending: 9 6 5 5 2 1
  ```

#### 2.2 `std::priority_queue`
- **คำอธิบาย**: ไม่มีเมธอด `sort` โดยตรง แต่ข้อมูลใน `std::priority_queue` จะถูกจัดเรียงตามลำดับความสำคัญโดยอัตโนมัติ (ใช้ Heap)
- **การใช้งาน**: เพิ่มข้อมูลด้วย `push` และดึงข้อมูลด้วย `top` และ `pop`
- **ตัวอย่าง**: ดูในส่วน Priority Queue ข้างต้น

---

### 3. ฟังก์ชันที่เกี่ยวข้องกับการเรียงลำดับ
#### 3.1 `std::make_heap`, `std::push_heap`, `std::pop_heap`, `std::sort_heap`
- **คำอธิบาย**: ฟังก์ชันสำหรับจัดการ Heap ซึ่งสามารถใช้ในการเรียงลำดับได้
- **รูปแบบ**:
  ```cpp
  void make_heap(RandomAccessIterator first, RandomAccessIterator last);
  void push_heap(RandomAccessIterator first, RandomAccessIterator last);
  void pop_heap(RandomAccessIterator first, RandomAccessIterator last);
  void sort_heap(RandomAccessIterator first, RandomAccessIterator last);
  ```
- **ความซับซ้อน**:
  - `make_heap`: O(n)
  - `push_heap`: O(log n)
  - `pop_heap`: O(log n)
  - `sort_heap`: O(n log n)
- **ตัวอย่าง**:
  ```cpp
  #include <iostream>
  #include <vector>
  #include <algorithm>
  using namespace std;

  int main() {
      vector<int> vec = {5, 2, 9, 1, 5, 6};
      
      // สร้าง Max-Heap
      make_heap(vec.begin(), vec.end());
      cout << "Max-Heap: ";
      for(int x : vec) cout << x << " ";
      cout << endl;
      
      // เรียงลำดับจาก Heap
      sort_heap(vec.begin(), vec.end());
      cout << "Sorted: ";
      for(int x : vec) cout << x << " ";
      cout << endl;
      
      return 0;
  }
  ```
  **ผลลัพธ์**:
  ```
  Max-Heap: 9 5 6 1 2 5
  Sorted: 1 2 5 5 6 9
  ```

#### 3.2 `std::partition` และ `std::stable_partition`
- **คำอธิบาย**: แบ่งข้อมูลตามเงื่อนไข โดยไม่ใช่การเรียงลำดับแบบสมบูรณ์ แต่สามารถใช้ร่วมกับการเรียงลำดับได้
- **รูปแบบ**:
  ```cpp
  ForwardIterator partition(ForwardIterator first, ForwardIterator last, UnaryPredicate pred);
  ForwardIterator stable_partition(ForwardIterator first, ForwardIterator last, UnaryPredicate pred);
  ```
- **ความซับซ้อน**: O(n)
- **ตัวอย่าง**:
  ```cpp
  #include <iostream>
  #include <vector>
  #include <algorithm>
  using namespace std;

  int main() {
      vector<int> vec = {5, 2, 9, 1, 5, 6};
      
      // แบ่งข้อมูล: คู่ vs คี่
      partition(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; });
      cout << "Partitioned (even first): ";
      for(int x : vec) cout << x << " ";
      cout << endl;
      
      return 0;
  }
  ```
  **ผลลัพธ์**:
  ```
  Partitioned (even first): 6 2 9 1 5 5
  ```

---

### สรุปฟังก์ชัน Sort ใน C++
| ฟังก์ชัน/เมธอด          | คำอธิบาย                                    | ความซับซ้อน       | Container ที่ใช้ได้         |
|--------------------------|---------------------------------------------|-------------------|---------------------------|
| `std::sort`              | เรียงลำดับทั่วไป                           | O(n log n)        | Vector, Array             |
| `std::stable_sort`       | เรียงลำดับแบบ stable                      | O(n log n)        | Vector, Array             |
| `std::partial_sort`      | เรียงลำดับบางส่วน                         | O(n log k)        | Vector, Array             |
| `std::nth_element`       | จัดตำแหน่ง n ให้ถูกต้อง                    | O(n)              | Vector, Array             |
| `std::is_sorted`         | ตรวจสอบว่าข้อมูลเรียงลำดับแล้วหรือไม่     | O(n)              | Vector, Array, List       |
| `std::list::sort`        | เรียงลำดับใน list                         | O(n log n)        | List                      |
| `std::make_heap`         | สร้าง Heap                                | O(n)              | Vector, Array             |
| `std::push_heap`         | เพิ่มข้อมูลใน Heap                        | O(log n)          | Vector, Array             |
| `std::pop_heap`          | ลบข้อมูลจาก Heap                          | O(log n)          | Vector, Array             |
| `std::sort_heap`         | เรียงลำดับจาก Heap                        | O(n log n)        | Vector, Array             |
| `std::partition`         | แบ่งข้อมูลตามเงื่อนไข                     | O(n)              | Vector, Array, List       |
| `std::stable_partition`  | แบ่งข้อมูลแบบ stable                      | O(n)              | Vector, Array, List       |

---

### หมายเหตุ
- **Container ที่ใช้ได้**: 
  - `std::sort` และฟังก์ชันที่ใช้ RandomAccessIterator (เช่น `partial_sort`, `nth_element`) ใช้ได้กับ container ที่มีการเข้าถึงแบบสุ่ม เช่น `std::vector` หรือ `std::array`
  - `std::list` ใช้ `list::sort` เพราะไม่มี RandomAccessIterator
- **Comparator**: สามารถกำหนดฟังก์ชันเปรียบเทียบ (เช่น `greater<T>`) หรือ lambda function เพื่อเปลี่ยนลำดับการเรียง (ascending, descending, หรือ custom)
- **Stability**: `stable_sort` และ `stable_partition` รักษาลำดับสัมพัทธ์ของข้อมูลที่มีค่าเท่ากัน

ฟังก์ชันเหล่านี้ครอบคลุมการเรียงลำดับใน C++ เกือบทุกกรณี และสามารถเลือกใช้ตามความเหมาะสมของงาน เช่น ความเร็ว, ความเสถียร (stability), หรือการเรียงลำดับบางส่วน หากต้องการตัวอย่างเพิ่มเติมหรือคำอธิบายในส่วนใด สามารถแจ้งได้ครับ!