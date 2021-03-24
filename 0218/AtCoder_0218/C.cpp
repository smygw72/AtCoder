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
	int c[3][3];
	REP(i, 3) {
		REP(j, 3) {
			cin >> c[i][j];
		}
	}

	bool col = false, row = false;

	int a12 = c[1][0] - c[0][0];
	int a13 = c[2][0] - c[0][0];
	int b12 = c[0][1] - c[0][0];
	int b13 = c[0][2] - c[0][0];

	if(a12 == (c[1][1]-c[0][1]) && a12 == (c[1][2]-c[0][2]) 
		&& a13 == (c[2][1] - c[0][1]) && a13 == (c[2][2] - c[0][2])) {
		col = true;
	}

	if (b12 == (c[1][1] - c[1][0]) && b12 == (c[2][1] - c[2][0])
		&& b13 == (c[1][2] - c[1][0]) && b13 == (c[2][2] - c[2][0])) {
		row = true;
	}

	if (col && row) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
	

	system("pause");
	return 0;
}