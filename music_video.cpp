#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int search_binary(vector<int> input, int dvd_count, int ans, int max, int left, int right)
{
	if (left > right) {
		return ans;
	}

	int mid = (left + right) / 2;
	int sum = 0;
	int count = 1;

	for (int i = 0; i < input.size(); ++i) {
		if (sum + input[i] > mid) {
			count++;
			sum = input[i];
		}
		else {
			sum += input[i];
		}
	}


	if (dvd_count >= count && mid >= max) {
		ans = mid;
		return search_binary(input, dvd_count, ans, max, left, mid - 1);
	}
	else  {
		return search_binary(input, dvd_count, ans, max, mid + 1, right);
	}
}

int main(void)
{
	int n;
	int dvd_count;
	cin >> n >> dvd_count;

	vector<int> input(n);
	int sum = 0;
	int max = INT_MIN;
	for (int i = 0; i < n; ++i) {
		cin >> input[i];
		sum += input[i];
		if (max < input[i]) {
			max = input[i];
		}
	}

	cout << search_binary(input, dvd_count, 0, max, 1, sum) << endl;

	return 0;
}
