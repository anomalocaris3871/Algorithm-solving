#include <iostream>


using namespace std;

bool nextPermutation(int *series, int size) {
	int i = size - 1;
	while (i > 0 && series[i - 1] >= series[i]) {
		i -= 1;
	}

	if (0 >= i) {
		return false;
	}

	int j = size - 1;
	while (series[i-1] >= series[j]) {
		j -= 1;
	}

	swap(series[i - 1], series[j]);
	j = size - 1;
	while (i < j) {
		swap(series[i], series[j]);
		i += 1;
		j -= 1;
	}

	return true;
}


int main(void) {

	int n;
	cin >> n;
	int series[10000];

	for (int i = 0; i < n; ++i) {
		cin >> series[i];
	}

	if (nextPermutation(series, n)) {
		for (int i = 0; i < n; ++i) {
			cout << series[i] << " ";
		}
	}
	else {
		cout << -1;
	}
	
	cout << endl;

	return 0;
}
