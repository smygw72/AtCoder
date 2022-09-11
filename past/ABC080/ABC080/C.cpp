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

char bit(int _n) {
	if (_n == 0) return '0';
	else return '1';
}

string ten2two(int ten_num) {
	string two_num = "0000000000";
	for (int i = 0; i < 10; ++i) {
		if (i < 9) {
			two_num[i] = bit(ten_num % 2);
			ten_num /= 2;
		}
		else {
			two_num[9] = bit(ten_num);
		}
	}
	return two_num;
}

int main() {
	int N;
	cin >> N;
	bool F[100][10];
	REP(i, N) {
		REP(j, 10) cin >> F[i][j];
	}
	ll P[100][11];
	REP(i, N) {
		REP(j, 11) cin >> P[i][j];
	}

	// ëSíTçı
	ll ans = -mod;
	REPS(i, 1, pow(2, 10)) {
		string s = ten2two(i);

		ll prof = 0;
		REP(j, N) {
			int count = 0;
			REP(k, 10) {
				if (F[j][k] == true && s[k] == '1') count++;
			}
			prof += P[j][count];
		}
		ans = max(ans, prof);
	}
	cout << ans;
	system("pause");
	return 0;
}