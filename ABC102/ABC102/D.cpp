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

	// �ݐϘa���v�Z
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

	// �^�񒆂̎d�؂肪i�Ԗڂɂ���Ƃ��̍œK�Ȏd�؂��
	// 0�Ԗڂ�N-1�Ԗڂ͒�`����Ȃ�
	vector<int> left_ix(N - 1), right_ix(N - 1);

	// �^�񒆂̎d�؂�̈ʒu�����炵���Ƃ��̍��E�̎d�؂�̍œK�Ȉʒu�����߂�
	// ���Ⴍ���@
	// mid:[1]����[N-3]�܂�
	REPS(mid_ix, 1, N - 2) 
	{
		if (mid_ix > 1) {

			// ����L�ɂ���
			left_ix[mid_ix] = left_ix[mid_ix - 1]; // ���p��

			ll left_diff = abs(sum_l2r[mid_ix] - 2 * sum_l2r[left_ix[mid_ix - 1]]);
			REPS(ix, left_ix[mid_ix - 1] + 1, mid_ix) {
				if (left_diff > abs(sum_l2r[mid_ix] - 2*sum_l2r[ix])) {
					left_ix[mid_ix] = ix;
					left_diff = abs(sum_l2r[mid_ix] - 2 * sum_l2r[ix]);
				}
				else break; // ���ꂪ�Ȃ���TLE!!
			}

			// ����R�ɂ���
			right_ix[mid_ix] = right_ix[mid_ix - 1]; // ���p��

			ll right_diff = abs(sum_r2l[mid_ix] - 2 * sum_r2l[right_ix[mid_ix - 1]]);
			REPS(ix, right_ix[mid_ix - 1] + 1, mid_ix) {
				if (right_diff > abs(sum_r2l[mid_ix] - 2 * sum_r2l[ix])) {
					right_ix[mid_ix] = ix;
					right_diff = abs(sum_r2l[mid_ix] - 2 * sum_r2l[ix]);
				}
				else break; // ���ꂪ�Ȃ���TLE!!
			}

		}
		else {
			// mid_ix = 1�̂Ƃ��͋����I�Ɍ��܂�
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