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

int A, B;

bool isKaibun(int _num) {
	int keta[5];
	REP(i, 5) {
		keta[i] = _num % 10;
		_num /= 10;
	}
	if (keta[0] != keta[4] || keta[1] != keta[3]) {
		return false;
	}
	int num_inv = 0;
	REP(i, 5) {
		num_inv += pow(10, 4 - i)*keta[i];
	}
	if (num_inv >= A && num_inv <= B) {
		return true;
	}
	return false;
}

int main() {
	cin >> A >> B;
	int count = 0;
	REPS(i, A, B + 1) {
		if (isKaibun(i)) {
			count++;
		}
	}
	cout << count;
	system("pause");
	return 0;
}