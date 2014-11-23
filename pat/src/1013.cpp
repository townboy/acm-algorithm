#include <stdio.h>
#include <iostream>
#include <memory.h>

using namespace std;

bool ret[110000];

void init() {
	memset(ret, true, sizeof(ret));
	ret[2] = true;
	for(int i = 2;i < 110000 ; i++) {
		if(false == ret[i])
			continue;
		for(int f = 2 * i; f < 110000;f += i)
			ret[f] = false;
	}
}

int main() {
	int n ,m;
	init();
	cin >> n >> m;
	int ans = 0;
	for(int i = 2 ;i < 110000;i ++) {
		if(true == ret[i])
			ans ++;
		else 
			continue;
		if(ans >= n) {
			if(0 == ans - n)
				;
			else if(0 == (ans - n) % 10)
				cout << endl;
			else
				cout << " ";
			cout << i ;
		}
		if(ans >= m)
			break;
	}
	cout << endl;
	return 0;
}

