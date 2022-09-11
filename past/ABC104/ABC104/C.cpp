#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<map>
#include<tuple>
#include<algorithm>
#include<numeric>
#include<math.h>

#define REPS(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int mod = 1e9 + 7;
const long double pi = 3.141592653589793238462643383279502884197;
const long double eps = 1e-7;

int D, G;

string conv(int _num) {
	string s = "0000000000";
	REP(i, D) {
		if (_num % 2 == 1) {
			s[i] = '1';
		}
		_num /= 2;
	}
	return s;
}

int main() {
	cin >> D >> G;
	int p[10], c[10];
	REP(i, D) {
		cin >> p[i] >> c[i];
	}

	int sum[10];
	REP(i, D) {
		sum[i] = (i + 1) * 100 * p[i] + c[i];
	}

	int ans = mod;
	REP(num, pow(2, D)) {
		string bits = conv(num);

		int total = 0, prob_num = 0;
		int zero_max_ix = -1;

		REP(ix, D) {
			// ‘S•”‰ð‚­
			if (bits[ix] == '1') {
				total += sum[ix];
				prob_num += p[ix];
			}
			// ‘S•”‰ð‚©‚È‚¢
			if (bits[ix] == '0') zero_max_ix = ix;
		}
		// ’†“r”¼’[‚É‰ð‚­
		if (total < G && zero_max_ix != -1) {
			int rest = G - total;
			int prob_num_ix;
			if (rest % ((zero_max_ix + 1) * 100) == 0) {
				prob_num_ix = rest / ((zero_max_ix + 1) * 100);
			}
			else {
				prob_num_ix = rest / ((zero_max_ix + 1) * 100) + 1;
			}

			if (prob_num_ix < p[zero_max_ix]) {
				total += prob_num_ix * 100*(zero_max_ix+1);
				prob_num += prob_num_ix;
			}
		}
		if (total >= G) {
			ans = min(ans, prob_num);
		}
	}
	cout << ans;
	system("pause");
	return 0;
}