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
	cin >> N;
	int A[100000],D[100000];
	int pos = 0;
	int output = 0;

	
	REP(i, N) {
		int memo;
		cin >> memo;
		A[i] = memo;
		D[i] = abs(A[i] - pos);
		output += D[i];
		pos = A[i];
	}
	D[N] = abs(pos);
	output += D[N];

	REP(i, N) {
		int result = output;
		if (i == 0) {
			result -= (D[0] + D[1] - abs(A[i + 1]));
		}
		else if (i == (N-1)) {
			result -= (D[N] + D[N-1] - abs(A[i - 1]));
		}
		else {
			result -= (D[i + 1] + D[i] - abs(A[i + 1] - A[i - 1]));
		}
		cout << result << endl;
	}


	system("pause");
	return 0;
}