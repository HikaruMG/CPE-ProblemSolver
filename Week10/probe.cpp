#include <cstdio>
#include "probelib.h"
int low = 0;    
int main()
{
  int n = probe_init();
  if (n == 1) { 
    probe_answer(0);
  }
  int high = n-1;
  while (low < high) { 
    int mid = (low +high)/2; 
    if (probe_check(low, mid)) { 
      high = mid;
    } else {
      low = mid+1; 
    }
  }
  probe_answer(high);
  return 0;
}