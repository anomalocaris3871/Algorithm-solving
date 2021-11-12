#include<iostream>
#include<string>
#define MOD 1000000007

typedef long long ll;
using namespace std;



ll get_factorial_recursive(int n)
{
	if (n == 0 || n == 1) {
		return 1;
	}

	return (n * (get_factorial_recursive(n - 1) % MOD) % MOD);
}

ll pow(ll base, int exponent)
{
	if (exponent == 0) {
		return 1;
	}

	if (exponent % 2 > 0) {
		return pow(base, exponent - 1) * base % MOD;
	}

	ll half = pow(base, exponent / 2);

	return (half % MOD) * (half % MOD) % MOD;
}


ll get_binomial_coefficient(int n, int k)
{
	return get_factorial_recursive(n)
		* pow((get_factorial_recursive(k) * get_factorial_recursive(n - k) % MOD), MOD - 2) % MOD;
}




int main(void)
{

	int n, k;
	cin >> n >> k;

	cout << get_binomial_coefficient(n, k) << endl;

	return 0;
}
