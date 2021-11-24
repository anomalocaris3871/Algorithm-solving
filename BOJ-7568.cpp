#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<pair<int, int>> people(n);

	for (int i = 0; i < n; ++i) {
		int weight, height;
		cin >> weight >> height;
		people[i] = make_pair(weight, height);
	}

	vector<int> rank(n);

	for (int i = 0; i < n; ++i) {
		int count = 0;
		for (int j = 0; j < n; ++j) {
			
			if (i != j) {
				if (people[i].first < people[j].first && people[i].second < people[j].second) {
					count++;
				}
			}
		}
		rank[i] = count + 1;
	}

	for (int i = 0; i < n; ++i) {
		cout << rank[i] << " ";
	}
	cout << endl;

	return 0;
}
