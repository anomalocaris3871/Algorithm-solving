#include <stdio.h>

int hash[53] = { 0, };

int main(void)
{
	char str[101];
	scanf("%s", str);

	for (char* ptr = str; *ptr != '\0'; ++ptr) {
		if (*ptr >= 65 && *ptr <= 90) {
			hash[*ptr - 64]++;
		}
		else {
			hash[*ptr - 70]++;
		}
	}

	scanf("%s", str);

	for (char* ptr = str; *ptr != '\0'; ++ptr) {
		if (*ptr >= 65 && *ptr <= 90) {
			hash[*ptr - 64]--;
		}
		else {
			hash[*ptr - 70]--;
		}
	}

	int i;
	for (i = 1; i < 53; ++i) {
		if (hash[i] != 0) {
			break;
		}
	}

	if (i < 53) {
		printf("NO\n");
	}
	else {
		printf("YES\n");
	}

	return 0;
}
