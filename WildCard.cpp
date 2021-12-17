#include <iostream>

using namespace std;

int cache[101][101];

string W, S;

bool matchMemoized(int w, int s)
{
	int& ret = cache[w][s];
	if (ret != -1) {
		if (ret == 1) {
			return true;
		}
		else {
			return false;
		}
	}

	if (s < S.size() && w < W.size() &&
		(W[w] == '?' || W[w] == S[s])) {

		if (matchMemoized(w + 1, s + 1)) {
			ret = 1;
			return true;
		}
		else {
			ret = 0;
			return false;
		}
	}

	if (w == W.size() && s == S.size()) {
		ret = 1;
		return true;
	}

	if (W[w] == '*') {
		if (matchMemoized(w + 1, s) || (s < S.size() && matchMemoized(w, s + 1))) {
			ret = 1;
			return true;
		}
	}

	ret = 0;
	return false;
}

//Exhaustive Search
//bool match(const string& w, const string& s) {
//	int pos = 0;
//	while (pos < s.size() && pos < w.size() &&
//		(w[pos] == '?' || w[pos] == s[pos])) {
//
//		++pos;
//	}
//
//	if (pos == w.size()) {
//		return pos == s.size();
//	}
//
//	if (w[pos] == '*') {
//		for (int skip = 0; pos + skip <= s.size(); ++skip) {
//			if (match(w.substr(pos + 1), s.substr(pos + skip))) {
//				return true;
//			}
//		}
//	}
//
//	return false;
//}
//

int main(void)
{
	int n;
	cin >> n;


	for (int i = 0; i < n; ++i) {
		cin >> W;

		int k;
		cin >> k;

		for (int j = 0; j < k;++j) {
			memset(cache, -1, sizeof(cache));
			cin >> S;
			if (matchMemoized(0, 0)) {
				cout << S << endl;
			}
		}

	}
	return 0;
}
