#include<fstream>
#include<iostream>
#define WHITE 0
#define BLUE 1

using namespace std;

int get_number_of_paper_recursive(int** paper, int color, int row, int col, int len)
{
	int count = 0;

	if (len == 1) {
		if (paper[row][col] == color) {
			return 1;
		}
		else {
			return 0;
		}
	}

	int i, j;
	for (i = row; i < row + len; ++i) {
		for (j = col; j < col + len; ++j) {
			if (paper[i][j] != color) {
				break;
			}
		}

		if (j < col + len) {
			break;
		}
	}

	if (i < row + len) {
		return get_number_of_paper_recursive(paper, color, row, col, len / 2) +
		get_number_of_paper_recursive(paper, color, row, col + len / 2, len / 2) +
		get_number_of_paper_recursive(paper, color, row + len / 2, col, len / 2) +
		get_number_of_paper_recursive(paper, color, row + len / 2, col + len / 2, len / 2);

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
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> paper[i][j];
		}
	}


	cout << get_number_of_paper_recursive(paper, WHITE, 0, 0, n) << endl;
	cout << get_number_of_paper_recursive(paper, BLUE, 0, 0, n) << endl;

	return 0;
}
