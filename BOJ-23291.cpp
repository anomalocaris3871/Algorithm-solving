#include<iostream>
#include<fstream>

using namespace std;

int main(void) {
	int n, k;

	ifstream fin("test.txt");

	if (fin.fail()) {
		cerr << "error" << endl;
	}

	fin >> n >> k;
	int** fishing_pot = new int* [n];

	for (int i = 0; i < n;++i) {
		fishing_pot[i] = new int[n];
		for (int j = 0;j < n; ++j) {
			fishing_pot[i][j] = 0;
		}
	}

	for (int i = 0; i < n; ++i) {
		fin >> fishing_pot[n - 1][i];
	}

	int min = fishing_pot[n - 1][0];
	for (int i = 1; i < n; ++i) {
		if (min > fishing_pot[n - 1][i]) {
			min = fishing_pot[n - 1][i];
		}
	}

	for (int i = 0; i < n; ++i) {
		if (fishing_pot[n - 1][i] == min) {
			fishing_pot[n - 1][i]++;
		}
	}


	int cnt = 1;
	int new_row = 0;
	int new_col = 0;

	int old_row = 1;
	int old_col = 0;

	while (true) {

		new_row = cnt + 1;
		new_col += cnt;

		old_row = 1;
		for (int i = 0; i < cnt * cnt; ++i) {

			fishing_pot[n - new_row][new_col] = fishing_pot[n - old_row][old_col];
			fishing_pot[n - old_row][old_col] = 0;

			if ((i + 1) % cnt == 0) {
				new_row--;
				new_col = cnt * cnt;

				old_row = 1;
				old_col++;
			}
			else {
				new_col++;

				old_row++;
			}
		}

		new_row = cnt + 1;
		new_col += cnt;

		if (new_col + cnt >= n) {
			break;
		}

		old_row = 1;
		for (int i = 0; i < cnt * cnt + cnt; ++i) {

			fishing_pot[n - new_row][new_col] = fishing_pot[n - old_row][old_col];
			fishing_pot[n - old_row][old_col] = 0;

			if ((i + 1) % (cnt + 1) == 0) {
				new_row--;
				new_col = cnt * cnt + cnt;

				old_row = 1;
				old_col++;

			}
			else {
				new_col++;

				old_row++;
			}
		}

		cnt++;
	}


	int** diff_fish_num = new int* [new_row];
	bool** diff_fish_check_north_south = new bool* [new_row];
	bool** diff_fish_check_east_west = new bool* [new_row];

	for (int i = 0; i < new_row; ++i) {
		diff_fish_num[i] = new int[n - old_col];
		diff_fish_check_north_south[i] = new bool[n - old_col];
		diff_fish_check_east_west[i] = new bool[n - old_col];
		for (int j = 0; j < n - old_col;++j) {
			diff_fish_num[i][j] = 0;
			diff_fish_check_north_south[i][j] = false;
			diff_fish_check_east_west[i][j] = false;
		}
	}

	for (int i = n - new_row; i < n; ++i) {
		for (int j = old_col; j < n; ++j) {

			int north = 0;
			if (i - 1 > n - new_row) {
				north = fishing_pot[i - 1][j];
			}

			int south = 0;
			if (i + 1 < n) {
				south = fishing_pot[i + 1][j];
			}

			int east = 0;
			if (j + 1 < n) {
				east = fishing_pot[i][j + 1];
			}

			int west = 0;
			if (j - 1 > old_col) {
				west = fishing_pot[i][j - 1];
			}

			int north_diff = abs(fishing_pot[i][j] - north);
			if (north != 0 && fishing_pot[i][j] != 0 &&
				(diff_fish_check_north_south[i - (n - new_row)][j - old_col] == false || diff_fish_check_north_south[i - (n - new_row) - 1][j - old_col] == false)) {

				if (fishing_pot[i][j] > north) {
					diff_fish_num[i - (n - new_row)][j - old_col] += -north_diff / 5;
					diff_fish_num[i - (n - new_row) - 1][j - old_col] += north_diff / 5;
				}
				else {
					diff_fish_num[i - (n - new_row)][j - old_col] += north_diff / 5;
					diff_fish_num[i - (n - new_row) - 1][j - old_col] += -north_diff / 5;
				}

				diff_fish_check_north_south[i - (n - new_row)][j - old_col] = true;
				diff_fish_check_north_south[i - (n - new_row) - 1][j - old_col] = true;
			}

			int south_diff = abs(fishing_pot[i][j] - south);
			if (south != 0 && fishing_pot[i][j] != 0 &&
				(diff_fish_check_north_south[i - (n - new_row)][j - old_col] == false || diff_fish_check_north_south[i - (n - new_row) + 1][j - old_col] == false)) {

				if (fishing_pot[i][j] > south) {
					diff_fish_num[i - (n - new_row)][j - old_col] += -south_diff / 5;
					diff_fish_num[i - (n - new_row) + 1][j - old_col] += south_diff / 5;
				}
				else {
					diff_fish_num[i - (n - new_row)][j - old_col] += south_diff / 5;
					diff_fish_num[i - (n - new_row) + 1][j - old_col] += -south_diff / 5;
				}

				diff_fish_check_north_south[i - (n - new_row)][j - old_col] = true;
				diff_fish_check_north_south[i - (n - new_row) + 1][j - old_col] = true;
			}

			int east_diff = abs(fishing_pot[i][j] - east);
			if (east != 0 && fishing_pot[i][j] != 0 &&
				(diff_fish_check_east_west[i - (n - new_row)][j - old_col] == false || diff_fish_check_east_west[i - (n - new_row)][j - old_col + 1] == false)) {

				if (fishing_pot[i][j] > east) {
					diff_fish_num[i - (n - new_row)][j - old_col] += -east_diff / 5;
					diff_fish_num[i - (n - new_row)][j - old_col + 1] += +east_diff / 5;
				}
				else {
					diff_fish_num[i - (n - new_row)][j - old_col] += +east_diff / 5;
					diff_fish_num[i - (n - new_row)][j - old_col + 1] += -east_diff / 5;
				}

				diff_fish_check_east_west[i - (n - new_row)][j - old_col] = true;
				diff_fish_check_east_west[i - (n - new_row)][j - old_col + 1] = true;
			}

			int west_diff = abs(fishing_pot[i][j] - west);
			if (east != 0 && fishing_pot[i][j] != 0 &&
				(diff_fish_check_east_west[i - (n - new_row)][j - old_col] == false || diff_fish_check_east_west[i - (n - new_row)][j - old_col - 1] == false)) {

				if (fishing_pot[i][j] > east) {
					diff_fish_num[i - (n - new_row)][j - old_col] += -west_diff / 5;
					diff_fish_num[i - (n - new_row)][j - old_col - 1] += west_diff / 5;
				}
				else {
					diff_fish_num[i - (n - new_row)][j - old_col] += west_diff / 5;
					diff_fish_num[i - (n - new_row)][j - old_col - 1] += -west_diff / 5;
				}

				diff_fish_check_east_west[i - (n - new_row)][j - old_col] = true;
				diff_fish_check_east_west[i - (n - new_row)][j - old_col - 1] = true;
			}
		}
	}

	for (int i = 0; i < new_row; ++i) {
		for (int j = 0; j < n - old_col; ++j) {
			cout << diff_fish_num[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;


	for (int i = n - new_row; i < n; ++i) {
		for (int j = old_col; j < n; ++j) {
			fishing_pot[i][j] += diff_fish_num[i - (n - new_row)][j - old_col];
		}
	}


	for (int i = n - new_row; i < n; ++i) {
		for (int j = old_col; j < n; ++j) {
			cout << fishing_pot[i][j] << " ";
		}
		cout << endl;
	}

	//fishing_pot[n - 2][1] = fishing_pot[n - 1][0];

	//fishing_pot[n - 2][2] = fishing_pot[n - 1][1];
	//fishing_pot[n - 2][3] = fishing_pot[n - 2][1];

	//fishing_pot[n - 3][4] = fishing_pot[n - 1][2];
	//fishing_pot[n - 3][5] = fishing_pot[n - 2][2];
	//fishing_pot[n - 2][4] = fishing_pot[n - 1][3];
	//fishing_pot[n - 2][5] = fishing_pot[n - 2][3];

	//fishing_pot[n - 3][6] = fishing_pot[n - 1][4];
	//fishing_pot[n - 3][7] = fishing_pot[n - 2][4];
	//fishing_pot[n - 3][8] = fishing_pot[n - 3][4];
	//fishing_pot[n - 2][6] = fishing_pot[n - 1][5];
	//fishing_pot[n - 2][7] = fishing_pot[n - 2][5];
	//fishing_pot[n - 2][8] = fishing_pot[n - 3][5];

	//fishing_pot[n - 4][9] = fishing_pot[n - 1][6];
	//fishing_pot[n - 4][10] = fishing_pot[n - 2][6];
	//fishing_pot[n - 4][11] = fishing_pot[n - 3][6];
	//fishing_pot[n - 3][9] = fishing_pot[n - 1][7];
	//fishing_pot[n - 3][10] = fishing_pot[n - 2][7];
	//fishing_pot[n - 3][11] = fishing_pot[n - 3][7];
	//fishing_pot[n - 2][9] = fishing_pot[n - 1][8];
	//fishing_pot[n - 2][10] = fishing_pot[n - 2][8];
	//fishing_pot[n - 2][11] = fishing_pot[n - 3][8];



	//fishing_pot[n - 1][0] = 0;

	//fishing_pot[n - 2][1] = 0;
	//fishing_pot[n - 1][1] = 0;

	//fishing_pot[n - 1][2] = 0;
	//fishing_pot[n - 2][2] = 0;
	//fishing_pot[n - 1][3] = 0;
	//fishing_pot[n - 2][3] = 0;





	delete[] fishing_pot;
	fin.close();
	return 0;
}
