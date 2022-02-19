#include<stdio.h>
int nums[50001];

int main(void)
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; j = j + i) {
			nums[j]++;
		}
	}

	for (int i = 1; i <= n; ++i) {
		printf("%d ", nums[i]);
	}


	return 0;
}
