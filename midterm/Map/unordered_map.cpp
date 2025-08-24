#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int, string> um;

    // แทรกข้อมูล
    um[3] = "Charlie";
    um[1] = "Alice";
    um[2] = "Bob";

    // พิมพ์ข้อมูล (ไม่เรียงลำดับ)
    for (auto& pair : um) {
        cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
    }

    // ค้นหาคีย์
    auto it = um.find(2);
    if (it != um.end()) {
        cout << "Found: " << it->second << endl;
    } else {
        cout << "Not found" << endl;
    }

    return 0;
}