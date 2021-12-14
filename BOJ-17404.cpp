#include <iostream>

using namespace std;

int dp[1001][3];
int house[1001][3];
const int MAX = 1000 * 1000 + 1;

int main(void)
{
	int n;
	cin >> n;


	for (int i = 1; i <= n;++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> house[i][j];
		}
	}

	int ans = MAX;
	for (int k = 0; k < 3; ++k) {
		for (int j = 0; j < 3; ++j) {
			if (j == k) {
				dp[1][j] = house[1][j];
			}
			else {
				dp[1][j] = MAX;
			}
		}

		for (int i = 2; i <= n; ++i) {
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + house[i][0];
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + house[i][1];
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + house[i][2];
		}

		for (int j = 0;j < 3; ++j) {
			if (j == k) {
				continue;
			}
			ans = min(ans, dp[n][j]);
		}

	}

	cout << ans << endl;

	return 0;
}
