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
	vector<ll> X(N),X_sort(N);
	
	REP(i, N) {
		cin >> X[i];
		X_sort[i] = X[i];
	}
	sort(X_sort.begin(), X_sort.end());
	ll middle1 = X_sort[N / 2 - 1];
	ll middle2 = X_sort[N / 2];

	REP(i, N) {
		if (X[i] <= middle1) {
			cout << middle2 << endl;
		}
		else {
			cout << middle1 << endl;
		}
	}


	system("pause");
	return 0;
}