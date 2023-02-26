#include <iostream>
#include <fstream>
using namespace std;


int elements[11];
int n;
int m;
int totalCount = 0;

void dfs(int level, int partialSum) {


	if (level == n + 1) {
		return;
	}

	if (partialSum  + elements[level] == m || partialSum - elements[level] == m) {
		totalCount++;
	}

	dfs(level + 1, partialSum + elements[level]);
	dfs(level + 1, partialSum);
	dfs(level + 1, partialSum - elements[level]);
	
}

int main(void) {

	
	ifstream ifs("in5.txt");
	ifs >> n >> m;
	
	int element;
	int i = 1;
	while (i <= n) {
		ifs >> element;
		elements[i] = element;
		i++;
	}

	dfs(1, 0);

	if (totalCount > 0) {
		cout << totalCount << endl;
	}
	else {
		cout << "NO" << endl;
	}
	
	
	return 0;
}
