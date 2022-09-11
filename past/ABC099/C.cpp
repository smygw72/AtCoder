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

int memo[100001];

int loopDP(int _num) {
	if (_num == 0) return 0;
	if (memo[_num] != -1) return memo[_num];

	int res = _num;

	// ‘S‚Ä‚Ìè–@‚Ì’†‚©‚çÅ‚à‚¢‚¢‚â‚Â‚ğ‘I‚ñ‚Å‚­‚é
	for (int i = 1; i <= _num; i *= 6) {
		res = min(loopDP(_num - i) + 1, res);
	}
	for (int i = 1; i <= _num; i *= 9) {
		res = min(loopDP(_num - i) + 1, res);
	}
	return memo[_num] = res;
}

int main() {
	int N;
	cin >> N;
	REP(i, 100001) {
		memo[i] = -1;
	}
	cout << loopDP(N);
	system("pause");
}