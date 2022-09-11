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

int dis[30][30];
int grid[500][500];

int main() {
	int N, C;
	cin >> N >> C;
	REP(i, C) {
		REP(j, C) {
			cin >> dis[i][j];
		}
	}
	REP(i, N) {
		REP(j, N) {
			cin >> grid[i][j];
		}
	}
	// ‰Šú‰»
	int color_count[3][30];
	REP(i, 3) {
		REP(j, 30) {
			color_count[i][j] = 0;
		}
	}
	// ”‚¦ã‚°
	REP(i, N) {
		REP(j, N) {
			int rest = (i + j + 2) % 3;
			int color_num = grid[i][j] - 1;
			color_count[rest][color_num]++;
		}
	}

	int minCost = mod;

	// ‘S’Tõ
	REP(i, C) {
		REP(j, C) {
			if (i == j) continue;
			REP(k, C) {
				if (k == i || k == j) continue;

				int cost = 0;
				REP (l, C) {
					cost += (
						color_count[0][l] * dis[l][i] +
						color_count[1][l] * dis[l][j] +
						color_count[2][l] * dis[l][k]);
				}
				if (minCost > cost) minCost = cost;
			}
		}
	}
	cout << minCost;
	system("pause");
	return 0;
}