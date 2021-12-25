#include <iostream>

using namespace std;

int n, triangle[100][100];
int cache[100][100];

int getPath(int y, int x)
{
	if (y == n - 1) {
		return triangle[y][x];
	}

	int& ret = cache[y][x];
	if (ret != -1) {
		return ret;
	}

	return ret = max(getPath(y + 1, x), getPath(y + 1, x + 1)) + triangle[y][x];
}

int main(void)
{
	memset(cache, -1, sizeof(cache));
	
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			cin >> triangle[i][j];
		}
	}

	cout << getPath(0, 0) << endl;

	return 0;
}
