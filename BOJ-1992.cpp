#include<fstream>
#include<iostream>

using namespace std;

string compress_recursive(string** picture, int row, int col, int len)
{
	int count = 0;

	if (len == 1) {
		return picture[row][col];
	}

	int i, j;
	for (i = row; i < row + len; ++i) {
		for (j = col; j < col + len; ++j) {
			if (picture[i][j].compare(picture[row][col]) != 0) {
				break;
			}
		}

		if (j < col + len) {
			break;
		}
	}

	if (i < row + len) {
		return "(" + compress_recursive(picture, row, col, len / 2) +
			compress_recursive(picture, row, col + len / 2, len / 2) +
			compress_recursive(picture, row + len / 2, col, len / 2) +
			compress_recursive(picture, row + len / 2, col + len / 2, len / 2) + ")";

	}
	else {
		return picture[row][col];
	}
}

int main(void)
{

	int n;
	cin >> n;

	string** paper = new string * [n];
	for (int i = 0; i < n; ++i) {
		paper[i] = new string[n];
	}

	for (int i = 0; i < n; ++i) {
		string row = "";
		cin >> row;
		for (int j = 0; j < n; ++j) {
			paper[i][j] = row[j];
		}
	}

	cout << compress_recursive(paper, 0, 0, n) << endl;

	return 0;
}
