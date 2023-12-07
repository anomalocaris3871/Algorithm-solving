#include <iostream>

using namespace std;

int times[16];
int prices[16];

int maxPrice = INT_MIN;

void dfs(int n, int limit, int sum) {
    if (n == limit + 1) {
        if (maxPrice < sum) {
            maxPrice = sum;
        }
    } else {

        if (n + times[n] <= limit + 1) {
            dfs(n + times[n], limit, sum + prices[n]);
        }
        dfs(n + 1, limit, sum);
    }

}


int main() {

    int n;

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> times[i];
        cin >> prices[i];
    }

    dfs(1, n, 0);


    cout << maxPrice << endl;

    return 0;
}