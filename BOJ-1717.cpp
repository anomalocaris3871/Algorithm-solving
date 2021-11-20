#include <iostream>

using namespace std;

int sets[1000001];

int find_set(int num)
{
	if (sets[num] < 0) {
		return num;
	}

	int parent = find_set(sets[num]);

	sets[num] = parent;

	return parent;
}

void union_sets(int set1, int set2)
{
	set1 = find_set(set1);
	set2 = find_set(set2);

	if (set1 > set2) {
		sets[set1] = set2;
	}
	else if (set1 < set2) {
		sets[set2] = set1;
	}
	else {
		return;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);

	cin.tie(0); 

	int n, m;
	cin >> n >> m;

	for (int i = 0; i <= n; ++i) {
		sets[i] = -1;
	}


	for (int i = 0; i < m; i++) {
		int op, s1, s2;

		cin >> op >> s1 >> s2;

		if (op == 0) {
			union_sets(s1, s2);
		}
		else {
			if (find_set(s1) == find_set(s2)) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
		}

	}

	return 0;

}
