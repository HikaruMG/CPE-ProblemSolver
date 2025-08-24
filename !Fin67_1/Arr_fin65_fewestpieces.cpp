#include <iostream>
using namespace std;

// กำหนดขนาดสูงสุดของตาราง
const int MAX_ROW = 100;
const int MAX_COL = 100;

void processMatrix(int matrix[][MAX_COL], int rows, int cols) {
    // เริ่มจากแถวที่ 1 (index 1) เพราะแถว 0 ไม่เปลี่ยน
    for(int i = 1; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            // ถ้าค่าน้อยกว่าค่าในแถวก่อนหน้าในคอลัมน์เดียวกัน
            if(matrix[i][j] < matrix[i-1][j]) {
                matrix[i][j] = matrix[i-1][j]; // แทนที่ด้วยค่าจากแถวก่อนหน้า
            }
        }
    }
}

void printMatrix(int matrix[][MAX_COL], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int rows, cols;
    
    // รับจำนวนแถวและคอลัมน์
    cin >> rows >> cols;
    
    // ตรวจสอบว่าขนาดอยู่ในขอบเขตที่กำหนด
    if(rows > MAX_ROW || cols > MAX_COL) {
        cout << "Matrix size exceeds maximum limit!" << endl;
        return 1;
    }
    
    // สร้างตาราง
    int matrix[MAX_ROW][MAX_COL];
    
    // รับข้อมูลตาราง
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
    
    // แสดงตารางก่อนประมวลผล
    // cout << "Input Matrix:" << endl;
    // printMatrix(matrix, rows, cols);
    
    // // ประมวลผลตาราง
    // processMatrix(matrix, rows, cols);
    
    // // แสดงตารางหลังประมวลผล
    // cout << "\nOutput Matrix:" << endl;
    printMatrix(matrix, rows, cols);
    
    return 0;
}