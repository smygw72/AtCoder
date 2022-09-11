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

int t[200010];
int ch[200010][30];

int main() {
	int N, C;
	cin >> N >> C;

	REP(i, 200010) {
		t[i] = 0;
		REP(j, 30) ch[i][j] = 0;
	}

	REP(i, N) {
		int si, ti, ci;
		cin >> si >> ti >> ci;
		ci -= 1;

		if (ch[2 * si][ci] == -1 && ch[2 * ti - 1][ci] == 1) {
			ch[2 * si][ci] = 0;
			ch[2 * ti - 1][ci] = 0;
		}
		else if (ch[2 * si][ci] == -1) {
			ch[2 * si][ci] = 0;
			ch[2 * ti][ci] = -1;
		}
		else if (ch[2 * ti - 1][ci] == 1) {
			ch[2 * si - 1][ci] = 1;
			ch[2 * ti - 1][ci] = 0;
		}
		else {
			ch[2 * si - 1][ci] = 1;
			ch[2 * ti][ci] = -1;
		}
	}


	REP(i, 200001){
		REP(j, C) {
			if (ch[i][j] == 1) {
				t[i]++;
			}
			else if (ch[i][j] == -1) {
				t[i]--;
			}
		}
	}

	int ans = 0;
	REPS(i, 1, 200001) {
		t[i] += t[i - 1];
		ans = max(ans, t[i]);
	}
	cout << ans;
	system("pause");
	return 0;
}