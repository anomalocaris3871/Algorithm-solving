#include <iostream>

using namespace std;


int main(void)
{
	int count = 0;
	int input;
	int num1;
	int num2 = 1;

	cin >> input;

	num1 = input -1;
	while (num1 > 0) {
		num2++;
		num1 = num1 - num2;
		if (num1 % num2 == 0) {
			int i;
			for (i = 1; i < num2; ++i) {
				cout << (num1/ num2) + i << " + ";
			}
			cout << (num1 / num2) + i << " = " << input << endl;
			count++;
		}
	}

	cout << count << endl;

	return 0;
}
