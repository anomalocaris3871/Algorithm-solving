#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef vector<vector<ll>> matrix;


matrix operator *(const matrix& matrix1, const matrix& matrix2)
{
	ll size = matrix1.size();
	matrix result(size, vector<ll>(size));
	for (ll i = 0; i < size; ++i) {
		for (ll j = 0; j < size; ++j) {
			for (ll k = 0; k < size; ++k) {
				result[i][j] += matrix1[i][k] * matrix2[k][j];
			}
			result[i][j] %= 1000;
		}
	}

	return result;
}

matrix pow_recursive(const matrix& square_matrix, ll power)
{
	ll size = square_matrix.size();
	if (power == 0) {
		matrix identity = matrix(size, vector<ll>(size));

		for (ll i = 0; i < size; ++i) {
			identity[i][i] = 1;
		}

		return identity;
	}

	if (power % 2 > 0) {
		return pow_recursive(square_matrix, power - 1) * square_matrix;
	}

	matrix half = pow_recursive(square_matrix, power / 2);

	return half * half;
}




int main(void)
{
	ll n, pow;
	cin >> n >> pow;


	matrix square_matrix(n, vector<ll>(n));
	for (ll i = 0; i < n; ++i) {
		for (ll j = 0; j < n; ++j) {
			cin >> square_matrix[i][j];
		}
	}

	matrix result = pow_recursive(square_matrix, pow);

	for (ll i = 0; i < n; ++i) {
		for (ll j = 0; j < n; ++j) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
