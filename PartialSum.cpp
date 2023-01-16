#include <iostream>
#include <fstream>
using namespace std;


int elements[11];
int totalSum = 0;
bool endFlag = false;
int n;

void dfs(int level, int partialSum) {
	
	if (endFlag == true) {
		return;
	}

	if (level == n + 1) {
		if (partialSum == totalSum - partialSum) {
			endFlag = true;	
		}

		return;
	}

	dfs(level + 1, partialSum + elements[level]);
	dfs(level + 1, partialSum);

}

int main(void) {

	ifstream ifs("in1.txt");
	ifs >> n;

	int i = 1;
	int element = 0;
	while (i <= n) {
		ifs >> element;
		elements[i++] = element;
		totalSum += element;
	}

	dfs(1, 0);

	if (endFlag == true) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	return 0;
}
