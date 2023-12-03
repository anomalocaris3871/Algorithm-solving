#include <iostream>

using namespace std;

int numbers[16];
bool checks[16];
int result[16];


void dfs(int currentIndex, int n, int r) {

    if (currentIndex == n) {
        for (int i = 0; i < r; ++i) {
            cout << result[i] << " ";
        }
        cout << endl;
    } else {

        for (int i = 1; i <= n; ++i) {
            if (checks[i]) {
                continue;
            }
            checks[i] = true;
            result[currentIndex] = numbers[i];
            dfs(currentIndex + 1, n, r);
            checks[i] = false;
        }
    }
}

int main(void) {

    int n;
    int r;
    cin >> n >> r;
    for (int i = 1; i <= n; ++i) {
        cin >> numbers[i];
    }

    dfs(0, n, r);

    return 0;
}