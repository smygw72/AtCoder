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

int l[100010], r[100010];
int sum[100010];

std::vector<int> eratosthenes_sieve(int n) {
	std::vector<int> ps(n + 1);
	std::iota(ps.begin() + 2, ps.end(), 2);
	for (int i = 2; i * i <= n; ++i)
		if (ps[i])
			for (int j = i * i; j <= n; j += i) ps[j] = 0;
	return ps;
}

int main() {
	int Q;
	cin >> Q;
	REP(i, Q) {
		cin >> l[i] >> r[i];
	}

	// ëfêîÉäÉXÉg
	vector<int> primes = eratosthenes_sieve(100000);
	//REP(i, 100) cout << primes[i] << endl;

	sum[1] = 0;
	for (int i = 3; i < 100001; i += 2) {
		sum[i] = sum[i - 2];

		// 2017-likeÇÃîªíË
		if (primes[i] != 0 && primes[(i + 1) / 2] != 0) {
			sum[i]++;
		}
	}

	REP(i, Q) {
		cout << sum[r[i]] - sum[l[i] - 2] << endl;
	}

	system("pause");
	return 0;
}