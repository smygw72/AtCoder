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
	int N, X;
	cin >> N >> X;

	int m[10010];

	int m_min = mod;
	REP(i, N) {
		cin >> m[i];
		X -= m[i];
		m_min = min(m_min, m[i]);
	}
	int ans = N;
	ans += (X / m_min);
	cout << ans;
	system("pause");
	return 0;
}