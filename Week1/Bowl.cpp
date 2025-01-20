#include <iostream>
using namespace std;

int Size(int arr[], int n)
{
    int max = 0;
    for (int i = 0; i < 300; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
int main()
{
    int n, r;
    int dish[301] = {0};
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> r;
        dish[r] += 1;
    }
    cout << Size(dish, n);
    return 0;
}