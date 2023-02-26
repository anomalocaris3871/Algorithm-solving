#include <iostream>

using namespace std;

int sequence[101] = { -1, };
int original[101];

int main(void)
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		int count;
		cin >> count;
		sequence[i] = count;
	}

	for (int i = n; i >= 1; --i) {

		int j;
		for (j = i; j < i + sequence[i]; ++j) {
			original[j] = original[j + 1];
		}

		original[j] = i;
	}

	for (int i = 1; i <= n; ++i) {
		cout << original[i] << " ";
	}
	cout << endl;


	return 0;
}
