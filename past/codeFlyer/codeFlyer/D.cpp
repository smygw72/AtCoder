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
	int H, W, N, M;
	cin >> H >> W;
	cin >> N >> M;
	bool A[1000][1000];
	REP(i, N) {
		string str;
		cin >> str;
		REP(j, str.length()) {
			if (str[j] = '#') {
				A[i][j] = 1;
			}
			else {
				A[i][j] = 0;
			}
		}
	}
	int num_block_h = H / N;
	int num_block_w = W / M;

	system("pause");
	return 0;
}