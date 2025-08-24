#include <iostream>
using namespace std;

// ฟังก์ชันสำหรับการรวม (Merge)
void merge(int arr[], int left, int mid, int right) {
    // ขนาดของสองส่วน
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // สร้างอาร์เรย์ชั่วคราวเพื่อเก็บสองส่วนย่อย
    int leftArr[n1], rightArr[n2];

    // คัดลอกข้อมูลจาก arr[] ไปยัง leftArr[] และ rightArr[]
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        rightArr[i] = arr[mid + 1 + i];

    // รวมสองส่วนย่อยกลับเข้าไปใน arr[]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // คัดลอกข้อมูลที่เหลือจาก leftArr[]
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // คัดลอกข้อมูลที่เหลือจาก rightArr[]
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// ฟังก์ชัน Merge Sort (Recursive)
void mergeSort(int arr[], int left, int right) {
    if (left >= right)
        return;
    cout << "First: "<< right << endl;
    // คำนวณจุดกึ่งกลาง
    int mid = left + (right - left) / 2;
    cout << left << " + (" << right << "-" << left <<")/2"<<"=" << mid << endl;
    cout << "Mid: "<< mid << endl;
    // เรียก mergeSort แบบ Recursive เพื่อแบ่งอาร์เรย์ออกเป็นสองส่วน
    mergeSort(arr, left, mid);
    cout << "next" << endl;
    mergeSort(arr, mid + 1, right);

    // รวมสองส่วนย่อยเข้าด้วยกัน
    merge(arr, left, mid, right);
}

// ฟังก์ชันสำหรับพิมพ์อาร์เรย์
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Sorting: ";
    printArray(arr, n);

    // เรียกใช้ Merge Sort
    mergeSort(arr, 0, n - 1);

    cout << "After Sorting: ";
    printArray(arr, n);

    return 0;
}

//Testcpp dsadsad sadsasadsad