#include<iostream>
#include<queue>

using namespace std;

#define INFESTED 1

int get_count_worm(int** network, int n, bool* is_infested)
{
	int count = 0;
	queue<int> queue;

	for (int i = 0; i < n; ++i) {
		if (network[0][i] == INFESTED) {
			queue.push(i);
			is_infested[i] = true;
		}
	}

	while (!queue.empty()) {
		int computer = queue.front();
		queue.pop();
		

		count++;

		for (int i = 0; i < n; ++i) {
			if (network[computer][i] == INFESTED && is_infested[i] == false) {
				queue.push(i);
				is_infested[i] = true;
			}
		}
	}


	return count;
}

int main(void)
{
	int n;
	cin >> n;

	int** network = new int* [n];
	bool* is_infested = new bool[n];

	
	for (int i = 0; i < n; ++i) {
		is_infested[i] = false;
		network[i] = new int[n];
		for (int j = 0; j < n; ++j) {
			network[i][j] = 0;
		}
	}

	int pair;
	cin >> pair;
	for (int i = 0; i < pair; ++i) {
		int y, x;
		cin >> y >> x;
		network[y - 1][x - 1] = INFESTED;
		network[x - 1][y - 1] = INFESTED;
	}

	is_infested[0] = true;
	cout << get_count_worm(network, n, is_infested) << endl;

	return 0;
}

