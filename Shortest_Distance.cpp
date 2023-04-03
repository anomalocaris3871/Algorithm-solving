#include <iostream>
#include <fstream>
#include <queue>

int map[21][21] = { 0, };
bool trace[21] = { false, };
int status[21] = { 0, };

using namespace std;

void getMinOfEdge(queue<int>* q, int end, int range) {	

	while (!(q->empty())) {
		int node = q->front();
		q->pop();
	
		for (int i = 1; i <= range; ++i) {
			if (map[node][i] == 1 && trace[i] == false) {
				
				status[i] = status[node] + 1;
				trace[i] = true;
				q->push(i);
			}
				
		}
	}
	
}

int main(void) {

	int numberOfVertex;
	int numberOfEdge;

	ifstream fin("in1.txt");

	fin >> numberOfVertex >> numberOfEdge;
	for (int i = 0; i < numberOfEdge; ++i) {
		int vertex;
		int edge;

		fin >> vertex >> edge;
		map[vertex][edge] = 1;
	}


	queue<int> bfs;
	bfs.push(1);
	trace[1] = true;

	getMinOfEdge(&bfs, 6, numberOfVertex);

	for (int i = 2; i <= numberOfVertex; ++i) {
		cout << i  <<  " : " << status[i] << endl;
	}

	return 0;
}
