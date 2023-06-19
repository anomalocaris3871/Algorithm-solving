#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int check(vector<string>& board) {
	int max = 1;
	int n = board.size();
	for (int i = 0; i < n; ++i) {
		int current = 1;
		for (int j = 1; j < n ; ++j) {
			
			if (board[i][j] == board[i][j-1]) {
				current += 1;
			}
			else {
				current = 1;
			}
			if (current > max) {
				max = current;
			}
		}


		current = 1;

		for (int j = 1; j < n; ++j) {
			if (board[j - 1][i] == board[j][i]) {
				current += 1;
			}
			else {
				current = 1;
			}
			if (current > max) {
				max = current;
			}
		}
	}

	return max;

}

int main(void) {

	int n;
	cin >> n;
	vector<string> board(n);
	for (int i = 0; i < n; ++i) {
		cin >> board[i];
	}

	int max = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - 1 ; ++j) {
		
			swap(board[i][j], board[i][j + 1]);
			int result = check(board);
			if (result > max) {
				max = result;
			}
			swap(board[i][j], board[i][j + 1]);

			
			swap(board[j + 1][i], board[j][i]);
			result = check(board);
			if (result > max) {
				max = result;
			}
			swap(board[j + 1][i], board[j][i]);
		
		}
	}

	cout << max << endl;


	return 0;
}
