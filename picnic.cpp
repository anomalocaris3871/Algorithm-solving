#include <iostream>

using namespace std;

int n;
bool areFriends[10][10];

int countPairings(bool taken[10])
{

	int firstFree = -1;
	for (int i = 0; i < n; ++i) {
		if (!taken[i]) {
			firstFree = i;
			break;
		}
	}

	if (firstFree == -1) {
		return 1;
	}

	int ret = 0;

	for (int pairWith = firstFree + 1; pairWith < n; ++pairWith) {
		if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
			taken[firstFree] = taken[pairWith] = true;
			ret += countPairings(taken);
			taken[firstFree] = taken[pairWith] = false;
		}
	}

	return ret;
}

int main(void)
{
	int count;
	cin >> count;
	for (int i = 0; i < count; ++i) {
		int pair;
		cin >> n >> pair;
		bool taken[10]{ false, };
		for (int j = 0; j < pair; ++j) {
			int f1, f2;
			cin >> f1 >> f2;
			areFriends[f1][f2] = areFriends[f2][f1] = true;
		}
		cout << countPairings(taken) << endl;
		
		//clear
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 10;++j) {
				areFriends[i][j] = false;
			}
		}

	}
	return 0;
} 
