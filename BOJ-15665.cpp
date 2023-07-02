#include <iostream>
#include <algorithm>

using namespace std;

int numbers[10];
int series[10];

void go(int index, int selected, int n, int m) {

	if (selected == m) {
		for (int i = 0; i < m; ++i) {
			cout << series[i] << " ";
		}
		cout << endl;
		return;
	}

	if (index >= n) {
		return;
	}

	series[selected] = numbers[index];
	go(index + 1, selected + 1, n, m);
	//series[selected] = 0;
	go(index + 1, selected, n, m);

}


int main(void) {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		cin >> numbers[i];
	}

	sort(numbers, numbers + n);

	go(0, 0, n, m);


	return 0;
}
