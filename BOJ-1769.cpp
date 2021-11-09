#include<fstream>
#include<iostream>
#include<string>

using namespace std;

void is_multiple_of_three_recursive(string n, int* count)
{
	if (n.length() == 1) {
		int result = n[0] - '0';

		cout << *count << endl;
		if (result % 3 == 0) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}

		return;
	}

	int sum = 0;
	for (int i = 0;i < n.length();++i) {
		sum += (n[i] - '0');
	}


	(*count)++;
	is_multiple_of_three_recursive(to_string(sum), count);

}

int main(void)
{
	string n;
	int count = 0;
	cin >> n;

	is_multiple_of_three_recursive(n, &count);

	return 0;
}
