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

	ll num[100];
	int max_num = 0, min_num = mod;
	REP(i, N) {
		int new_num;
		cin >> new_num;
		max_num = max(max_num, new_num);
		min_num = min(min_num, new_num);
	}
	cout << max_num - min_num;
	system("pause");
	return 0;
}