#include <iostream>
using namespace std;

const int MAX = 201;
const long long MOD = 1000000000;

long long dp[MAX][MAX];


int main(void)
{
	int n, k;
	cin >> n >> k;

	dp[0][0] = 1LL;
	for (int i = 1; i <= k; ++i) {
		for (int j = 0; j <= n; ++j) {
			for (int l = 0; l <= j; ++l ) {
				dp[i][j] += dp[i-1][j-l];
				dp[i][j] %= MOD;
			}
		}
	}

	cout << dp[k][n] << endl;



	return 0;
}
