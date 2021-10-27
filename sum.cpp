#include<iostream>

using namespace std;

int sumTailRecursive(int n, int sum) 
{
	if (n <= 0) 
	{
		return sum;
	}

	return sumTailRecursive(n - 1, sum + n);
}

int sumRecursive(int n)
{
	return sumTailRecursive(n, 0);
}

int main(void)
{
	int sum = sumTailRecursive(10, 0);
	printf("%d : %d", 10, sum);

	return 0;
}
