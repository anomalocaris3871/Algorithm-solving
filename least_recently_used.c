#include<stdio.h>

int cache[1001];

int main(void)
{
	int buffer_size;
	int n;

	
	scanf("%d", &buffer_size);
	scanf("%d", &n);


	for (int i = 0; i < n; ++i) {
		int work;
		scanf("%d", &work);

		int length;
		if (i < buffer_size) {
			length = i - 1;
		}
		else {
			length = buffer_size;
		}

		int j;
		for (j = 0; j < length; ++j) {
			if (work == cache[j]) {
				break;
			}
		}

		for (int i = j - 1; i >= 0; --i) {
			cache[i + 1] = cache[i];
		}
		cache[0] = work;
	}

	for (int i = 0; i < buffer_size; ++i) {
		printf("%d ", cache[i]);
	}
	printf("\n");

	return 0;
}
