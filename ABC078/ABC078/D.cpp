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

ll a[2010];

int main() {
	cin.tie(0);
	int N, Z, W;
	cin >> N >> Z >> W;
	REP(i, N) cin >> a[i];
	ll op1 = abs(a[N - 1] - W);

	if (N >= 2) {
		ll op2 = abs(a[N - 2] - a[N - 1]);
		if (op1 <= op2) cout << op2;
		else cout << op1;
	}
	else {
		cout << op1;
	}
	system("pause");
	return 0;
}