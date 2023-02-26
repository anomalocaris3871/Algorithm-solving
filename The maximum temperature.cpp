#include<stdio.h>
#include <vector>

using namespace std;

int main(void)
{

	vector<int> temperatures;
	int n;
	int continued_day;

	scanf("%d %d", &n, &continued_day);
	for (int i = 0; i < n; ++i) {
		int temperature;
		scanf("%d", &temperature);
		temperatures.push_back(temperature);
	}

	
	int max_sum = 0;
	int temperature_sum = 0;
	for (int i = 0; i < continued_day; ++i) {
		temperature_sum += temperatures[i];
		max_sum = temperature_sum;
	}

	for (int i = continued_day; i < n; ++i) {
		temperature_sum += temperatures[i] - temperatures[i - continued_day];

		if (temperature_sum > max_sum) {
			max_sum = temperature_sum;
		}
	}

	printf("%d\n", max_sum);

	return 0;
}
