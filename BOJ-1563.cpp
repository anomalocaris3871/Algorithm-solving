#include <iostream>

using namespace std;

const int MOD = 1000000;

int dp[1001][2][3];

int main(void)
{
	int n;
	cin >> n;

	dp[1][0][0] = dp[1][1][0] = dp[1][0][1] = 1;

	for (int i = 2; i <= n; ++i) {
		dp[i][0][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2]) % MOD;
		dp[i][0][1] = dp[i - 1][0][0] % MOD;
		dp[i][0][2] = dp[i - 1][0][1] % MOD;

		dp[i][1][0] = (dp[i-1][0][0] + dp[i-1][0][1] + dp[i-1][0][2] + dp[i - 1][1][0] + dp[i - 1][1][1] + dp[i - 1][1][2]) % MOD;
		dp[i][1][1] = dp[i - 1][1][0] % MOD;
		dp[i][1][2] = dp[i - 1][1][1] % MOD;

	}

	int ans = 0;
	for (int i = 0; i < 2; ++i) {
		for(int j = 0 ; j <3; ++j) {
			ans += dp[n][i][j];
			ans %= MOD;
		}
	}

	cout << ans << endl;

	return 0;
}
