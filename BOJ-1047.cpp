#include <iostream> 
#include <vector> 
#include <algorithm>
#include <map>
#include <climits>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	vector<tuple<int, int, int> > vv;
	vector<int> xcor, ycor;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int y, x, val;
		cin >> x >> y >> val;
		vv.push_back(make_tuple(val, y, x));
		ycor.push_back(y);
		xcor.push_back(x);
	}

	sort(ycor.begin(), ycor.end());
	sort(xcor.begin(), xcor.end());
	sort(vv.rbegin(), vv.rend());       //desc

	int answer = INT_MAX;
	int v, y, x;
	int down, up, right, left;

	for (int tup = 0; tup < ycor.size(); tup++) {
		for (int tleft = 0; tleft < xcor.size(); tleft++) {
			for (int tdown = ycor.size() - 1; tdown >= tup; tdown--) {
				for (int tright = xcor.size() - 1; tright >= tleft; tright--) {

					left = xcor[tleft];
					right = xcor[tright];
					up = ycor[tup];
					down = ycor[tdown];

					int perimeter = 2 * ((down - up) + (right - left));
					int treeCount = 0;
					int currentFenceLength = 0;

					bool valid = true;
					for (const tuple<int, int, int>& tt : vv) {
						tie(v, y, x) = tt;
						if (y < up || y > down || x < left || x > right) {
							treeCount++;
							currentFenceLength += v;
							if (treeCount >= answer) {
								valid = false;
								break;
							}
						}
					}

					if (!valid) {
						break;
					}

					if (perimeter <= currentFenceLength && treeCount < answer) {
						answer = treeCount;
						break;
					}

					// cut inner tree 
					for (const tuple<int, int, int>& tt : vv) {
						tie(v, y, x) = tt;
						if (y >= up && y <= down && x >= left && x <= right) {
							treeCount++;
							currentFenceLength += v;
							if (treeCount >= answer) {
								valid = false;
								break;
							}

							if (currentFenceLength >= perimeter) {
								answer = treeCount;
								break;
							}
						}
					}
				}
			}
		}
	}

	cout << answer << '\n';
	return 0;
}
