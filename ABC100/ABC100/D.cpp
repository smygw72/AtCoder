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
#include<functional> // greater<Type>()

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
	vector<ll> cost[8];
	int N, M;
	cin >> N >> M;

	REP(i, N) {
		ll x, y, z;
		cin >> x >> y >> z;
		cost[0].push_back(x + y + z);
		cost[1].push_back(x + y - z);
		cost[2].push_back(x - y + z);
		cost[3].push_back(x - y - z);
		cost[4].push_back(-x + y + z);
		cost[5].push_back(-x + y - z);
		cost[6].push_back(-x - y + z);
		cost[7].push_back(-x - y - z);
	}

	ll maxCost = 0;
	REP(i, 8){
		sort(cost[i].begin(), cost[i].end());

		ll totalCost = 0;
		for (int j = N - 1; j > N - M - 1; j--) {
			totalCost += cost[i][j];
		}
		if (maxCost < totalCost) maxCost = totalCost;
	}
	std::cout << maxCost;
	
	std::system("pause");
	return 0;
}