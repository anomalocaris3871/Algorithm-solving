#include <iostream>
#include <vector>
#include <tuple>
#include <cstdlib>

using namespace std;

void getCuttedTreeCount(vector<tuple<int, int, int>>& treeInfo, int currentFenceLength, int& cuttedTreeCount)
{
	int north = INT_MAX;
	int south = INT_MIN;
	int east = INT_MIN;
	int west = INT_MAX;


	int removeTree = INT_MAX;

	int neededFenceLength = 0;
	int removeTreeIndex = 0;
	for (int i = 0; i < treeInfo.size(); ++i) {
		for (int j = 0; j < treeInfo.size(); ++j) {
			if (i != j) {
				north = min(get<0>(treeInfo[j]), north);
				south = max(get<0>(treeInfo[j]), south);
				east = max(get<1>(treeInfo[j]), east);
				west = min(get<1>(treeInfo[j]), west);
			}
		}

		if (removeTree > ((south - north) * 2 + (east - west) * 2) - (get<2>(treeInfo[i]) + currentFenceLength)) {
			removeTree = ((south - north) * 2 + (east - west) * 2) - (get<2>(treeInfo[i]) + currentFenceLength);

			removeTreeIndex = i;
			neededFenceLength = (south - north) * 2 + (east - west) * 2;
		}
	}

	currentFenceLength += get<2>(treeInfo[removeTreeIndex]);

	cuttedTreeCount++;
	if (currentFenceLength >= neededFenceLength) {
		return;
	}

	treeInfo.erase(treeInfo.begin() + removeTreeIndex);
	getCuttedTreeCount(treeInfo, currentFenceLength, cuttedTreeCount);
}


int main(void)
{
	int n;
	cin >> n;
	vector<tuple<int, int, int>> treeInfo(n);

	for (int i = 0; i < n; ++i) {
		int x, y, fenceLength;
		cin >> x >> y >> fenceLength;

		treeInfo[i] = make_tuple(x, y, fenceLength);
	}

	int treeCount = 0;
	getCuttedTreeCount(treeInfo, 0, treeCount);

	cout << treeCount << endl;

	return 0;
}