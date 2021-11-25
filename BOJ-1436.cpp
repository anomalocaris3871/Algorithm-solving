#include <iostream>

using namespace std;


int main(void)
{
	int n;
	cin >> n;

	int num = 666;
	int cnt = 0;
	while (true) {
		int temp = num;
		while (temp >= 666) {
			if (temp % 1000 == 666) {
				cnt++;
				break;
			}
			temp /= 10;
		}
		if (cnt == n) {
			cout << num << endl;
			break;
		}
		num++;
	}

	return 0;
}
