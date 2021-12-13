#include <iostream>
#include <climits>

using namespace std;

const int MAX = 100001;

int dp[MAX];
int seq[MAX];

int main(void)
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> seq[i];
	}


	dp[1] = seq[1];
	for (int i = 2; i <= n; ++i) {
		dp[i] = seq[i];
		if (dp[i] < dp[i - 1] + seq[i]) {
			dp[i] = dp[i - 1] + seq[i];
		}
	}

	int ans = INT_MIN;
	for (int i = 1; i <= n; ++i) {
		ans = max(ans, dp[i]);
	}

	cout << ans << endl;

	return 0;
}
