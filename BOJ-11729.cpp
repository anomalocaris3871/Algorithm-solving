#include<iostream>
#include<string>

using namespace std;



string make_hanoi_tower_recursive(int n, int from, int tmp, int to, int *count)
{
	if (n == 1) {
		(*count)++;
		return to_string(from) + " " + to_string(to) + '\n';
	}
	else {
		string result = "";

		result.append(make_hanoi_tower_recursive(n - 1, from, to, tmp, count));
		
		result.append(to_string(from) + " " + to_string(to) + '\n');
		(*count)++;
		
		result.append(make_hanoi_tower_recursive(n - 1, tmp, from, to, count));
		
		return result;
	}

}

int main(void)
{
	int n;
	cin >> n;

	int count = 0;
	
	string result = make_hanoi_tower_recursive(n, 1, 2, 3, &count);

	cout << count << endl << result << endl;

	return 0;
}
