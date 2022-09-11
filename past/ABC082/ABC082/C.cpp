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

vector<ll> av;

int main() {
	int N;
	cin >> N;
	REP(i, N) {
		ll num;
		cin >> num;
		av.push_back(num);
	}
	sort(av.begin(), av.end());

	ll ans = 0;
	ll targetNum = av[0];
	ll count = 1;

	if (av.size() == 1 && av[0] != 1) ans = 1;
	REPS(i, 1, av.size()) {
		if (targetNum == av[i]) {
			count++;
		}
		else {
			if (count < targetNum) ans += count;
			else ans += count - targetNum;
			targetNum = av[i];
			count = 1;
		}
		if (i == av.size() - 1) {
			if (count < targetNum) ans += count;
			else ans += count - targetNum;
		}
	}
	cout << ans;
	system("pause");
	return 0;
}