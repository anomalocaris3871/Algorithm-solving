#include<iostream>
#include<algorithm>

using namespace std;

int arr[100001];

void binary_search(int find_num, int* arr, int length)
{
	int start_index = 0;
	int end_index = length - 1;

	while (end_index >= start_index) {
		int mid_index = (start_index + end_index) / 2;

		if (arr[mid_index] > find_num) {
			end_index = mid_index - 1;
		}
		else if (arr[mid_index] < find_num) {
			start_index = mid_index + 1;
		}
		else {
			printf("%d\n", 1);
			return;
		}

	}

	printf("%d\n", 0);
}

int main(void)
{
	cin.tie(NULL);

	int n, m;

	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}

	sort(arr, arr + n);

	scanf("%d", &m);

	for (int i = 0; i < m; ++i) {
		int find_number;
		scanf("%d", &find_number);
		binary_search(find_number, arr, n);
	}

	return 0;
}
