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
	vector<string> vecStr;
	vector<int> vecInt;
	int N, M;

	cin >> N;
	for (int i = 0; i < N;++i)
	{
		string str;
		cin >> str;
		bool isFound = false;
		for (int j = 0; j < vecStr.size(); ++j) 
		{
			if (vecStr[j] == str) {
				vecInt[j]++;
				isFound = true;
				break;
			}
		}
		if (!isFound) {
			vecStr.push_back(str);
			vecInt.push_back(1);
		}
	}

	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		string str;
		cin >> str;
		bool isFound = false;
		for (int j = 0; j < vecStr.size(); ++j)
		{
			if (vecStr[j] == str) {
				vecInt[j]--;
				break;
			}
		}
	}

/*	for (int i = 0; i < vecStr.size(); ++i) {
		cout << vecStr[i] << " " << vecInt[i] << endl;
	}*/

	int max = 0;
	for (int i = 0; i < vecStr.size(); ++i) {
		if (vecInt[i] > max) {
			max = vecInt[i];
		}
	}

	if (max < 0) {
		max = 0;
	}
	cout << max;

	system("pause");
	return 0;
}