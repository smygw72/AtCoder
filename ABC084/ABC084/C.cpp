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

int C[500], S[500], F[500];

// _t•b‚É_ix‰w‚É‚¢‚é‚Æ‚«‚ÉŽŸ‚Ì‰w‚É’…‚­ŽžŠÔ‚ðreturn
int getNextTime(int _t, int _stat_ix) {
	if (_t < S[_stat_ix]) {
		return S[_stat_ix] + C[_stat_ix];
	}
	else {
		if (_t%F[_stat_ix] == 0) {
			return _t + C[_stat_ix];
		}
		else {
			return (_t / F[_stat_ix] + 1)*F[_stat_ix] + C[_stat_ix];
		}
	}
	return 0;
}

int main() {
	int N = 0;
	cin >> N;
	REP(i, N-1) {
		cin >> C[i] >> S[i] >> F[i];
	}

	REP(i, N) {
		int time = 0;
		REPS(j, i, N-1) {
			time = getNextTime(time, j);
		}
		cout << time << endl;
	}

	system("pause");
	return 0;
}