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
	ll name_count[5];
	REP(i, 5) name_count[i] = 0;

	string name;
	REP(i, N) {
		cin >> name;
		switch (name[0]) {
		case 'M':
			name_count[0]++;
			break;
		case 'A':
			name_count[1]++;
			break;
		case 'R':
			name_count[2]++;
			break;		
		case 'C':
			name_count[3]++;
			break;
		case 'H':
			name_count[4]++;
			break;
		}
	}
	
	ll ans = 0;
	REPS(i, 0, 3) {
		REPS(j, i + 1, 4) {
			REPS(k, j + 1, 5) {
				ans += (name_count[i] * name_count[j] * name_count[k]);
			}
		}
	}
	cout << ans;
	system("pause");
	return 0;
}