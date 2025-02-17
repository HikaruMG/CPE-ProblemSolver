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

int find_max(vector<int>& x, int n)
{
  int Max;
  if (n == 1)
    return x[0];
  else
  {
    Max = find_max(x,n-1);
    if (x[n-1] > Max)
      return x[n-1];
    else
	  return Max;
  } 
}
int main()
{
  read_input();
  cout << find_max(x,n) << endl;
}