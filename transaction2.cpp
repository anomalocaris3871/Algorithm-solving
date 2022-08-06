#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
using namespace std;

int main(void) {

	fstream ifs("in5.txt");

	int n;
	int index = 1;
	stack<int> transaction;
	vector<char> result;
	ifs >> n;

	int train;
	for (int i = 0; i < n; ++i) {
		ifs >> train;
		transaction.push(train);
		result.push_back('P');
		while (!transaction.empty()) {
			if (index == transaction.top()) {
				transaction.pop();
				result.push_back('O');
				index++;
			}
			else {
				break;
			}

		}
	}

	if (transaction.empty()) {
		for (vector<char>::iterator iter = result.begin(); iter != result.end(); ++iter) {
			cout << *iter;
		}
	}
	else {
		cout << "impossible" << endl;
	} 

	return 0;
}
