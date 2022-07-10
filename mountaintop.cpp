#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool isPeak(const vector<vector<int>> map, int xLocation, int yLocation) {

	int i;
	for (i = 0; i < 4; ++i) {
		if (map[yLocation][xLocation] <= map[yLocation + dy[i]][xLocation + dx[i]]) {
			break;
		}
	}

	if (i < 4) {
		return false;
	} else{
		return true;
	}

}


int main(void) {

	ifstream fopen;
	fopen.open("in1.txt");


	int n;
	fopen >> n;
	vector<vector<int>> map(n + 2, vector<int>(n + 2, 0));

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			fopen >> map[i][j];
		}
	}

	int count = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (isPeak(map, i, j)) {
				count++;
			}
		}
	}

	cout << count << endl;
	fopen.close();

	return 0;
}
