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
	int A, B, K;
	cin >> A >> B >> K;

	int last = 0;
	REP(i, K) {
		int num = A + i;
		if (num <= B) {
			cout << num << endl;
			last = num;
		}
		else {
			break;
		}
	}

	if ((B - K + 1) <= (A + K - 1)) {
		REPS(i, last + 1, B + 1) {
			cout << i << endl;
		}
	}
	else {
		REPS(i, B - K + 1, B + 1) {
			cout << i << endl;
		}
	}

	system("pause");
	return 0;
}