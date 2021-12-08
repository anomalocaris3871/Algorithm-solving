#include <iostream>

using namespace std;

const int MAX = 10001;

int p[MAX];
int dp[MAX];

int main(void)
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
		dp[i] = 1000 * 10000;
	}

	dp[0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			dp[i] = min(dp[i], dp[i - j] + p[j]);
		} 
	}


	cout << dp[n] << endl;


	return 0;
}
