#include <bits/stdc++.h>

using namespace std;


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<char> left, right;
    string init;
    getline(cin,init);
    int cnt = 0;
    while(cnt < init.size()) {
        left.push(init[cnt]);
        cnt++;
    }
    int n;

    cin >> n;
    while(n--) {
        char commend;
        cin >> commend;
        if(commend == 'L'){
            if(!left.empty()) {
                right.push(left.top());
                left.pop();
            }
        } else if(commend == 'D') {
            if(!right.empty()) {
                left.push(right.top());
                right.pop();
            }
        } else if(commend == 'B') {
            if(!left.empty())
                left.pop();
        } else {
            char new_char;
            cin >> new_char;
            left.push(new_char);
        }
    }

    string ans = "";
    while(!left.empty()) {
        right.push(left.top());
        left.pop();
    }

    while(!right.empty()) {
        ans += right.top();
        right.pop();
    }

    cout << ans << '\n';
    return 0;
}
