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
	int N, M;
	cin >> N >> M;
	ll ans = 0;
	// 1回あたりの実行時間
	int t = 100 * (N - M) + M * 1900;
	// Mケースすべて正解する確率
	double p = 1.0/pow(2, M); // >= 1/2^5

	// 数学的な解はt/p
	cout << t / p;

	system("pause");
	return 0;
}