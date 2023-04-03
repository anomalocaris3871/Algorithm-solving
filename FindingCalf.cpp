#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

int position[10001] = { 0, };
int range[3] = { 1, -1, 5 };

int main(void) {

	fstream fin("in5.txt");

	int start;
	int end;

	fin >> start >> end;

	queue<int> bfs;
	
	bfs.push(start);
	position[start] = 1;

	int currentPosition = start;
	while (!bfs.empty()) {
		
		currentPosition = bfs.front();
		bfs.pop();

		int nextPosition;
		for (int i = 0; i < 3; ++i) {

			nextPosition = currentPosition + range[i];
			if (nextPosition < 1 || nextPosition > 100000) {
				continue;
			}

			if (position[nextPosition] == 0) {
				position[nextPosition] = position[currentPosition] + 1;
				bfs.push(nextPosition);
			}

			if (nextPosition == end) {
				goto end;
			}
		}
	end:
		if (nextPosition == end) {
			break;
		}
	}

	cout << position[currentPosition] << endl;

	return 0;
}
