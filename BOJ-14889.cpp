#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int member[20][20];
int n;
int min = INT_MAX;

int makeTeam(int index, vector<int>& first, vector<int>& second) {

	if (first.size() > n / 2) {
		return -1;
	}

	if (second.size() > n / 2) {
		return -1;
	}


	if (index == n) {

		int team1 = 0;
		int team2 = 0;

		for (int i = 0; i < first.size(); ++i) {
			for (int j = 0; j < first.size(); ++j) {
				if (i == j) {
					continue;
				}
				team1 += member[first[i]][first[j]];
				team2 += member[second[i]][second[j]];
			}
		}

		int diff = team1 - team2;
		if (diff < 0) {
			diff = -diff;
		}
		return diff;

	}

	int ans = INT_MAX;
	first.push_back(index);
	int team1 = makeTeam(index + 1, first, second);
	if (team1 != -1 && ans > team1) {
		ans = team1;
	}
	first.pop_back();

	second.push_back(index);
	int team2 = makeTeam(index + 1, first, second);
	if (team2 != -1 && ans > team2) {
		ans = team2;
	}
	second.pop_back();

	return ans;
}

int main(void) {

	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> member[i][j];
		}
	}

	vector<int> team1;
	vector<int> team2;

	cout << makeTeam(0, team1, team2) << endl;



	return 0;
}
