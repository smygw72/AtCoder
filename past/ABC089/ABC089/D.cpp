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

ll ans[100010];
map<int, pair<int, int>> mp;

int main() {
	cin.tie(0);
	int H, W, D;
	cin >> H >> W >> D;

	REP(i, H) {
		REP(j, W) {
			int num;
			cin >> num;
			mp[num] = pair<int, int>(i, j);
		}
	}

	ll sum[90001];
	vector<pair<int, int>> pos_prev(D);
	REPS(i, 1, H*W + 1) {
		pair<int, int> pos = mp[i];

		if (i <= D) {
			sum[i] = 0;
			pos_prev[i%D] = pos;
		}
		else {
			sum[i] = sum[i-D] + abs(pos.first - pos_prev[i%D].first) + abs(pos.second - pos_prev[i%D].second);
			pos_prev[i%D] = pos;
		}
	}

	int Q;
	cin >> Q;

	REP(i, Q) {
		int li, ri;
		cin >> li >> ri;
		ans[i] = sum[ri] - sum[li];
	}
	REP(i, Q) {
		cout << ans[i] << endl;
	}
	system("pause");
	return 0;
}