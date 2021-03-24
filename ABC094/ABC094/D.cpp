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
#include <utility>


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
	int n;
	cin >> n;
	static vector<ll> a(n);

	REP(i, n) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	double mid_num = a[n - 1] / 2.0;
	int diff = mod;
	REP(i, n) {
		int new_diff = abs((int)(mid_num - a[i]));
		if (diff > new_diff) {
			diff = new_diff;
		}
		else {
			cout << a[n - 1] << " " << a[i - 1];
			break;
		}
	}

	system("pause");
	return 0;
}