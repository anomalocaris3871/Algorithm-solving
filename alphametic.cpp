#include <iostream>

using namespace std;

int alphabet[10];
bool number[10];

int send() {
    return alphabet[6] * 1000 + alphabet[1] * 100 + alphabet[3] * 10 + alphabet[0];
}

int more() {
    return alphabet[2] * 1000 + alphabet[4] * 100 + alphabet[5] * 10 + alphabet[1];
}

int money() {
    return alphabet[2] * 10000 + alphabet[4] * 1000 + alphabet[3] * 100 + alphabet[1] * 10 + alphabet[7];
}

void dfs(int n) {
    if (n == 8) {
        if (send() + more() == money()) {
            if (alphabet[6] == 0 || alphabet[2] == 0) {
                return;
            }
            cout << " " << alphabet[6] << alphabet[1] << alphabet[3] << alphabet[0] << endl;
            cout << "+" << alphabet[2] << alphabet[4] << alphabet[5] << alphabet[1] << endl;
            cout << "=====" << endl;
            cout << alphabet[2] << alphabet[4] << alphabet[3] << alphabet[1] << alphabet[7] << endl;
        }
    } else {
        for (int i = 0; i < 10; ++i) {
            if (number[i]) {
                continue;
            }
            alphabet[n] = i;
            number[i] = true;
            dfs(n + 1);
            number[i] = false;
        }
    }
}

int main(void) {

    dfs(0);
    return 0;
}