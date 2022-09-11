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

int main() {
	int count = 0;

	int N = 0;
	int sum[200000];
	cin >> N;

	REP(i, N) {
		int value;
		cin >> value;
		if (i != 0) {
			sum[i] = sum[i - 1] + value;
		}
		else {
			sum[0] = value;
		}
		if (sum[i] == 0) {
			count++;
		}
	}

	REP(i, N) {
		for (int j = i + 1; j < N; ++j) {
			if(sum[j] - sum[i] == 0) {
				count++;
			}
		}
	}
	cout << count;
	system("pause");
	return 0;
}