#include<iostream>

using namespace std;

int factorialRecursive(int n, int fac)
{
	if (n <= 1)
	{
		return fac;
	}

	return factorialRecursive(n - 1, n * fac);
}

int factorial(int n)
{
	return factorialRecursive(n, 1);
}

int main(void)
{
	printf("%d!= %d", 6, factorial(6));

	return 0;
}
