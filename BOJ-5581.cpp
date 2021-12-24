#include <iostream>

using namespace std;

//[i][0]:黒か白か, [i][1]:連続で並んでる個数
int table[100001][2];

int main(void) {
	int n;
	cin >> n;

	int stone;
	cin >> stone;

	table[0][0] = stone;
	table[0][1] = 1;
	int size = 1;

	for (int i = 0;i < n - 1;i++) {
		cin >> stone;
		if (i % 2 == 0) { //偶数
			if (table[size - 1][0] == stone) {
				table[size - 1][1]++;
			}
			else {
				if (size >= 2) {
					table[size - 2][1] += table[size - 1][1] + 1;
					size--;
				}
				else {
					table[size - 1][0] = stone;
					table[size - 1][1]++;
				}
			}
		}
		else { //奇数
			if (table[size - 1][0] == stone) {
				table[size - 1][1]++;
			}
			else {
				table[size][0] = stone;
				table[size++][1] = 1;
			}
		}
	}

	int ans = 0;
	for (int i = 0;i < size;i++) {
		ans += table[i][0] == 0 ? table[i][1] : 0;
	}

	cout << ans << endl;

	return 0;
}
