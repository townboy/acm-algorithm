#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
	int tem[110];
	int n ,m;
	cin >> n >> m;
	for(int i = 0 ;i < n; i++) 
		cin >> tem[i];
	m %= n;
	int aim = n - m;
	for(int i = aim ;i < n;i++)
		cout << tem[i] << " ";
	for(int i = 0 ;i < aim ;i++) {
		cout << tem[i];
		if(i != aim - 1)
			cout << " ";
	}
	cout << endl;
	return 0;
}

