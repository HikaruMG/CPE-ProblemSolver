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