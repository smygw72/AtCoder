#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORR(i, a, b) for (int i = b - 1; i >= a; --i)
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) FORR(i, 0, n)

const int inf = 999999999;
const int mod = 1e9 + 7;
const long double pi = 3.141592653589793238462643383279502884197;
const long double eps = 1e-7;

int main() {
	cin.tie(0);
	static int even[100010],odd[100010];
	REP(i, 100010) {
		even[i] = 0;
		odd[i] = 0;
	}

	int even_max_count = 0, odd_max_count = 0;
	int even_max_ix, odd_max_ix;
	int ans;

	int n;
	cin >> n;

	REP(i, n) {
		int vi;
		cin >> vi;
		if (i % 2 == 0) {
			even[vi]++;
			if (even_max_count < even[vi]) {
				even_max_count = even[vi];
				even_max_ix = vi;
			}
		}
		else {
			odd[vi]++;
			if (odd_max_count < odd[vi]) {
				odd_max_count = odd[vi];
				odd_max_ix = vi;
			}
		}
	}

	sort(even, even + 100001);
	sort(odd, odd + 100001);
	reverse(even, even + 100001);
	reverse(odd, odd + 100001);

	if (even_max_ix != odd_max_ix) {
		ans = n - even_max_count - odd_max_count;
	}
	else {
		ans = n - max(even_max_count + odd[1], odd_max_count + even[1]);
	}
	cout << ans;
	system("pause");
	return 0;
}