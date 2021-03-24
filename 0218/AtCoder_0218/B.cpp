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
#include <functional>

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
	vector<int> a;
	int alice = 0, bob = 0;
	
	REP(i, N) {
		int ai;
		cin >> ai;
		a.push_back(ai);
	}
	std::sort(a.begin(), a.end(), std::greater<int>());//ç~èáÉ\Å[Ég

	REP(i, a.size()) {
		if (i % 2 == 0) {
			alice += a[i];
		}
		else {
			bob += a[i];
		}
	}

	cout << alice - bob;

	system("pause");
	return 0;
}