#include <iostream>
#include <vector>

using namespace std;

void pick(int n, vector<int> cards, int m, int* max)
{
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			for (int k = j + 1; k < n; ++k) {
				int sum = cards[i] + cards[j] + cards[k];
				if (sum > *max && sum <= m) {
					*max = sum;
				}
			}
		}
	}

}

int main(void)
{
	int n, m;
	cin >> n >> m;
	vector<int> cards(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &cards[i]);
	}

	int max = 0;
	pick(n, cards, m, &max);
	cout << max << endl;

	return 0;
}
