#include <iostream>
#include <cstring>

using namespace std;

int n;
int cache[1000];
int seq[1000];

int getLIS(int start)
{
	int& ret = cache[start];
	if (ret != -1) {
		return ret;
	}

	ret = seq[start];
	for (int next = start + 1; next < n; ++next) {
		if (seq[start] < seq[next]) {
			ret = max(ret, getLIS(next) + seq[start]);
		}
	}

	return ret;
}


int main(void)
{
	memset(cache, -1, sizeof(cache));

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> seq[i];
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans = max(ans, getLIS(i));
	}

	cout << ans << endl;

	return 0;
}
