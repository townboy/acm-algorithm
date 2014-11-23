#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <math.h>

using namespace std;

bool ret[110000];

void init() {
	memset(ret, true, sizeof(ret));
	for(int i = 2; i < 100000; i++) {
		for(int f = 2; f <= sqrt(i) + 0.1; f++) {
			if(0 == i % f) {
				ret[i] = false;
				break;
			}
		}
	}
}

int main() {
	init();
	int tem, ans = 0;
	cin >> tem;
	for(int i = 5; i <= tem; i++) {
		if(ret[i] && ret[i - 2])
			ans ++;
	}
	cout << ans << endl;
	return 0;
}
