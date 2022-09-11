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

int H, W;
bool grid[50][50];

bool isInner(int _x, int _y) {
	if (_x < 0 || _x >= W || _y < 0 || _y >= H) return false;
	return true;
}

bool isBlack(int _x, int _y) {
	if (grid[_y][_x]) return true;
	return false;
}

bool canPaint(int _x, int _y) {
	if (isInner(_x - 1, _y)) {
		if (isBlack(_x - 1, _y)) return true;
	}
	if (isInner(_x + 1, _y)) {
		if (isBlack(_x + 1, _y)) return true;
	}
	if (isInner(_x, _y - 1)) {
		if (isBlack(_x, _y - 1)) return true;
	}
	if (isInner(_x, _y + 1)) {
		if (isBlack(_x, _y + 1)) return true;
	}
	return false;
}

int main() {
	cin >> H >> W;
	REP(i, H) {
		REP(j, W) {
			char c;
			cin >> c;
			if (c == '#') grid[i][j] = 1;
			else grid[i][j] = 0;
		}
	}

	string ans = "Yes";
	REP(i, H) {
		REP(j, W) {
			if (isBlack(j, i)) {
				if (!canPaint(j, i)) {
					ans = "No";
					break;
				}
			}
		}
		if (ans == "No") break;
	}
	cout << ans;
	system("pause");
	return 0;
}