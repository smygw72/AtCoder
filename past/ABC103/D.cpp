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

vector<pair<int, int>> pvec;

inline bool isOverlap(pair<int,int>& _ix1, const pair<int,int> _ix2) {
	if (_ix1.second < _ix2.first) {
		_ix1 = _ix2;
		return false;
	}
	else {
		_ix1.first = _ix2.first;
		if (_ix1.second > _ix2.second) {
			_ix1.second = _ix2.second;
		}
	}
	return true;
}

int main() {
	cin.tie(0);
	int N, M;
	cin >> N >> M;

	REP(i, M) {
		pair<int, int> p;
		cin >> p.first >> p.second;
		p.second -= 1;
		pvec.push_back(p);
	}

	sort(pvec.begin(), pvec.end());

	ll ans = 0;

	pair<int, int> overlap_ix = pvec[0];
	REPS(i, 1, M) {
		if (!isOverlap(overlap_ix, pvec[i])) {
			ans++;
		}
	}
	ans++;
	cout << ans;
	system("pause");
	return 0;
}