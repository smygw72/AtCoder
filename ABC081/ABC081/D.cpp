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
	int N;
	cin >> N;
	int a[50];

	int max_num = 0, min_num = mod;
	int max_ix, min_ix;
	REP(i, N) {
		cin >> a[i];
		if (max_num < a[i]) {
			max_num = a[i];
			max_ix = i;
		}
		if (min_num > a[i]) {
			min_num = a[i];
			min_ix = i;
		}
	}
	bool sign_p = true;
	if (min_num < 0 && max_num > 0) {
		cout << 2*N - 1 << endl;

		if (max_num > abs(min_num)) {
			REP(i, N) {
				a[i] += max_num;
				cout << max_ix+1 << " " << i+1 << endl;
			}
		}
		else {
			REP(i, N) {
				a[i] += min_num;
				cout << min_ix+1 << " " << i+1 << endl;
			}
			sign_p = false;
		}
	}
	else {
		cout << N - 1 << endl;
		if (max_num <= 0) sign_p = false;
	}

	if (sign_p) {
		REP(i, N - 1) {
			cout << i+1 << " "<< i + 2 << endl;
		}
	}
	else {
		for (int i = N - 1; i > 0; --i) {
			cout << i+1 << " " << i << endl;
		}
	}
	system("pause");
	return 0;
}