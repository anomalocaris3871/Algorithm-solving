#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	int n;	
	cin >> n;

	queue<int> queue;
	for (int i = 1; i <= n; ++i) {
		queue.push(i);
	}

	while(queue.size() != 1) {
		queue.pop();
		int reuse = queue.front();
		queue.pop();
		queue.push(reuse);
	}

	printf("%d\n", queue.front());
	
	return 0;
}
