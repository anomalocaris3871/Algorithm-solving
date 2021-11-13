#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

#define HOUSE 1

using namespace std;

int n;

bool is_house(int x, int y, vector<vector<int>> map)
{
	if (x < 0 || y < 0 || x >= n || y >= n) {
		return false;
	}
	else {
		return map[x][y] == HOUSE;
	}
}

void find_housing_complex(vector<vector<int>>& map, vector<int>& housing_complex_number,
	int x, int y)
{

	int count = 0;
	queue<pair<int, int>> queue;
	queue.push(make_pair(x, y));

	while (!queue.empty()) {

		pair<int, int> location = queue.front();
		queue.pop();

		int location_x = location.first;
		int location_y = location.second;

		if (is_house(location_x, location_y, map)) {
			map[location_x][location_y] = 0;
			count += 1;

			if (is_house(location_x + 1, location_y, map)) {
				queue.push(make_pair(location_x + 1, location_y));
			}
			if (is_house(location_x - 1, location_y, map)) {
				queue.push(make_pair(location_x - 1, location_y));
			}
			if (is_house(location_x, location_y + 1, map)) {
				queue.push(make_pair(location_x, location_y + 1));
			}
			if (is_house(location_x, location_y - 1, map)) {
				queue.push(make_pair(location_x, location_y - 1));
			}
		}

	}
	if (count > 0) {
		housing_complex_number.push_back(count);
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
			find_housing_complex(map, housing_complex_number, i, j);
		}
	}

	sort(housing_complex_number.begin(), housing_complex_number.end());

	cout << housing_complex_number.size() << endl;
	for (int i = 0; i < housing_complex_number.size(); ++i) {
		cout << housing_complex_number[i] << endl;
	}

	return 0;
}
