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
	string s;
	cin >> s;
	int count[3] = {0,0,0};
	REP(i, s.size()) {
		switch (s[i]) {
		case 'a':
			count[0]++;
			break;
		case 'b':
			count[1]++;
			break;
		case 'c':
			count[2]++;
			break;
		}
	}
	bool flag = true;
	REP(i, 3) {
		if (count[i] != 1) flag = false;
	}
	if (flag) cout << "Yes";
	else cout << "No";
	system("pause");
	return 0;
}