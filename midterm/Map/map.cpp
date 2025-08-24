#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, string> m;

    // แทรกข้อมูล
    m[3] = "Charlie";
    m[1] = "Alice";
    m[2] = "Bob";

    // พิมพ์ข้อมูล (เรียงตามคีย์)
    for (auto& pair : m) {
        cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
    }

    // ค้นหาคีย์
    auto it = m.find(2);
    if (it != m.end()) {
        cout << "Found: " << it->second << endl;
    } else {
        cout << "Not found" << endl;
    }

    return 0;
}