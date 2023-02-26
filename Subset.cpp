#include <iostream>

using namespace std;


int input;
int level[11] = { 0, };

void dfs(int n) {
	
	if (n == input + 1) {
		for (int i = 1; i <= input; ++i) {
			if (level[i] == 1) {
				cout << i << " ";
			}
		}
		cout << endl;
		return;
	}

	level[n] = 1;
	dfs(n + 1);
	level[n] = 0;
	dfs(n + 1);

}

int main(void) {

	cin >> input;

	dfs(1);

	return 0;
}
