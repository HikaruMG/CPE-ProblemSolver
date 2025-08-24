#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int main(){
    // อ่านข้อมูลอินพุต
    int R, C, A, B, X, Y;
    cin >> R >> C >> A >> B >> X >> Y;
    
    // อ่านแผนที่และเก็บใน vector 2 มิติ
    vector<vector<int>> grid(R, vector<int>(C));
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            cin >> grid[i][j];
        }
    }
    
    // หารหัสประเทศของจุดเริ่มต้นและจุดปลายทาง
    int startCountry = grid[A - 1][B - 1];  // ปรับจาก 1-based เป็น 0-based
    int targetCountry = grid[X - 1][Y - 1];
    
    // ถ้าเริ่มต้นและปลายทางอยู่ในประเทศเดียวกัน ไม่ต้องขอวีซ่า
    if(startCountry == targetCountry){
        cout << 0 << endl;
        return 0;
    }
    
    // สร้างกราฟของประเทศ
    // เนื่องจากรหัสประเทศมีค่าสูงสุดไม่เกิน R*C เราจึงใช้ vector<set<int>> เพื่อเก็บเพื่อนบ้านของแต่ละประเทศ
    int maxCountry = R * C;
    vector<set<int>> graph(maxCountry + 1);
    
    // กำหนดทิศที่สามารถเดินได้ 4 ทิศ: ขึ้น, ลง, ซ้าย, ขวา
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    // วนซ้ำทุกช่องเพื่อตรวจสอบเพื่อนบ้าน
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            int curr = grid[i][j];
            for (int k = 0; k < 4; k++){
                int ni = i + dx[k], nj = j + dy[k];
                // ตรวจสอบว่าอยู่ในขอบเขตของแผนที่หรือไม่
                if(ni >= 0 && ni < R && nj >= 0 && nj < C){
                    int neighbor = grid[ni][nj];
                    // ถ้าเพื่อนบ้านอยู่ในประเทศที่แตกต่างกันให้เพิ่มขอบเชื่อม
                    if(neighbor != curr){
                        graph[curr].insert(neighbor);
                    }
                }
            }
        }
    }
    
    // ใช้ BFS ในการค้นหาจำนวนวีซ่า (คือจำนวนการข้ามประเทศ)
    // visa[i] เก็บจำนวนวีซ่าที่ต้องใช้ในการไปถึงประเทศ i
    vector<int> visa(maxCountry + 1, -1);
    queue<int> q;
    visa[startCountry] = 0; // ไม่ต้องขอวีซ่าสำหรับประเทศเริ่มต้น
    q.push(startCountry);
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        // ตรวจสอบเพื่อนบ้านของประเทศ cur
        for(auto nxt : graph[cur]){
            if(visa[nxt] == -1){ // ถ้ายังไม่เข้าเยี่ยมประเทศนี้
                visa[nxt] = visa[cur] + 1;
                // ถ้าเป็นประเทศปลายทางก็แสดงผลและจบโปรแกรม
                if(nxt == targetCountry){
                    cout << visa[nxt] << endl;
                    return 0;
                }
                q.push(nxt);
            }
        }
    }
    
    // กรณีที่ไม่สามารถเดินทางไปถึง (ตามโจทย์รับประกันว่ามีเส้นทางเดิน)
    cout << visa[targetCountry] << endl;
    return 0;
}
