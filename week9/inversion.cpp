#include <iostream>
#include <vector>

using namespace std;

long long merge(vector<int>& arr, int L, int mid, int R) {
    vector<int> Larr(arr.begin()+L, arr.begin()+mid+1);
    vector<int> Rarr(arr.begin()+mid+1, arr.begin()+R+1);

    int i = 0, j = 0, k = L;
    long long Count = 0;
    while (i<Larr.size() && j<Rarr.size()) {
        if (Larr[i] <= Rarr[j]) {
            arr[k++] = Larr[i++];
        } else {
            arr[k++] = Rarr[j++];
            Count += (Larr.size()-i);
        }
    }
    while (i < Larr.size()) {
        arr[k++] = Larr[i++];
    }
    while (j < Rarr.size()) {
        arr[k++] = Rarr[j++];
    }
    return Count;
}

long long FindInverse(vector<int>& arr, int L, int R) {
    long long Count = 0;
    if (L < R) {
        int mid = L+(R - L)/2;
        Count += FindInverse(arr, L, mid);
        Count += FindInverse(arr, mid + 1, R);
        Count += merge(arr, L, mid, R);
    }
    return Count;
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    cout << FindInverse(arr, 0, N - 1) << endl;
    return 0;
}
