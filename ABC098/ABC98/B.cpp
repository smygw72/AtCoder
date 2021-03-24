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

int getIndex(char _c) {
	return _c - 'a';
}

int main() {
	string s;
	int N;
	cin >> N;
	cin >> s;

	int right[26], left[26];
	// èâä˙âª
	for (int i = 0; i < 26; ++i) {
		right[i] = 0;
		left[i] = 0;
	}
	for (int i = 0; i < s.size(); ++i) {
		right[getIndex(s[i])]++;
	}

	// âEÇ…Ç∏ÇÁÇµÇƒÇ≠
	int ans = 0;

	REP(i, s.size()){
		char c = s[i];
		right[getIndex(c)]--;
		left[getIndex(c)]++;

		int same_number = 0;
		REP(j, 26) {
			if (left[j] > 0 && right[j] > 0) same_number++;
		}
		ans = max(ans, same_number);
	}
	cout << ans;
	system("pause");
	return 0;
}