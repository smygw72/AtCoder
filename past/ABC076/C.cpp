#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORR(i, a, b) for (int i = b - 1; i >= a; --i)
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) FORR(i, 0, n)

const int inf = 999999999;
const int mod = 1e9 + 7;
const long double pi = 3.141592653589793238462643383279502884197;
const long double eps = 1e-7;

int main() {
	cin.tie(0);
	string Sd, T;
	cin >> Sd >> T;

	bool ans = false;
	int ix_start = 0;
	REP(i, Sd.size() - T.size() + 1) {
		string subs = Sd.substr(i, T.size());
		REP(j, T.size()) {
			if (Sd[i + j] != '?' && Sd[i + j] != T[j]) break;
			if (j == T.size() - 1) {
				ix_start = i;
				ans = true;
			}
		}
	}

	if (ans) {
		string S = Sd;
		REP(i, S.size()) {
			if (i == ix_start) {
				REP(j, T.size()) {
					S[i + j] = T[j];
				}
				i += T.size() - 1;
				continue;
			}
			if (S[i] == '?') {
				S[i] = 'a';
			}
		}
		cout << S;
	}
	else {
		cout << "UNRESTORABLE";
	}
	system("pause");
	return 0;
}