#include <iostream>
#define MAX (9)
using namespace std;

int sequence[MAX] = { 0, };
bool visited[MAX] = { false, };

int n, m;

void permutate(int index)
{
	if (index == m) {
		for (int i = 0; i < m; ++i) {
			cout << sequence[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; ++i) {
		if (!visited[i]) {
			sequence[index] = i;
			visited[i] = true;
			permutate(index + 1);
			visited[i] = false;
		}
	}
}

int main(void)
{
	cin.tie(0);
	cin >> n >> m;

	permutate(0);
	return 0;
}
