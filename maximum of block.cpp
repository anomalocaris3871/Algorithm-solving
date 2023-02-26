#include <iostream>
#include <fstream>

using namespace std;

int front_side[10];
int right_side[10];

int main(void) {

	ifstream fin("in5.txt");

	int max = 0;
	int n;
	fin >> n;
	for (int i = 0; i < n; ++i) {
		fin >> front_side[i];
	}

	for (int i = 0; i < n; ++i) {
		fin >> right_side[i];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (front_side[j] != 0) {
				if (right_side[i] > front_side[j]) {
					max += front_side[j];
				}
				else {
					max += right_side[i];
				}
			}
		}
	}

	cout << max;
	
	return 0;
}
