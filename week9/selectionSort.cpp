#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> x;

void read_input()
{
  cin >> n;
  for(int i = 0; i < n; i++) {
    int xx;
    cin >> xx;
    x.push_back(xx);
  }
}

int find_max_index(vector<int>& x, int n)
{
  if (n==1){
        return 0;
    }
    int max = find_max_index(x,n-1);
    if (x[n-1] > x[max]){
        return n-1;
    }
    else{
        return max;
    }
}

void swap(int& x, int& y)
{
  int t = x;
  x = y;
  y = t;
}

void selection_sort(vector<int>& x, int n)
{
  if (n == 1)
    return;
  int max = find_max_index(x,n);
  swap(x[max],x[n-1]);
  selection_sort(x,n-1);
  
}

int main()
{
  read_input();
  selection_sort(x, n);
  for(int i=0; i<n; i++) {
    cout << x[i] << endl;
  }
}