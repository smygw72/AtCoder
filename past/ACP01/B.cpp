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

const int MAX = 10000;

int main() {
	int N;
	cin >> N;
	int a[MAX], b[MAX];
	int numPlusBi=0, numMinusAi=0;

	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> b[i];
	}

	for (int i = 0; i < N; ++i) {
		if (a[i] - b[i] > 0) {
			numPlusBi += (a[i] - b[i]);
		}
		else if (b[i] - a[i] >1) {
			numMinusAi += (b[i] - a[i])/2;
		}
	}

	if (numMinusAi >= numPlusBi) cout << "Yes";
	else cout << "No";

	system("pause");
	return 0;
}