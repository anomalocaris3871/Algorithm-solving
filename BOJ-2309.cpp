#include <iostream>
#include <algorithm>

using namespace std;


int dwarfs[9];
int total = 9;

int main(void) {

	int dwarf;
	int sum = 0;

	for (int i = 0; i < total; ++i) {
		cin >> dwarfs[i];
		sum += dwarfs[i];
	}

	sort(dwarfs, dwarfs + total);

	
	for (int i = 0;i < total; ++i) {
		for (int j = i + 1; j < total; ++j) {
			if (sum - dwarfs[i] - dwarfs[j] == 100) {
				for (int k = 0; k < total; ++k) {
					if (k == i || k == j) {
						continue;
					}
					cout << dwarfs[k] << endl;
				}
				return 0;
			}

		}
	}
	


	return 0;
}
