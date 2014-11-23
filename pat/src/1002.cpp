#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

char ch[110];
string dig[10];

void init() {
	dig[0] = "ling";
	dig[1] = "yi";
	dig[2] = "er";
	dig[3] = "san";
	dig[4] = "si";
	dig[5] = "wu";
	dig[6] = "liu";
	dig[7] = "qi";
	dig[8] = "ba";
	dig[9] = "jiu";
}

int main() {
	init();
	gets(ch);
	int sum = 0, len = strlen(ch);
	for(int i = 0;i < len; i++)
		sum += ch[i] - '0';
	
	vector<int> ans;
	while(0 != sum) {
		ans.push_back(sum % 10);
		sum /= 10;
	}
	
	for(int i = ans.size() - 1; i >= 0; i --) {
		cout << dig[ans[i]];
		if(0 != i)
			printf(" ");
	}
	return 0;
}
