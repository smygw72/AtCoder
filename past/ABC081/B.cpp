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

	int ans = mod;
	REP(i, N) {
		int num;
		cin >> num;
		int div_num = 0;
		while (1) {
			if (num % 2 == 0) {
				num /= 2;
				div_num++;
			}
			else break;
		}
		ans = min(ans, div_num);
	}
	cout << ans;
	system("pause");
	return 0;
}