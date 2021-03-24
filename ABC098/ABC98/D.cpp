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

int right_ix[200000];
int bin[200000][20];
int num[200000];

void num2bin(const int _num, int _binary[20]) {
	int dammy = _num;
	REP(i, 20) {
		_binary[i] = dammy % 2;
		dammy /= 2;
	}
}

bool update_sum(ll &_sum, const int _num) {
	int sum_bin[20], num_bin[20];
	num2bin(_sum, sum_bin);
	num2bin(_num, num_bin);
	REP(i, 20) {
		if (sum_bin[i] == 1 && num_bin[i] == 1) return false;
	}
	_sum += _num;
	return true;
}

int main() {
	int N;
	cin >> N;
	REP(i, N) {
		cin >> num[i];
	}

	ll ans = 0;
	ll sum = 0;

	// ‚µ‚á‚­Žæ‚è–@
	// Start
	REP(i, N) {

		if (i > 0) {
			sum -= num[i - 1];
			right_ix[i] = right_ix[i - 1];

			// End
			REPS(j, right_ix[i - 1] + 1, N) {
				if (update_sum(sum, num[j])) {
					right_ix[i] = j;
				}
				else {
					right_ix[i] = j - 1;
					break;
				}
			}
		}
		// i==0 ‚Ì‚Æ‚«
		else {
			REP(j, N) {
				if (update_sum(sum, num[j])) {
					right_ix[0] = j;
				}
				else {
					right_ix[0] = j - 1;
					break;
				}
			}
		}
		//cout << right_ix[i] << endl;
		ans += (right_ix[i] - i + 1);
	}
	cout << ans;
	system("pause");
	return 0;
}