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

int main() {
	int N;
	cin >> N;
	vector<ll> A(N),sum_l2r(N), sum_r2l(N);

	// 累積和を計算
	sum_l2r[0] = 0, sum_r2l[0] = 0;
	REP(i, N) {
		cin >> A[i];
		if (i > 0) {
			sum_l2r[i] += (sum_l2r[i - 1] + A[i]);
		}
		else sum_l2r[0] = A[0];
	}
	REP(i, N) {
		if (i > 0) {
			sum_r2l[i] += (sum_r2l[i - 1] + A[N - 1 - i]);
		}
		else sum_r2l[0] = A[N - 1];
	}

	// 真ん中の仕切りがi番目にあるときの最適な仕切り方
	// 0番目とN-1番目は定義されない
	vector<int> left_ix(N - 1), right_ix(N - 1);

	// 真ん中の仕切りの位置をずらしたときの左右の仕切りの最適な位置を求める
	// しゃく取り法
	// mid:[1]から[N-3]まで
	REPS(mid_ix, 1, N - 2) 
	{
		if (mid_ix > 1) {

			// 数列Lについて
			left_ix[mid_ix] = left_ix[mid_ix - 1]; // 引継ぎ

			ll left_diff = abs(sum_l2r[mid_ix] - 2 * sum_l2r[left_ix[mid_ix - 1]]);
			REPS(ix, left_ix[mid_ix - 1] + 1, mid_ix) {
				if (left_diff > abs(sum_l2r[mid_ix] - 2*sum_l2r[ix])) {
					left_ix[mid_ix] = ix;
					left_diff = abs(sum_l2r[mid_ix] - 2 * sum_l2r[ix]);
				}
				else break; // これがないとTLE!!
			}

			// 数列Rについて
			right_ix[mid_ix] = right_ix[mid_ix - 1]; // 引継ぎ

			ll right_diff = abs(sum_r2l[mid_ix] - 2 * sum_r2l[right_ix[mid_ix - 1]]);
			REPS(ix, right_ix[mid_ix - 1] + 1, mid_ix) {
				if (right_diff > abs(sum_r2l[mid_ix] - 2 * sum_r2l[ix])) {
					right_ix[mid_ix] = ix;
					right_diff = abs(sum_r2l[mid_ix] - 2 * sum_r2l[ix]);
				}
				else break; // これがないとTLE!!
			}

		}
		else {
			// mid_ix = 1のときは強制的に決まる
			left_ix[1] = 0;
			right_ix[1] = 0;
		}
	}

	ll ans = mod;
	REPS(mid_ix, 1, N - 2)
	{
		ll left_min = min(sum_l2r[mid_ix] - sum_l2r[left_ix[mid_ix]], sum_l2r[left_ix[mid_ix]]);
		ll left_max = max(sum_l2r[mid_ix] - sum_l2r[left_ix[mid_ix]], sum_l2r[left_ix[mid_ix]]);
		
		ll right_min = min(sum_r2l[N - 2 - mid_ix] - sum_r2l[right_ix[N - 2 - mid_ix]], sum_r2l[right_ix[N - 2 - mid_ix]]);
		ll right_max = max(sum_r2l[N - 2 - mid_ix] - sum_r2l[right_ix[N - 2 - mid_ix]], sum_r2l[right_ix[N - 2 - mid_ix]]);

		//cout << min_L << " " << max_L << " " << min_R << " " << max_R << endl;
		ans = min(max(left_max, right_max) - min(left_min, right_min), ans);
	}
	cout << ans << endl;
	system("pause");
	return 0;
}