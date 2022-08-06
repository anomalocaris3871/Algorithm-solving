#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

int main(void) {

	fstream ifs("in1.txt");
	int n;
	ifs >> n;
	stack<int> transaction;
	string result = "";

	bool isFirst = true;
	bool isPossible = true;
	int train;
	
	for (int i = 0;i < n; ++i) {
		ifs >> train;

		if (transaction.empty()) {
			transaction.push(train);
			result.append("P");
		} else if (train < transaction.top()) {
			result.append("P");
			transaction.push(train);
		} else {
			while (!transaction.empty()) {
				if (train > transaction.top()) {
					result.append("O");
					if (transaction.top() == 1 && isFirst == true) {
						isFirst = false;
					}
					else if (isFirst == true) {
						isPossible = false;
						break;
					}
					transaction.pop();
				}
				else {
					break;
				}
			}
			if (isPossible == false) {
				break;
			}
			transaction.push(train);
			result.append("P");
		}
	}

	while (!transaction.empty()) {
		result.append("O");
		transaction.pop();
	}

	if (isPossible == false) {
		cout << "impposible" << endl;
	}
	else {
		cout << result << endl;
	}

	return 0;
}
