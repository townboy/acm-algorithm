#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

char ch[3];

int main() {
	cin >> ch;
	int len = strlen(ch);
	for(int i = 0; ch[i]; i++) {
		if(3 == len - i)
			for(int f = 0;f < ch[i] - '0'; f++)
				cout << "B" ;
		else if(2 == len - i)
			for(int f = 0;f < ch[i]- '0'; f++)
				cout << "S" ;
		else 
			for(int f = 1;f <= ch[i] - '0'; f++)
				cout << f ;
	}
	cout << endl;
	return 0;
}
