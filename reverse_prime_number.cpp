#include <stdio.h>

int reverse(int num)
{
	int result = 0;
	int tmp = 0;
	while (num != 0) {
		tmp = num % 10;
		result = result * 10 + tmp;
		num /= 10;
	}

	return result;
}

bool isPrime(int num) 
{
	int i;

	if (num <= 1) {
		return false;
	}

	for (i = 2; i < num; ++i) {
		if (num % i == 0) {
			break;
		}
	}

	if (i < num) {
		return false;
	}
	else {
		return true;
	}
}

int main(void)
{
	freopen("in5.txt", "rt", stdin);
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		int num;
		scanf("%d", &num);

		int reverse_num;
		reverse_num = reverse(num);
		if (isPrime(reverse_num)) {
			printf("%d ", reverse_num);
		}
	}

	printf("\n");

	return 0;
}
