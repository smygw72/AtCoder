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

ll num[87];

int main() {
	int N;
	cin >> N;
	REP(i, N + 1) num[i] = 0;
	num[0] = 2;
	num[1] = 1;

	REPS(i, 2, N + 1) {
		num[i] = num[i - 1] + num[i - 2];
	}
	cout << num[N];

	system("pause");
	return 0;
}