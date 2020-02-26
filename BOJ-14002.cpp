#include<bits/stdc++.h>

using namespace std;

int dp[1001];
int a[1001];
int b[1001];

void go(int p) {
    if(p == 0)
        return;
    go(b[p]);
    cout << a[p] << ' ';

}
int main(void)
{
    int n;
    cin >> n;
    for(int i=1;i<=n;++i) {
        cin >> a[i];
    }

    for(int i=1;i<=n;++i) {
        dp[i] = 1;
        b[i] = 0;
        for(int j=1;j<=i;++j) {
            if(a[i] > a[j] && dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
                b[i] = j;
            }
        }
    }

    int ans = 0;
    int p = 0;
    for(int i=1;i<=n; ++i) {
        if(dp[i] > ans) {
            ans = dp[i];
            p = i;
        }
    }

    cout << ans << '\n';
    go(p);
    cout << '\n';

    return 0;
}
