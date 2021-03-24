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

string cov2num(int _num) {
	string s = "+++";
	REP(i, 3) {
		if (_num % 2 == 0) {
			s[i] = '-';
		}
		_num /= 2;
	}
	return s;
}

int main() {
	string sn;
	cin >> sn;
	int num[4];
	REP(i, 4) {
		num[i] = sn[i] - '0';
	}
	string op;
	REP(i, 8) {
		op = cov2num(i);
		int ans = num[0];
		REP(i, 3) {
			if (op[i] == '+') {
				ans += num[i + 1];
			}
			else ans -= num[i + 1];
		}
		if (ans == 7) {
			cout << num[0];
			REP(i, 3) cout << op[i] << num[i + 1];
			cout << "=7";
			break;
		}
	}
	system("pause");
	return 0;
}