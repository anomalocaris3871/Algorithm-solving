#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(void) {

	int n;
	while (true) {
		cin >> n;

		if (n == 0) {
			break;
		}

		vector<int> series(n);
		for (int i = 0; i < n;++i) {
			cin >> series[i];
		}

		vector<int> selected;
		for (int i = 0; i < n - 6; ++i) {
			selected.push_back(0);
		}

		for (int i = 0; i < 6; ++i) {
			selected.push_back(1);
		}

		vector<vector<int>> ans;
		do {
			vector<int> line;
			for (int i = 0; i < n; ++i) {
				if (selected[i] == 1) {
					line.push_back(series[i]);
				}
			}
			
			ans.push_back(line);

		} while (next_permutation(selected.begin(), selected.end()));
		sort(ans.begin(), ans.end());

		for (int i = 0; i < ans.size();++i) {
			for (int j = 0; j < 6; ++j) {
				cout << ans[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	return 0;
}
