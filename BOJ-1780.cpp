#include<fstream>
#include<iostream>

using namespace std;
#define MINUS -1
#define ZERO  0
#define PLUS  1

int get_number_of_paper_recursive(int** paper, int row, int col, int len, int kind)
{
	if (len <= 1) {
		if (paper[row][col] == kind) {
			return 1;
		}
		else {
			return 0;
		}
	}

	int i, j;
	for (i = row; i < row + len; ++i) {
		for (j = col; j < col + len;++j) {
			if (paper[i][j] != kind) {
				break;
			}
		}

		if (j < col + len) {
			break;
		}
	}

	if (i < row + len) {
		return get_number_of_paper_recursive(paper, row, col, len / 3, kind)
			+ get_number_of_paper_recursive(paper, row, col + len / 3, len / 3, kind)
			+ get_number_of_paper_recursive(paper, row, col + len / 3 * 2, len / 3, kind)
			+ get_number_of_paper_recursive(paper, row + len / 3, col, len / 3, kind)
			+ get_number_of_paper_recursive(paper, row + len / 3, col + len / 3, len / 3, kind)
			+ get_number_of_paper_recursive(paper, row + len / 3, col + len / 3 * 2, len / 3, kind)
			+ get_number_of_paper_recursive(paper, row + len / 3 * 2, col, len / 3, kind)
			+ get_number_of_paper_recursive(paper, row + len / 3 * 2, col + len / 3, len / 3, kind)
			+ get_number_of_paper_recursive(paper, row + len / 3 * 2, col + len / 3 * 2, len / 3, kind);
	}
	else {
		return 1;
	}
}


int main(void)
{
	int n;
	cin >> n;

	int** paper = new int* [n];
	for (int i = 0; i < n; ++i) {
		paper[i] = new int[n];
		for (int j = 0; j < n; ++j) {
			cin >> paper[i][j];
		}
	}

	cout << get_number_of_paper_recursive(paper, 0, 0, n, MINUS) << endl;
	cout << get_number_of_paper_recursive(paper, 0, 0, n, ZERO) << endl;
	cout << get_number_of_paper_recursive(paper, 0, 0, n, PLUS) << endl;

	return 0;
}
