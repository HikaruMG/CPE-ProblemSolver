#include <iostream>
#include <unordered_map>
#include <deque>
using namespace std;

int main() {
    int N, M; // N = ขนาดของ cache, M = จำนวนคำขอ
    cin >> N >> M;

    unordered_map<int, deque<int>::iterator> cache; // เก็บหน้าเว็บใน cache และลำดับที่
    deque<int> order; // เก็บลำดับหน้าเว็บที่ถูกใช้งาน

    int misses = 0; // นับจำนวน miss

    for (int i = 0; i < M; ++i) {
        int page;
        cin >> page;

        if (cache.find(page) != cache.end()) {
            // hit: ลบหน้าออกจาก deque และเพิ่มกลับท้าย (update ลำดับ)
            order.erase(cache[page]); // ลบหน้าเว็บออกจาก deque
            order.push_back(page); // เพิ่มไปที่ท้าย deque
            cache[page] = --order.end(); // อัปเดตตำแหน่งใหม่
        } else {
            // miss: เพิ่มหน้าใหม่เข้า cache
            misses++;
            if (order.size() == N) {
                // ลบหน้าเก่าที่สุดออก (ถ้า cache เต็ม)
                int oldest = order.front();
                order.pop_front();
                cache.erase(oldest); // ลบจาก cache
            }
            // เพิ่มหน้าใหม่เข้า deque และ cache
            order.push_back(page);
            cache[page] = --order.end(); // บันทึกตำแหน่งของหน้าใหม่
        }
    }

    cout << misses << endl;
    return 0;
}
