#include <stdio.h>

int main(void)
{
	int n;
	int multiple = 9;
	int result = 0;
	int digit = 1;
	int count_of_digit;

	scanf("%d", &n);

	count_of_digit = multiple;
	result = digit * multiple;
	while (count_of_digit < n) {
		multiple *= 10;
		count_of_digit += multiple;
		
		digit++;
		result += digit * multiple;
	}

	result += (n - count_of_digit) * digit;

	printf("%d\n", result);
	
	return 0;
}
