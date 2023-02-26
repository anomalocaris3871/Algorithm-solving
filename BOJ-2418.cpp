#include <iostream>

using namespace std;

pair<int, int> dir[8] = { {-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,1},{1,-1} };

unsigned long long dp[200][200][100];
char panel[200][200];
int H, W, L;
string word;


void dfs(int r, int c, int depth)
{
	if (depth == L - 1) {
		dp[r][c][depth] = 1;
		return;
	}

	unsigned long long value = 0;

	for (int i = 0; i < 8; i++) {
		int nr = r + dir[i].first;
		int nc = c + dir[i].second;
		if (nr >= 0 && nr < H && nc >= 0 && nc < W) {
			if (panel[nr][nc] == word[depth + 1]) {
				if (dp[nr][nc][depth + 1] == -1) {
					dfs(nr, nc, depth + 1);
				}
				value += dp[nr][nc][depth + 1];
			}
		}
	}

	dp[r][c][depth] = value;
}


int main(void)
{

	cin >> H >> W >> L;

	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			cin >> panel[i][j];
			for (int k = 0; k < 100; ++k) {
				dp[i][j][k] = -1;
			}
		}
	}

	cin >> word;

	unsigned long long ans = 0;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (panel[i][j] == word[0]) {
				dfs(i, j, 0);
				ans += dp[i][j][0];
			}
		}
	}

	cout << ans << endl;

	return 0;
}
