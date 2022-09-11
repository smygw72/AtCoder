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
	int N, K;
	cin >> N >> K;

	ll ans = 0;
	ll num1, num2;
	num1 = N / K;

	// K����̏ꍇ
	if (K % 2 == 1) {		
		ans = pow(num1, 3);
	}
	// K�������̏ꍇ
	else {
		num2 = (N + K / 2) / K;
		ans = pow(num1, 3) + pow(num2, 3);
	}
	cout << ans;
	system("pause");
	return 0;
}