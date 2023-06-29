#include <iostream>

using namespace std;

int main(void) {

	
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int M, N, x, y;
		cin >> M >> N >> x >> y;

		x = x - 1;
		y = y - 1;
		bool ok = false;
		for (int yYear = x; yYear < M * N; yYear += M) {
			if (yYear % N == y) {
				cout << yYear + 1 << endl;
				ok = true;
				break;
			}
		}


		if (!ok) {
			cout << -1 << endl;
		}
	}





	return 0;
}
