#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    unordered_map<long long, int> like_count; // เก็บจำนวน Like ของแต่ละ status
    long long max_status = 0; // เก็บหมายเลข status ที่มีจำนวน Like มากที่สุด
    int max_likes = 0;        // เก็บจำนวน Like มากที่สุด

    vector<long long> results; // เก็บผลลัพธ์

    for (int i = 0; i < N; ++i) {
        long long status;
        cin >> status;

        // เพิ่มจำนวน Like ให้กับ status นี้
        like_count[status]++;

        // อัปเดต status ที่มีจำนวน Like มากที่สุด
        if (like_count[status] > max_likes || 
           (like_count[status] == max_likes && status > max_status)) {
            max_likes = like_count[status];
            max_status = status;
        }

        // บันทึก status ที่มีจำนวน Like มากที่สุดในปัจจุบัน
        results.push_back(max_status);
    }

    // แสดงผลลัพธ์
    for (long long status : results) {
        cout << status << endl;
    }

    return 0;
}
