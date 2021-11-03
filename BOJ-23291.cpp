#include<iostream>
#include<fstream>

using namespace std;

void spread_fish(int** fishing_pot, int row, int col, int n) {

	for (int i = n - row; i < n; ++i) {
		for (int j = col; j < n; ++j) {
			//north-south
			if (i + 1 < n) {
				if (fishing_pot[i][j] != 0 && fishing_pot[i + 1][j] != 0) {
					int diff = fishing_pot[i][j] - fishing_pot[i + 1][j];
					fishing_pot[i][j - n / 2] += -diff / 5;
					fishing_pot[i + 1][j - n / 2] += diff / 5;
				}
			}

			//east-west
			if (j + 1 < n) {
				if (fishing_pot[i][j] != 0 && fishing_pot[i][j + 1] != 0) {
					int diff = fishing_pot[i][j] - fishing_pot[i][j + 1];
					fishing_pot[i][j - n / 2] += -diff / 5;
					fishing_pot[i][(j + 1) - n / 2] += diff / 5;

				}
			}
		}
	}

	for (int i = n - row; i < n; ++i) {
		for (int j = col; j < n; ++j) {
			fishing_pot[i][j] += fishing_pot[i][j - n / 2];
			fishing_pot[i][j - n / 2] = 0;
		}
	}
}

int main(void) {
	int n, k;

	//ifstream fin("test.txt");

	//if (fin.fail()) {
	//	cerr << "error" << endl;
	//}

	cin >> n >> k;
	int** fishing_pot = new int* [n];

	for (int i = 0; i < n;++i) {
		fishing_pot[i] = new int[n];
		for (int j = 0;j < n; ++j) {
			fishing_pot[i][j] = 0;
		}
	}

	for (int i = 0; i < n; ++i) {
		cin >> fishing_pot[n - 1][i];
	}


	int count = 0;
	int max = 0;
	int min = 0;

	do {

		min = fishing_pot[n - 1][0];
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

		bool bFlag = false;

		while (true) {
			new_row = cnt + 1;
			new_col += cnt;

			//if (new_col >= n) {
			//	bFlag = true;
			//	break;
			//}

			if (cnt > n - new_col) {
				bFlag = true;
				break;
			}

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

			//if (cnt > n - new_col) {
			//	break;
			//}

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



		int row = 0;
		int col = 0;
		if (bFlag == true) {
			row = cnt;
		}
		else {
			row = cnt + 1;
		}
		col = old_col;

		spread_fish(fishing_pot, row, old_col, n);


		if (bFlag == true) {
			row = n - cnt;
			col = n;
		}
		else {
			row = n - new_row;
			col = old_col + cnt;
		}

		int col_pos = 0;
		for (int j = old_col; j < col; ++j) {
			for (int i = n - 1; i >= row; --i) {
				if (fishing_pot[i][j] != 0) {
					fishing_pot[n - 1][col_pos] = fishing_pot[i][j];
					if (i != n - 1) {
						fishing_pot[i][j] = 0;
					}
					col_pos++;
				}




			}
		}

		int len = n / 2;
		for (int j = 0; j < len; ++j) {
			fishing_pot[n - 2][len + j] = fishing_pot[n - 1][len - (j + 1)];
			fishing_pot[n - 1][len - (j + 1)] = 0;
		}

		for (int j = 0;j < len / 2;++j) {
			fishing_pot[n - 3][len + len / 2 + j] = fishing_pot[n - 2][len + len / 2 - (j + 1)];
			fishing_pot[n - 4][len + len / 2 + j] = fishing_pot[n - 1][len + len / 2 - (j + 1)];
			fishing_pot[n - 2][len + len / 2 - (j + 1)] = 0;
			fishing_pot[n - 1][len + len / 2 - (j + 1)] = 0;
		}


		if (bFlag == true) {
			row = n;
		}
		else {
			row = n / 2;
		}

		spread_fish(fishing_pot, row, n - n / 4, n);


		col_pos = 0;
		for (int j = n - n / 4; j < n; ++j) {
			for (int i = n - 1; i >= n - 4; --i) {
				fishing_pot[n - 1][col_pos] = fishing_pot[i][j];
				fishing_pot[i][j] = 0;
				col_pos++;
			}
		}

		min = fishing_pot[n - 1][0];
		max = fishing_pot[n - 1][0];
		for (int i = 0; i < n; ++i) {
			if (max < fishing_pot[n - 1][i]) {
				max = fishing_pot[n - 1][i];
			}

			if (min > fishing_pot[n - 1][i]) {
				min = fishing_pot[n - 1][i];
			}
		}
		count++;


	} while (k < max - min);

	cout << count << endl;


	delete[] fishing_pot;

	//fin.close();
	return 0;
}
