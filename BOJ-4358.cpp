#include <iostream>
#include <map>
#include<vector>
#include<algorithm>
#include <string>
using namespace std;

int main(void)
{
	map<string, int> map;
	string species;
	int count = 0;
	while (getline(cin, species)) {
	
		if (map.find(species) != map.end()) {
			map[species]++;
		}
		else {
			map.insert(make_pair(species, 1));
		}
		count++;
	}

	vector<pair<string, int>> sorted;
	
	for (const auto& item : map) {
		sorted.emplace_back(item);
	}

	sort(sorted.begin(), sorted.end(),
		[](const auto& x, const auto& y) {
			return x.first < y.first;
		});


	for (int i = 0; i < sorted.size(); ++i) {
		cout << sorted[i].first << " ";
		printf("%.4f\n", (sorted[i].second / (float)count) * 100);
	}
	
}
