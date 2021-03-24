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

int sum(int _num) {
	int sum = 0;
	while (1) {
		sum += _num % 10;
		_num /= 10;
		if (_num == 0) break;
	}
	return sum;
}

int main() {
	int N;
	int A, B;
	cin >> N >> A >> B;

	ll ans = 0;
	REPS(i, 1, N + 1){
		int buf = sum(i);
		if (buf >= A && buf <= B) {
			ans += i;
		}
	}
	cout << ans;
	system("pause");
	return 0;
}