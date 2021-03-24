
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

// カロリーと位置
ll x[100010], v[100010];

// 初期位置からi番目の寿司を食べるまでに得るカロリー
ll cal_cw[100010]; // 時計回り(clockwise)
ll cal_ccw[100010]; // 反時計回り(counter-clockwise)

// Bの位置を固定したときの最適なAの位置
ll a_ix_oboa[100010],a_ix_oaob[100010];

// 答え
ll ans = 0;

int main() {
	ll N, C;
	cin >> N >> C;

	REP(i, N) {
		cin >> x[i] >> v[i];
	}

	// 時計回り
	REP(i, N) {
		if (i > 0) {
			cal_cw[i] = cal_cw[i - 1] + v[i] - (x[i] - x[i - 1]);
		}
		else {
			cal_cw[0] = v[0] - x[0];
		}
		ans = max(ans, cal_cw[i]);
	}

	// 反時計回り
	for (int i = N - 1; i >= 0; --i) {
		if (i < (N - 1)) {
			cal_ccw[i] = cal_ccw[i + 1] + v[i] - (x[i + 1] - x[i]);
		}
		else {
			cal_ccw[N - 1] = v[N - 1] - (C - x[N - 1]);
		}
		ans = max(ans, cal_ccw[i]);
	}

	//---- Bの位置(b_ix)を固定したときの最適なA:[O,b_ix)の位置(a_ix_best)を求める

	// b_ix = 1のときは強制的に決まる。b_ix = 0のときは定義されない。
	a_ix_oboa[1] = 0;
	a_ix_oaob[1] = 0;

	REPS(b_ix, 2, N) 
	{
		// oboa
		if (cal_cw[b_ix - 1] > cal_cw[a_ix_oboa[b_ix - 1]]) {
			a_ix_oboa[b_ix] = b_ix - 1; // 更新
		}
		else {
			a_ix_oboa[b_ix] = a_ix_oboa[b_ix - 1]; // 引継ぎ
		}
		//cout << a_ix_best[b_ix] << " ";

		// oaob
		if (cal_cw[b_ix - 1] - x[b_ix - 1] > cal_cw[a_ix_oaob[b_ix - 1]] - x[a_ix_oaob[b_ix - 1]]) {
			a_ix_oaob[b_ix] = b_ix - 1; // 更新
		}
		else {
			a_ix_oaob[b_ix] = a_ix_oaob[b_ix - 1]; // 引継ぎ
		}
		//cout << a_ix_best[b_ix] << " ";

	}
	//cout << endl;


	REPS(b_ix, 1, N) {
		ll ans_oaob = 0, ans_oboa = 0;

		//cout << "b_ix: " << b_ix << endl;

		// oboa
		ans_oboa += cal_ccw[b_ix];
		ans_oboa -= (C - x[b_ix]);
		ans_oboa += cal_cw[a_ix_oboa[b_ix]];
		//cout << ans_oboa<<endl;

		// oaob
		ans_oaob += cal_cw[a_ix_oaob[b_ix]];
		ans_oaob -= x[a_ix_oaob[b_ix]];
		ans_oaob += cal_ccw[b_ix]; // O→B
		//cout << ans_oaob << endl;

		ans = max(ans, max(ans_oboa, ans_oaob));
		//cout << ans << endl;
	}
	cout << max((ll)0, ans);
	system("pause");
	return 0;
}