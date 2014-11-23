#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

char ch[100];

int find(int x) {
	int ans = -1;
	for(int i = 0;ch[i]; i++)
		if(x == ch[i]) {
			if(-1 == ans)
				ans = i;
			else return -1;
		}
	return ans;
}

bool isOK() {
	for(int i = 0 ; ch[i]; i++)
		if(ch[i] != 'P' && ch[i] != 'A' && ch[i] != 'T')
			return false;
	return true;
}

int main() {
	int _;
	cin >> _;
	for(int i = 0;i < _ ;i++) {
		scanf("%s", ch);

		if(false == isOK()) {
			puts("NO");
			continue;
		}
		
		int p = find('P'), t = find('T');
		if(-1 == p || -1 == t) {
			puts("NO");
			continue;
		}
		int q = p,z = t - p - 1, h = strlen(ch) - t - 1;
		if(z * q == h && z != 0)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}

