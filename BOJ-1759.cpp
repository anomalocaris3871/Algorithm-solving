#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(string password) {
	int consonant = 0;
	int vowel = 0;
	for (int i = 0; i < password.size(); ++i) {
		if (password[i] == 'a' || password[i] == 'e' || password[i] == 'i' || password[i] == 'u' || password[i] == 'o') {
			vowel += 1;
		}
		else {
			consonant += 1;
		}
	}

	if (2 > consonant || 1 > vowel) {
		return false;
	}
	
	return true;
}

void generatePassword(int len, vector<char> alpha, string password, int i) {
	
	if (password.size() == len && check(password)) {
		cout << password << endl;
		return;
	}

	if (i >= alpha.size()) {
		return;
	}

	generatePassword(len, alpha, password + alpha[i], i + 1);
	generatePassword(len, alpha, password, i + 1);

}

int main(void) {

	int len;
	int n;
	cin >> len >> n;

	vector<char> alpha(n);
	for (int i = 0; i < n; ++i) {
		cin >> alpha[i];
	}

	sort(alpha.begin(), alpha.end());

	string password;
	generatePassword(len, alpha, password, 0);


	return 0;
}
