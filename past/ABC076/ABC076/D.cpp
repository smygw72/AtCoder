#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pdi = pair<double, int>;
using vi = vector<int>;

#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORR(i, a, b) for (int i = b - 1; i >= a; --i)
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) FORR(i, 0, n)

const int inf = 999999999;
const int mod = 1e9 + 7;
const long double pi = 3.141592653589793238462643383279502884197;
const long double eps = 1e-7;

double t[100], v[100];
double maxv[40010], curv[40010];

int main() {
	cin.tie(0);
	int N; cin >> N;

	int T = 0;
	REP(i, N) {
		cin >> t[i];
		T += t[i];
	}
	REP(i, N) {
		cin >> v[i];
	}
	t[0] -= 0.5;
	int ix = 0;
	REP(i, N) {
		REP(j, t[i]) {
				maxv[ix + 2 * j] = v[i];
				maxv[ix + 2 * j + 1] = v[i];
		}
		ix += 2 * t[i];
	}

	REP(i, 2 * T) {
		if (i == 0) {
			curv[0] = min(maxv[i], 0.5);
			continue;
		}
		curv[i] = min(maxv[i], curv[i - 1] + 0.5);
	}

	REPR(i, 2 * T) {
		if (i == (2 * T - 1)) {
			curv[2 * T - 1] = 0;
			continue;
		}
		curv[i] = min(curv[i], curv[i + 1] + 0.5);
	}

	//REP(i, 2*T) {
	//	cout << maxv[i] << " " << curv[i] << endl;
	//}

	double ans = 0;
	REP(i, 2*T) {
		if (i == 0) {
			ans += curv[i] * 0.5 / 2.0;
			continue;
		}
		ans += curv[i - 1] * 0.5;
		ans += (curv[i] - curv[i - 1]) * 0.5 / 2.0;
	}
	cout << ans;
	system("pause");
	return 0;
}