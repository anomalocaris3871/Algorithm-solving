#include <iostream>

using namespace std;

int numbers[10];
int operators[4];
int maxValue = INT_MIN;
int minValue = INT_MAX;
int n;

void dfs(int level, int result) {
    if (level == n) {
        if (result > maxValue) {
            maxValue = result;
        }

        if (result < minValue) {
            minValue = result;
        }
        return;
    }

    if (operators[0] > 0) {
        operators[0]--;
        dfs(level + 1, result + numbers[level]);
        operators[0]++;
    }

    if (operators[1] > 0) {
        operators[1]--;
        dfs(level + 1, result - numbers[level]);
        operators[1]++;
    }

    if (operators[2] > 0) {
        operators[2]--;
        dfs(level + 1, result * numbers[level]);
        operators[2]++;
    }

    if (operators[3] > 0) {
        operators[3]--;
        dfs(level + 1, result / numbers[level]);
        operators[3]++;
    }
}

int main(void) {

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    for (int i = 0; i < 4; ++i) {
        cin >> operators[i];
    }

    dfs(1, numbers[0]);

    cout << maxValue << endl;
    cout << minValue << endl;
    return 0;
}