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
	string s, t;
	cin >> s >> t;
	vector<char> sv, tv;
	REP(i, s.size()) sv.push_back(s[i]);
	REP(i, t.size()) tv.push_back(t[i]);

	sort(sv.begin(), sv.end());
	sort(tv.begin(), tv.end());
	reverse(tv.begin(), tv.end());

	//REP(i, s.size()) cout << sv[i] << " ";
	//cout << endl;
	//REP(i, t.size()) cout << tv[i] << " ";
	//cout << endl;

	int ix = 0;
	while (1) {
		if (ix > sv.size() || ix > tv.size()) {
			if (s.size() < t.size()) {
				cout << "Yes";
			}
			else cout << "No";
			break;
		}
		if (tv[ix] - sv[ix] > 0) {
			cout << "Yes";
			break;
		}
		else if (tv[ix] - sv[ix] < 0) {
			cout << "No";
			break;
		}
		ix++;
	}

	system("pause");
	return 0;
}