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

ll dp[100010][4];

int main() {
	string s;
	cin >> s;

	// èâä˙èÛë‘
	REP(i, 4) dp[0][i] = 0;
	dp[0][0] = 1;

	REP(i, s.size()) 
	{
		// èÛë‘ïœâªÇ»Çµ
		if (s[i] != '?') {
			REP(j, 4) dp[i + 1][j] = dp[i][j];
		}
		else {
			REP(j, 4) dp[i + 1][j] = 3*dp[i][j];
		}

		// èÛë‘ïœâªÇ†ÇË
		if (s[i] == 'A' || s[i] == '?') {
			dp[i + 1][1] += dp[i][0];
		}
		if (s[i] == 'B' || s[i] == '?') {
			dp[i + 1][2] += dp[i][1];
		}
		if (s[i] == 'C' || s[i] == '?') {
			dp[i + 1][3] += dp[i][2];
		}

		REP(j, 4) dp[i + 1][j] %= mod;
	}
	cout << dp[s.size()][3];
	system("pause");
	return 0;
}