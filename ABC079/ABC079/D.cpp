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

int c[10][10];
int a[201][201];

int cost[10], minCost[10];
bool done[10];

bool canUpdate() {
	REP(i, 10) {
		if (done[i] != true) return true;
	}
	return false;
}

int main() {
	int H, W;
	cin >> H >> W;
	REP(i, 10) REP(j, 10) cin >> c[i][j];
	REP(i, H) REP(j, W) cin >> a[i][j];

	// ダイクストラ法
	REP(num, 10) {
		// 初期化
		REP(i, 10) {
			cost[i] = mod;
			done[i] = false;
		}
		cost[num] = 0;

		while (canUpdate()) {
			int min_ix, min_num = mod;

			// 未探索の中でコスト最小のノードを探索
			REP(i, 10) {
				if (cost[i] < min_num && done[i] == false) {
					min_num = cost[i];
					min_ix = i;
				}
			}

			// コストが小さくなれば更新
			REP(i, 10) {
				if (done[i] != true) {
					int cost_dash = cost[min_ix] + c[min_ix][i];
					if (cost[i] > cost_dash) cost[i] = cost_dash;
				}
			}
			done[min_ix] = true;
		}
		minCost[num] = cost[1];
		//cout << cost[1] << endl;
	}

	ll ans = 0;
	REP(i, H) {
		REP(j, W) {
			int wallNum = a[i][j];
			if(wallNum!=-1){
				ans += minCost[wallNum];
			}
		}
	}
	cout << ans;
	system("pause");
	return 0;
}