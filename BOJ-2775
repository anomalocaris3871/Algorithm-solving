#include<fstream>
#include<iostream>

using namespace std;

int main(void)
{
	int k;
	cin >> k;

	while (k > 0) {
		int a, b;
		cin >> a >> b;

		int** apartment = new int* [a + 1];
		for (int i = 0; i < a + 1; ++i) {
			apartment[i] = new int[b + 1];
			for (int j = 0; j < b + 1; ++j) {
				apartment[i][j] = 0;
			}
		}

		for (int i = 1; i < b + 1; ++i) {
			apartment[0][i] = i;
		}

		for (int i = 1; i < a + 1; ++i) {
			for (int j = 1; j < b + 1; ++j) {
				for (int k = 1; k <= j; ++k) {
					apartment[i][j] += apartment[i - 1][k];
				}
			}
		}

		cout << apartment[a][b] << endl;

		delete[] apartment;
		k--;
	}




	return 0;
}
