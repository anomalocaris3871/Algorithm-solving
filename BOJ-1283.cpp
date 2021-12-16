#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<char> shortcutWithUpperCase;

bool hasElement(char element)
{
	for (int i = 0;i < shortcutWithUpperCase.size(); ++i) {
		if (toupper(element) == shortcutWithUpperCase[i]) {
			return true;
		}
	}

	return false;
}

int main(void)
{
	int n;
	cin >> n;
	cin.ignore();

	for (int i = 0;i < n; ++i) {
		string word;
		getline(cin, word);

		string ans = "";
		if (!hasElement(word[0])) {
			shortcutWithUpperCase.push_back(toupper(word[0]));

			ans.append("[").
				append(string(1, word[0])).
				append("]").
				append(word.substr(1, word.size()));

			cout << ans << endl;
			continue;
		}

		int j;
		for (j = 1; j < word.size(); ++j) {
			if (word[j] == ' ' && !hasElement(word[j + 1])) {
				shortcutWithUpperCase.push_back(toupper(word[j + 1]));

				ans.append(word.substr(0, j + 1)).
					append("[").
					append(string(1, word[j + 1])).
					append("]").
					append(word.substr(j + 2, word.size()));

				cout << ans << endl;
				break;
			}
		}

		if (j < word.size()) {
			continue;
		}


		int k;
		for (k = 1; k < word.size(); ++k) {
			if (!hasElement(word[k]) && word[k] != ' ') {
				shortcutWithUpperCase.push_back(toupper(word[k]));

				ans.append(word.substr(0, k)).
					append("[").
					append(string(1, word[k])).
					append("]").
					append(word.substr(k + 1, word.size()));

				cout << ans << endl;
				break;
			}
		}

		if (k < word.size()) {
			continue;
		}

		cout << word << endl;

	}

	return 0;
}
