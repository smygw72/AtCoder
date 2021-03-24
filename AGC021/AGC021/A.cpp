#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
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
#include <typeinfo>

#define REPS(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int mod = 1e9 + 7;
const long double pi = 3.141592653589793238462643383279502884197;
const long double eps = 1e-7;

int ctoi(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 0;
}

int main() {

	string str;
	cin >> str;
	int keta = str.length();
	int result = 0;
	int memo = keta - 1;

	bool shouldChange = false;
	for (int i = keta - 1; i > 0; --i) {
		if (ctoi(str[i]) <= 7 && ctoi(str[i-1]) >0) {
			shouldChange = true;
			memo = i;
		}
	}
	if (shouldChange) {
		str[memo - 1]--;

		for (int i = memo; i < keta; ++i) {
			str[i] = '9';
		}
	}
	for (int i = 0; i < keta; ++i) {
		result += ctoi(str[i]);
	}
	cout << result;

	system("pause");
	return 0;
}