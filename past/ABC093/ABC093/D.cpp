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
	int Q;
	cin >> Q;
	vector<ll> A(Q), B(Q);

	REP(i, Q) {
		cin >> A[i] >> B[i];
	}
	REP(i,Q){
		ll a = A[i], b = B[i];
		if (a > b) swap(a, b);

		if ((b - a) <= 1) {
			cout << 2 * (a - 1) << endl;
		}
		else {
			ll c = sqrt(a*b);
			if (c*(c + 1) < a*b) {
				cout << (a - 1) + 2 * c - a << endl;
			}
			else if(c*c < a*b) {
				cout << (a - 1) + 2 * c - a - 1 << endl;
			}
			else if (c*c == a*b) {
				cout << (a - 1) + 2 * c - a - 1 - 1 << endl;
			}
		}
	}
	system("pause");
	return 0;
}