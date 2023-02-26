#include<stdio.h>


int main(void)
{
	int n;
	scanf("%d", &n);

	int left = 1;
	int right;
	int current;
	int pow = 1;
	int result = 0;

	while (left != 0) {
		left = n / (pow * 10);
		current = (n / pow) % 10;
		right = n % pow;
		if (current > 3) {
			result += (left + 1) * pow;
		}
		else if (current < 3) {
			result += left * pow;
		}
		else {
			result += left * pow + right + 1;
		}

		pow *= 10;
	}

	printf("%d\n", result);
	
	return 0;
}
