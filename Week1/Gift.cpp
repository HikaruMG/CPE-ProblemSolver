#include <iostream>
using namespace std;

int main() {
	int x,n,sum = 0;
	cin >> n;
	for(int j = 0;j<n;j++){
	    cin >> x;
	    if (x > 0){
	        sum += x;
	    }
	}
	cout << sum ;
	return 0;
}