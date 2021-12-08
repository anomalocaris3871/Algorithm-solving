#include <iostream>

using namespace std;

const long long MOD = 1000000009;
const int limit = 100000;

int dp[100001][4];

int main(void)
{
	for (int i = 1; i <= limit; ++i) {
		if (i - 1 >= 0) {
			dp[i][1] = dp[i - 1][2] + dp[i - 1][3];
			if (i == 1) {
				dp[i][1] = 1;
			}
		}

		if (i - 2 >= 0) {
			dp[i][2] = dp[i - 2][1] + dp[i - 2][3];
			if (i == 2) {
				dp[i][2] = 1;
			}
		}

		if (i - 3 >= 0) {
			dp[i][3] = dp[i - 3][1] + dp[i - 3][2];
			if (i == 3) {
				dp[i][3] = 1;
			}
		}

		dp[i][1] %= MOD;
		dp[i][2] %= MOD;
		dp[i][3] %= MOD;
	}

	int n;
	cin >> n;
	while (n--) {
		int k;
		cin >> k;
		cout << (dp[k][1] + dp[k][2] + dp[k][3]) % MOD << endl;
	}



	return 0;
}
