#include <iostream>
#include <vector>

using namespace std;

int search_binary(vector<int> input, int dvd_count, int ans, int left, int right)
{
	if (left > right) {
		return ans;
	}

	int mid = (left + right) / 2;
	int sum = 0;
	int count = 0;

	for (int i = 0; i < input.size(); ++i) {
		sum += input[i];
		
		if (sum > mid) {
			sum = 0;
			count++;
			i = i - 1;
		}
		else if (i == input.size() - 1) {
			count++;
		}
	}

	if (dvd_count >= count) {
		ans = mid;
	}

	if (dvd_count < count) {
		return search_binary(input, dvd_count, ans, mid + 1, right);
	}
	else {
		return search_binary(input, dvd_count, ans, left, mid - 1);
	}
}

int main(void)
{
	int n;
	int dvd_count;
	cin >> n >> dvd_count;

	vector<int> input(n);
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> input[i];
		sum += input[i];
	}

	cout << search_binary(input, dvd_count, 0, 1, sum) << endl;

	return 0;
}
