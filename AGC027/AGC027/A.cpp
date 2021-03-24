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
	ll N, x;
	vector<ll> a;
	cin >> N >> x;
	REP(i, N) {
		ll num;
		cin >> num;
		a.push_back(num);
	}
	sort(a.begin(), a.end());

	ll count = x;
	int ix = 0;
	while (ix+1 <= N) {
		count -= a[ix];
		if (count == 0) {
			ix++;
			break;
		}
		if (count < 0) {
			break;
		}
		if (count > 0 && (ix + 1) == N) {
			break;
		}
		ix++;
	}
	cout << ix;
	system("pause");
	return 0;
}