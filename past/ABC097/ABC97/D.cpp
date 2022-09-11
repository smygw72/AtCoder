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

//1. ���R�ɓ���ւ�����O���[�v�����
//ex) (1, 2), (2, 5)��(1, 2, 5)
//2. �e�O���[�v�ɂ���index�ƈ�v����l�𐔂��グ��]
//ex) index(1, 2, 4) :value(2, 4, 7) �� 2��

//UnionFind���g�����I

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
		// p[i]����1�����̂�Y��Ȃ��I(�͈͂��P�`N�Ȃ̂�)
		if (unionFind.isSame(i, p[i] - 1)) ans++;
	}

	cout << ans;
	system("pause");
	return 0;
}