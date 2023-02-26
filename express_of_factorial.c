#include<stdio.h>

int prime_numbers_count[1001] = { 0, };

int main(void)
{
	int n;
	scanf("%d", &n);

	for(int i = 2; i <= n; ++i) {
		int denominator = i;
		int nominator = 2;
		while (denominator != 1) {
			
			if (denominator % nominator == 0) {
				prime_numbers_count[nominator]++;
				denominator /= nominator;
			}
			else {
				nominator++;
			}
		}
	}
	
	printf("%d! = ", n);
	for (int i = 1; i <= n; ++i) {
		if (prime_numbers_count[i] != 0) {
			printf("%d ", prime_numbers_count[i]);
		}
	}

	printf("\n");

	return 0;
}
