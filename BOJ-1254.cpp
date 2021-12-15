#include <iostream>
using namespace std;

bool isPalindrom(string str)
{
	for (int i = 0; i < str.size() / 2; ++i) {
		if (str[i] != str[str.size() - i - 1]) {
			return false;
		}
	}
	return true;
}

int main(void)
{
	string str;
	cin >> str;

	int ans = str.size() * 2 - 1;

	for (int i = 0;i < str.size(); ++i) {
		string temp = str.substr(i, str.size());

		if (isPalindrom(temp)) {
			ans = str.size() + i ;
			break;
		}
	}

	cout << ans << endl;

	return 0;
}
