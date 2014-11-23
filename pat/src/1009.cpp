#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

vector<string> ans;

int main() {
	char ch[100];
	while(scanf("%s", ch) != EOF)
		ans.push_back((string)ch);
	for(int i = ans.size() - 1; i >= 0 ; i--) {
		cout << ans[i] ;
		if(i != 0)
			cout << " ";
	}
	return 0;
}
