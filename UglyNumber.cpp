#include <iostream>

using namespace std;

int ugly_number[1500];

int main(void) {

	int n;
	cin >> n;

	int* ptr_multiple_of_two = ugly_number;
	int* ptr_multiple_of_three = ugly_number;
	int* ptr_multiple_of_five = ugly_number;
	

	int multiple_of_two = 1;
	int multiple_of_three = 1;
	int multiple_of_five = 1;

	ugly_number[0] = 1;

	for (int i = 1; i <= n; ++i) {
		multiple_of_two  = *ptr_multiple_of_two * 2;
		multiple_of_three = *ptr_multiple_of_three * 3;
		multiple_of_five = *ptr_multiple_of_five * 5;
		
		int min = multiple_of_two;
		
		if (multiple_of_two > multiple_of_three) {
			min = multiple_of_three;
		}
		
		if (min > multiple_of_five) {
			min = multiple_of_five;
		}

		if (multiple_of_two == min) {
			++ptr_multiple_of_two;
		} 
		if (multiple_of_three == min) {
			++ptr_multiple_of_three;
		}
		if (multiple_of_five == min) {
			++ptr_multiple_of_five;
		}

		ugly_number[i] = min;
	}

	cout << ugly_number[n - 1];

	
	return 0;
}
