#include <iostream>

using namespace std;

const long long NEGINF = numeric_limits<long long>::min();

int n, m, A[100], B[100];
int cache[101][101];

int getJLIS(int indexA, int indexB)
{
	int& ret = cache[indexA + 1][indexB + 1];

	if (ret != -1) {
		return ret;
	}

	ret = 2;
	long long a = (indexA == -1 ? NEGINF : A[indexA]);
	long long b = (indexB == -1 ? NEGINF : B[indexB]);
	long long  maxElement = max(a, b);

	for (int nextA = indexA + 1; nextA < n; ++nextA) {
		if (maxElement < A[nextA]) {
			ret = max(ret, getJLIS(nextA, indexB) + 1);
		}
	}

	for (int nextB = indexB + 1; nextB < m; ++nextB) {
		if (maxElement < B[nextB]) {
			ret = max(ret, getJLIS(indexA, nextB) + 1);
		}
	}

	return ret;
}


int main(void)
{
	memset(cache, -1, sizeof(cache));

	cin >> n >> m;


	for (int i = 0; i < n; ++i) {
		cin >> A[i];
	}

	for (int i = 0; i < m; ++i) {
		cin >> B[i];
	}

	cout << getJLIS(-1, -1) -2 << endl;


	return 0;
}
