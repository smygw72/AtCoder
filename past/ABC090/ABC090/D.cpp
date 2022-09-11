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
	cin.tie(0);
	ll N, K;
	cin >> N >> K;
	ll ans = 0;

	if (K == 0) ans = N*N;
	else {
		REPS(b, K+1, N + 1) {
			ll p = N / b;
			ll r = N%b;

			ans += p*max(b - K, 0LL);
			ans += max(r - K + 1, 0LL);
		}
	}
	cout << ans;
	system("pause");
	return 0;
}