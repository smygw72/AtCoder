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
	vector<int> nv;
	int N, K;
	cin >> N >> K;
	REP(i, N) {
		int num;
		cin >> num;
		nv.push_back(num);
	}
	sort(nv.begin(), nv.end());

	vector<int> kv;
	kv.push_back(1);
	REPS(i, 1, nv.size()) {
		if (nv[i] != nv[i - 1]) {
			kv.push_back(1);
		}
		else {
			kv.back()++;
		}
	}
	sort(kv.begin(), kv.end());
	reverse(kv.begin(), kv.end());

	int ans = 0;
	if (kv.size() > K) {
		REPS(i, K, kv.size()) {
			ans += kv[i];
		}
	}
	cout << ans;
	system("pause");
	return 0;
}