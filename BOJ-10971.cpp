#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>

using namespace std;

int city[20][20];

int main(void) {

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> city[i][j];
		}
	}

	vector<int> series(n);
	for (int i = 0; i < n; ++i) {
		series[i] = i;
	}

	int min = INT_MAX;
	do {
		int cost = 0;
		bool canGo = true;
		for (int i = 0; i < n - 1; ++i) {
			if (city[series[i]][series[i+1]] == 0) {
				canGo = false;
				break;
			}
			cost += city[series[i]][series[i+1]];
		}

		if (canGo && city[series[n-1]][series[0]] != 0) {
			cost += city[series[n-1]][series[0]];

			if (min > cost) {
				min = cost;
			}
		}
	} while (next_permutation(series.begin() + 1, series.end()));


	cout << min << endl;


	return 0;
}
