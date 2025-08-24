#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;

// Comparator สำหรับ set เพื่อให้เรียงตามคะแนนจากมากไปน้อย
// ถ้าคะแนนเท่ากัน ให้เรียงตามหมายเลขหนังสือจากน้อยไปมาก
struct cmp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        if(a.first != b.first)
            return a.first > b.first; // มากก่อน
        return a.second < b.second;   // ถ้าคะแนนเท่ากัน เล็กก่อน
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, L;
    cin >> N >> M >> L;

    // Map สำหรับเก็บคะแนนในหน้าต่างปัจจุบัน
    unordered_map<int, int> freq;
    // set สำหรับจัดอันดับหนังสือในหน้าต่างปัจจุบัน
    set<pair<int, int>, cmp> ranking;

    // สำหรับเก็บคำตอบสุดท้าย
    int bestBook = 0, bestVotes = -1;

    int vote;
    // Array สำหรับเก็บข้อมูลโหวต เพื่อให้สามารถลบออกได้ตามตำแหน่ง
     int* votes = new int[N];
    //int votes[N];
    
    for (int i = 0; i < N; i++){
        cin >> votes[i];
    }
    // for (int i = 0; i < N; i++){
    //     cout << votes[i] << " ";
    // }
    // cout << endl;
    
    for (int i = 0; i < N; i++){
        int book = votes[i];
        // หากหนังสือมีอยู่ใน map อยู่แล้ว ให้เอาคู่เดิมออกจาก ranking
        if(freq.count(book)){
            ranking.erase({freq[book], book});
        }
        // เพิ่มจำนวนโหวตของหนังสือเล่มนั้น
        freq[book] = freq[book] + 1;
        // ใส่คู่ข้อมูลใหม่เข้า ranking
        ranking.insert({freq[book], book});
        
        // เมื่อหน้าต่างมีขนาดเกิน M ให้ลบโหวตที่อยู่ด้านซ้ายสุดออก
        if(i >= M){
            int outBook = votes[i - M];
            ranking.erase({freq[outBook], outBook});
            freq[outBook]--;
            // หากจำนวนโหวตยังคงเหลือ ให้เพิ่มกลับเข้าไปใน ranking
            if(freq[outBook] > 0)
                ranking.insert({freq[outBook], outBook});
        }
        
        // เมื่อมีหน้าต่างครบ M โหวตแล้ว (เริ่ม i = M-1)
        if(i >= M - 1){
            // Candidate คือหนังสือที่อยู่หัว ranking (มีคะแนนสูงสุดและถ้าคะแนนเท่ากัน เล็กสุด)
            auto candidate = *ranking.begin();
            int curVotes = candidate.first;
            int curBook = candidate.second;
            // บันทึกผลถ้าคะแนนในหน้าต่างนี้สูงกว่า หรือเท่ากันแต่หมายเลขหนังสือเล็กกว่า
            if(curVotes > bestVotes || (curVotes == bestVotes && curBook < bestBook)){
                bestVotes = curVotes;
                bestBook = curBook;
            }
        }
    }
    
    cout << bestBook << " " << bestVotes << "\n";
    
    delete[] votes;
    return 0;
}
