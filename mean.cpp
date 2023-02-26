#include <iostream>
#include <fstream>

using namespace std;

int map[9][9];
int avg[9];

int main(void) {
	
	ifstream fin;
	fin.open("in5.txt");

	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9;++j) {
			fin >> map[i][j];
			avg[i] += map[i][j];
		}
		avg[i] = round(avg[i] / 9.0);
	}

	

	for (int i = 0; i < 9; ++i) {

		int result = 0;
		int min = INT_MAX;

		for (int j = 0; j < 9; ++j) {
			if (min > abs(avg[i] - map[i][j])) {
				min = abs(avg[i] - map[i][j]);
				result = map[i][j];
			}
			else if (min == abs(avg[i] - map[i][j])) {
				if (result < map[i][j]) {
					result = map[i][j];
				}
			}
		}

		cout << avg[i] << " " << result << endl;
	}

	return 0;
}
