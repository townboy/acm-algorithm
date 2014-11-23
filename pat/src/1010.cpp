#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
	int a, b;
	bool tt = false;
	while(cin >> a >> b) {
		if(0 == a || 0 == b)
			continue;
		if(true == tt)
			cout << " ";
		tt = true;
		cout << a * b << " " << b - 1 ;
	}
	if(false == tt)
		cout << "0 0" ;
	cout << endl;
	return 0;
}



