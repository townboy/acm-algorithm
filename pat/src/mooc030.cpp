#include <stdio.h>

int main() {
	int speed;
	scanf("%d", &speed);
	if(speed > 60)
		printf("Speed: %d - Speeding\n", speed);
	else
		printf("Speed: %d - OK\n", speed);
		
	return 0;
}

