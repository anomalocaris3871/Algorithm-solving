#include <iostream>
#include <vector>

using namespace std;

vector<int> h;

long long solve(int left, int right)
{
	if (left == right) {
		return h[left];
	}

	int mid = (left + right) / 2;

	long long ret = max(solve(left, mid), solve(mid + 1, right));

	int lo = mid;
	int hi = mid + 1;
	int height = min(h[lo], h[hi]);

	ret = max(ret, (long long)height * 2);

	while (left < lo || hi < right) {
		if (hi < right && (lo == left || h[lo - 1] < h[hi + 1])) {
			++hi;
			height = min(height, h[hi]);
		}
		else {
			--lo;
			height = min(height, h[lo]);
		}
		ret = max(ret, (long long)height *((long long)hi - lo + 1));
	}
	return ret;
}

int main(void)
{

	while (true) {
		int cnt;
		cin >> cnt;
		
		if (cnt == 0) {
			break;
		}

		for (int j = 0; j < cnt;++j) {
			int height;
			cin >> height;
			h.push_back(height);
		}
		cout << solve(0, cnt-1) << endl;
		h.clear();

	}

	return 0;
};
