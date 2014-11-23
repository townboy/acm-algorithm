#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
	int n, step = 0;
	cin >> n;
	while(1 != n) {
		step ++;
		if(0 == n % 2)
			n /= 2;
		else
			n = (3 * n + 1) / 2;
	}
	cout << step  << endl;
	return 0;
}

