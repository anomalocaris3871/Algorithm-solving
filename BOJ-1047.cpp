#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <climits>

using namespace std;

int result = INT_MAX;

void getCuttedTreeCount(vector<tuple<int, int, int>>& treeInfo, int addedFenceLength, int& cuttedTreeCount)
{
	int north = INT_MAX;
	int south = INT_MIN;
	int east = INT_MIN;
	int west = INT_MAX;

	int removeTree = INT_MAX;

	int neededFenceLength = 0;

	int length = treeInfo.size();
	for (int i = 0; i < length; ++i) {

		tuple<int, int, int> backUp = treeInfo[i];
		int currentFenceLength = get<2>(backUp);
		treeInfo.erase(treeInfo.begin() + i);

		int neededFenceLength = 0;
		for (int j = 0; j < treeInfo.size(); ++j) {
			north = min(get<0>(treeInfo[j]), north);
			south = max(get<0>(treeInfo[j]), south);
			east = max(get<1>(treeInfo[j]), east);
			west = min(get<1>(treeInfo[j]), west);
		}

		neededFenceLength = (south - north) * 2 + (east - west) * 2;
		cuttedTreeCount++;
		currentFenceLength += addedFenceLength;
		if (currentFenceLength >= neededFenceLength) {
			result = min(result, cuttedTreeCount);
			treeInfo.insert(treeInfo.begin() + i, backUp);
			currentFenceLength -= addedFenceLength;
			cuttedTreeCount--;
			return;
		}

		getCuttedTreeCount(treeInfo, currentFenceLength, cuttedTreeCount);
		treeInfo.insert(treeInfo.begin() + i, backUp);
		currentFenceLength -= addedFenceLength;
		cuttedTreeCount--;
	}
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

	cout << result << endl;

	return 0;
}