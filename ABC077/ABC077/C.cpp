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

vector<ll> s[3];

// b‚ðŒÅ’è‚µ‚½‚Æ‚«‚Éa,c‚ÅðŒ‚ð–ž‚½‚·index‚ÌƒŠƒXƒg
ll a_ix_end[100010], c_ix_start[100010];

int main() {
	cin.tie(0);
	int N;
	cin >> N;
	REP(i, 3) {
		REP(j, N) {
			int num;
			cin >> num;
			s[i].push_back(num);
		}
	}
	REP(i, 3) {
		sort(s[i].begin(),s[i].end());
	}


	ll ix = 0;
	REP(b_ix, N) {
		while (1) {
			if (ix == N) {
				a_ix_end[b_ix] = N;
				break;
			}
			if (s[1][b_ix] <= s[0][ix]) {
				a_ix_end[b_ix] = ix;
				break;
			}
			else ix++;
		}
//		cout << a_ix_end[b_ix] << " ";
	}
//	cout << endl;

	ix = 0;
	REP(b_ix, N) {
		while (1) {
			if (ix == N) {
				c_ix_start[b_ix] = N;
				break;
			}
			if (s[1][b_ix] < s[2][ix]) {
				c_ix_start[b_ix] = ix;
				break;
			}
			else ix++;
		}
//		cout << c_ix_start[b_ix] << " ";
	}
//	cout << endl;

	ll ans = 0;
	REP(b_ix, N) {
		ans += a_ix_end[b_ix] * (N - c_ix_start[b_ix]);
	}
	cout << ans;
	system("pause");
	return 0;
}