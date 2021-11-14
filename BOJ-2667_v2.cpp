#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

#define HOUSE (1)
#define EMPTY (0)

using namespace std;

int n;
int direction_x[4] = { 1, 0, -1, 0 };
int direction_y[4] = { 0, 1, 0, -1 };

bool is_house(int x, int y, vector<vector<int>> map)
{
	if (x < 0 || y < 0 || x >= n || y >= n) {
		return false;
	}
	else {
		return map[x][y] == HOUSE;
	}
}

void find_housing_complex_recursive(vector<vector<int>>& map, int x, int y, int* count)
{

	if (is_house(x, y, map)) {
		map[x][y] = EMPTY;
		(*count)++;

		for (int i = 0; i < 4; ++i) {
			if (is_house(x + direction_x[i], y + direction_y[i], map)) {
				find_housing_complex_recursive(map, x + direction_x[i], y + direction_y[i], count);
			}
		}
	}
	else {
		return;
	}
}

int main(void)
{
	cin.tie(NULL);
	cin >> n;

	vector<vector<int>> map(n, vector<int>(n));
	vector<int> housing_complex_number;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			char house;
			cin >> house;
			map[i][j] = house - 48;
		}
	}


	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int count = 0;
			find_housing_complex_recursive(map, i, j, &count);
			if (count > 0) {
				housing_complex_number.push_back(count);
			}
		}
	}

	sort(housing_complex_number.begin(), housing_complex_number.end());

	cout << housing_complex_number.size() << endl;
	for (int i = 0; i < housing_complex_number.size(); ++i) {
		cout << housing_complex_number[i] << endl;
	}

	return 0;
}
