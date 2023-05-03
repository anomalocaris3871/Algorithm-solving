#include <fstream>
#include <queue>
#include <iostream>

using namespace std;

int days[10001] = { 0, };

int main(void) {

	int n;
	int day;
	int money;
	priority_queue<pair<int, int>> queue;
	fstream fin("in5.txt");

	fin >> n;
	for (int i = 0; i < n; ++i) {
		fin >> money >> day;
		queue.push(make_pair(money, day));
	}

	
	int period = queue.top().first;

	for (int i = 0; i < n; ++i) {
		int income = queue.top().first;
		int expire = queue.top().second;

		for (int i = expire; i >= 1; --i) {
			if (income > days[i]) {
				days[i] = income;
				break;
			}
		}
		queue.pop();
	}

	int sum = 0;
	for (int i = 1; i <= period; ++i) {
		sum += days[i];
	}

	cout << sum << endl;

	return 0;
}
