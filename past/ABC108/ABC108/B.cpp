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
	int x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	int xt = abs(x1 - x2);
	int yt = abs(y1 - y2);

	if (x2 >= x1) {
		if (y2 >= y1) {
			cout << x2 - yt << " " << y2 + xt << " " << x1 - yt << " " << y1 + xt;
		}
		else {
			cout << x2 + yt << " " << y2 + xt << " " << x1 + yt << " " << y1 + xt;
		}
	}
	else {
		if (y2 >= y1) {
			cout << x2 - yt << " " << y2 - xt << " " << x1 - yt << " " << y1 - xt;
		}
		else {
			cout << x2 + yt << " " << y2 - xt << " " << x1 + yt << " " << y1 - xt;
		}
	}


	system("pause");
	return 0;
}