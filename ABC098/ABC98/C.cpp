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
	string S;
	cin >> N;
	cin >> S;
	int left[2], right[2];

	// 初期値
	REP(i, 2) left[i] = 0, right[i] = 0;
	REP(i, S.size()) {
		if (S[i] == 'W') right[0]++;
		else right[1]++;
	}

	// 最初の一人目がリーダーの場合
	if (S[0] == 'W') right[0]--;
	else right[1]--;
	int ans = right[1] + left[0];

	// リーダーを全探索
	REPS(i, 1, S.size()) {

		char c_current = S[i];
		if (c_current == 'W') right[0]--;
		else right[1]--;
		
		char c_back = S[i - 1];
		if (c_back == 'W') left[0]++;
		else left[1]++;

		int people_num = right[1] + left[0];
		//cout << left[0] << left[1] << right[0] << right[1] << endl;
		ans = min(ans, people_num);
	}
	cout << ans;
	system("pause");
	return 0;
}