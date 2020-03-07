#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int cnt = 0;
    string str;
    cin >> str;

    for(int i=0;i<str.size();++i) {
        if(str[i] == 'c') {
            if(str[i+1] == '=' || str[i+1] == '-')
                i+=1;
        }
        else if(str[i] == 'd') {
            if(str[i+1] == 'z' && str[i+2] == '=')
                i+=2;
            else if(str[i+1] == '-')
                i+=1;
        }
        else if(str[i] == 'l') {
            if(str[i+1] == 'j') {
                i+=1;
            }
        }
        else if(str[i] == 'n') {
            if(str[i+1] == 'j') {
                i+=1;
            }
        }
        else if(str[i] == 's') {
            if(str[i+1] == '=') {
                i+=1;
            }
        }
        else if(str[i] == 'z') {
            if(str[i+1] == '=') {
                i+=1;
            }
        }
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
