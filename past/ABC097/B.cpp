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
	int X;
	cin >> X;
	
	int max_num = 0;
	if (X == 1) {
		max_num = 1;
	}
	else {
		for (int b = 2; b <= (int)floor(sqrt(X)); ++b) {
			int p = 2;
			while (1) {
				int num = pow(b, p);
				if (num > X) break;
				max_num = max(max_num, num);
				p++;
			}
		}
	}
	cout << max_num;
	system("pause");
	return 0;
}