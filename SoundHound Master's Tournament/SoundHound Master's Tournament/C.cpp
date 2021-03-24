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
#include <iomanip>

#define REPS(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const long double pi = 3.141592653589793238462643383279502884197;
const long double eps = 1e-7;

int main() {
	ll n, m, d;
	cin >> n >> m >> d;
	double ans = 0;
	if (d == 0) {
		ans = (double)(m - 1) / n;
	}
	else {
		ans = 2.0 * (m - 1)*(n - d) / (n*n);
	}
	cout << fixed;
	cout << setprecision(7) << ans;
	system("pause");
	return 0;
}