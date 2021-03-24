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

//1. 自由に入れ替えられるグループを作る
//ex) (1, 2), (2, 5)→(1, 2, 5)
//2. 各グループについてindexと一致する値を数え上げる]
//ex) index(1, 2, 4) :value(2, 4, 7) → 2個

//UnionFindを使おう！

class UnionFind {
private:
	vector<int> par;

public:
	UnionFind(int N) {
		REP(i, N) par.push_back(i);
	}
	int getRoot(int x) {
		if (par[x] == x) return x;
		return par[x] = getRoot(par[x]);
	}
	void unite(int x, int y) {
		int rx = getRoot(x);
		int ry = getRoot(y);
		if (rx == ry) return;
		par[rx] = ry;
	}
	bool isSame(int x, int y) {
		return getRoot(x) == getRoot(y);
	}
};


signed main() {
	int N, M;
	cin >> N >> M;
	int p[100010];
	REP(i, N) cin >> p[i];

	UnionFind unionFind(N);
	REP(i, M) {
		int x, y;
		cin >> x >> y;
		unionFind.unite(x - 1, y - 1);
	}

	int ans = 0;
	REP(i, N) {
		// p[i]から1引くのを忘れない！(範囲が１～Nなので)
		if (unionFind.isSame(i, p[i] - 1)) ans++;
	}

	cout << ans;
	system("pause");
	return 0;
}