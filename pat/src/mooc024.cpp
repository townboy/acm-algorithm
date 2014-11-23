#include <stdio.h>

int main() {
	int ans;
	scanf("%d", &ans);
	int di = ans % 16;
	ans /= 16;
	printf("%d\n", ans * 10 + di);
	return 0;
}

