#include <stdio.h>

int main() {
	int a, b, c;
	scanf("%d%d%d", &a, &b ,&c);
	int diff = a ^ b ^ c;
	if(a == diff)
		puts("A");
	if(b == diff)
		puts("B");
	if(c == diff)
		puts("C");
	return 0;
}

