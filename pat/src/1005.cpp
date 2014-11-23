#include <stdio.h>
#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

int ans[11000];

int main() {
	int _;
	cin >> _;
	memset(ans, 0, sizeof(ans));
	for(int i = 0 ;i < _;i ++) {
		int t;
		cin >> t;
		ans[t] = -1;
	}
	for(int i = 1 ;i <= 100;i ++) 
		if(-1 == ans[i]) {
			int x = i;
			while(1 != x) {
				if(0 == x % 2)
					x /= 2;
				else
					x = (x * 3 + 1)/ 2;
				ans[x] = 1;
			}
		}
	vector<int> ret;
	for(int i = 100; i > 0; i--)
		if(-1 == ans[i])
			ret.push_back(i);

	for(int i = 0 ;i < ret.size(); i++) {
		if(0 != i)
			cout << " ";
		cout << ret[i];
	}
	cout << endl;
	return 0;
}

