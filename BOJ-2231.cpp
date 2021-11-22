#include <iostream>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	int temp = n;
	int digitNumber = 0;
	while (temp > 0) {
		temp /= 10;
		digitNumber++;
	}

	int startNumber = n - digitNumber * 9;
	;
	int i;
	for (i = startNumber; i <= n; ++i) {
		int sum = i;
		int digit = i;
		while (digit > 0) {
			sum += digit % 10;
			digit /= 10;
		}

		if (n == sum) {
			cout << i;
			break;
		}
	}

	if (i > n) {
		cout << 0 << endl;
	}
	

	return 0;
}
