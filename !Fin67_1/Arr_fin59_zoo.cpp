#include <iostream>
using namespace std;

int main() {
    int R, C, B, T;
    cin >> R >> C >> B >> T; // รับค่า R, C, B, T
    
    // สร้าง array 2D ขนาด R × C
    int grid[10][10];
    int total_ostriches = 0; // นับนกทั้งหมดในลาน
    
    // รับข้อมูลตารางและนับจำนวนนกทั้งหมด
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> grid[i][j];
            total_ostriches += grid[i][j];
        }
    }
    
    int water = 0; // น้ำปัจจุบันในถัง
    int fill_count = 0; // จำนวนครั้งที่เติมน้ำ
    int ostriches_served = 0; // จำนวนนกที่ให้น้ำไปแล้ว
    
    // เริ่มต้นเติมน้ำครั้งแรก
    fill_count++;
    water = B;
    
    // เดินตามแถวและคอลัมน์
    for(int i = 0; i < R; i++) {
        bool has_ostrich_in_row = false; // ตรวจสอบว่าแถวนี้มีนกหรือไม่
        
        // ตรวจสอบว่าแถวนี้มีนกหรือไม่
        for(int j = 0; j < C; j++) {
            if(grid[i][j] > 0) {
                has_ostrich_in_row = true;
                break;
            }
        }
        
        if(!has_ostrich_in_row) continue; // ถ้าไม่มีนกในแถว ข้ามไป
        
        // ประมวลผลนกในแถวนี้
        for(int j = 0; j < C; j++) {
            // ให้น้ำนกในช่องนี้ทีละตัว
            while(grid[i][j] > 0) {
                if(water < T) { // ถ้าน้ำไม่พอให้ตัวถัดไป
                    fill_count++;
                    water = B;
                }
                water -= T; // ให้น้ำ 1 ตัว
                grid[i][j]--; // ลดจำนวนนกในช่อง
                ostriches_served++; // นับนกที่ให้น้ำแล้ว
            }
        }
        
        // หลังจบแถว ตรวจสอบว่ายังมีนกเหลือในลานหรือไม่
        if(ostriches_served < total_ostriches) {
            fill_count++;
            water = B;
        }
    }
    
    cout << fill_count << endl;
    return 0;
}