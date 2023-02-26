#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get_maximun_distance(vector<int> stable, int number_of_horse, int left, int right, int ans)
{
	if (left > right) {
		return ans;
	}

	int mid = (left + right) / 2;
	int pos = stable[1];
	int count = 1;

	for (int i = 2; i <= stable.size() - 1; ++i) {
		int length = stable[i] - pos;
		if (length >= mid) {
			pos = stable[i];
			count++;
		}
	}

	if (count >= number_of_horse) {
		ans = mid;
		return get_maximun_distance(stable, number_of_horse, mid + 1, right, ans);
	}
	else {
		return get_maximun_distance(stable, number_of_horse, left, mid - 1, ans);
	}
}

int main(void)
{
	int n;
	int number_of_horse;

	cin >> n >> number_of_horse;

	vector<int> stable(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> stable[i];
	}

	sort(stable.begin(), stable.end());

	cout << get_maximun_distance(stable, number_of_horse, stable[1], stable[stable.size() - 1], 0);

	return 0;
}
