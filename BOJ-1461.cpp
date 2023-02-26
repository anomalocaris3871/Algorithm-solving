#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

vector<int> bookPosition;
vector<int> bookPositionPositive;
vector<int> bookPositionNegative;


int main(void)
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		int pos;
		cin >> pos;
		bookPosition.push_back(pos);
	}

	for (int i = 0; i < n; ++i) {
		if (bookPosition[i] > 0) {
			bookPositionPositive.push_back(bookPosition[i]);
		}
		else {
			bookPositionNegative.push_back(abs(bookPosition[i]));
		}
	}

	
	sort(bookPositionPositive.begin(), bookPositionPositive.end(), [](int a, int b) {
		return a > b;});

	sort(bookPositionNegative.begin(), bookPositionNegative.end(), [](int a, int b) {
		return a > b;});

	vector<int> maxValue;
	vector<int> minValue;

	if (bookPositionPositive.size() > 0 && bookPositionNegative.size() > 0) {
		if (bookPositionPositive[0] > bookPositionNegative[0]) {
			maxValue = bookPositionPositive;
			minValue = bookPositionNegative;
		}
		else {
			maxValue = bookPositionNegative;
			minValue = bookPositionPositive;
		}
	}
	else if (bookPositionNegative.size() == 0) {
		maxValue = bookPositionPositive;
	}
	else if (bookPositionPositive.size() == 0) {
		maxValue = bookPositionNegative;
	}

	
	int ans = maxValue[0];

	for (int i = 1; i < maxValue.size(); ++i) {

		if (i % m == 0) {
			ans += maxValue[i] * 2;

		}
	}

	for (int i = 0; i < minValue.size(); ++i) {
		
		if (i % m == 0) {
			ans += minValue[i] * 2;
		}
	}

	cout << ans << endl;
	

	return 0;
}
