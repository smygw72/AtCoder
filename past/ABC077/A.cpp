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
	char c[2][3];
	REP(i, 2) REP(j, 3) cin >> c[i][j];
	
	bool ans = true;
	
	if (c[0][0] != c[1][2]) ans = false;
	else if (c[0][1] != c[1][1]) ans = false;
	else if (c[0][2] != c[1][0]) ans = false;

	if (ans) cout << "YES";
	else cout << "NO";

	system("pause");
	return 0;
}