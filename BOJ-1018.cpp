#include<iostream>
#include<vector>
#include<algorithm>

#define LENGTH (8)
#define INF (9999)

using namespace std;

int isValid(vector<vector<char>> board, int cx, int cy, int length, int height)
{

	if (cy + LENGTH > height || cx + LENGTH > length) {
		return INF;
	}

	int min = 32;


	int countBlack = 0;
	int countWhite = 0;

	for (int y = cy; y < cy + LENGTH; ++y) {
		for (int x = cx; x < cx + LENGTH; ++x) {

			if ((y + x) % 2 == 0) {
				if (board[y][x] == 'B') {
					countWhite++;
				}
				else {
					countBlack++;
				}
			}
			else {
				if (board[y][x] == 'B') {
					countBlack++;
				}
				else {
					countWhite++;
				}
			}
		}
	}

	min = min > countBlack ? countBlack : min;
	min = min > countWhite ? countWhite : min;
	return min;
}

int main(void)
{
	cin.tie(0);

	int y, x;
	cin >> y >> x;

	vector<vector<char>> board(y, vector<char>(x));

	for (int i = 0; i < y; ++i) {
		string row;
		cin >> row;
		for (int j = 0; j < x; ++j) {
			board[i][j] = row[j];
		}
	}

	vector<int> count;
	for (int i = 0; i < y; ++i) {
		for (int j = 0; j < x; ++j) {
			count.push_back(isValid(board, j, i, x, y));
		}
	}

	sort(count.begin(), count.end());
	cout << count[0] << endl;

	return 0;
}
