#include<stdio.h>
#include<math.h>

int nums[101];
int diffs[101] = { 0, };

int main(void)
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i) {
		scanf("%d", &nums[i]);
	}

	bool flag = true;
	for (int i = 1; i <= n - 1; ++i) {
		int diff = abs(nums[i + 1] - nums[i]);

		if (diff > n - 1) {
			flag = false;
			break;
		}

		if (diffs[diff] == 0) {
			diffs[abs(nums[i + 1] - nums[i])] = 1;
		}
		else {
			flag = false;
			break;
		}
	}

	if (flag == true) {
		printf("%s\n", "YES");
	}
	else {
		printf("%s\n", "NO");
	}



	return 0;
}
