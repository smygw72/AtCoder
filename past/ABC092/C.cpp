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

bool compare(pii red, pii blue) {
	if (red.first < blue.first && red.second < blue.second) {
		return true;
	}
	return false;
}

bool pairCompareFirst(const pii& firstElof, const pii& secondElof)
{
	return firstElof.first < secondElof.first;
}

bool pairCompareSecond(const pii& firstElof, const pii& secondElof)
{
	return firstElof.second < secondElof.second;
}

int main() {
	int N;
	vector<pii> red, blue;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		pii xy;
		int x, y;
		cin >> x >> y;
		xy.first = x;
		xy.second = y;
		red.push_back(xy);
	}
	for (int i = 0; i < N; ++i) {
		pii xy;
		int x, y;
		cin >> x >> y;
		xy.first = x;
		xy.second = y;
		blue.push_back(xy);
	}

	// É\Å[Ég
	sort(red.begin(), red.end(), pairCompareFirst);
	sort(blue.begin(), blue.end(), pairCompareFirst);

	int startIdx = 0; 
	int endIdx = 0;
	while (endIdx < N) {
		int target = red[startIdx].first;
		for (int i = startIdx; i < N; ++i) {
			if (red[i].first == target) {
				endIdx = i;
			}
			else {
				startIdx = i;
				break;
			}
		}
		sort(red.begin() + startIdx, red.begin() + endIdx, pairCompareSecond);
		if (endIdx == (N - 1)) break;
	}
	startIdx = 0;
	endIdx = 0;
	while (endIdx < N) {
		int target = red[startIdx].first;
		for (int i = startIdx; i < N; ++i) {
			if (red[i].first == target) {
				endIdx = i;
			}
			else {
				startIdx = i;
				break;
			}
		}
		sort(blue.begin() + startIdx, blue.begin() + endIdx, pairCompareSecond);
		if (endIdx == (N - 1)) break;
	}

/*	for (int i = 0; i < N; ++i) {
		cout << red[i].first << " " << red[i].second << endl;
	}
	for (int i = 0; i < N; ++i) {
		cout << blue[i].first << " " << blue[i].second << endl;
	}*/

	int result=0;
	int start = N-1;
	for (int i = (N-1); i >= 0; --i) {
		bool isFound = false;
		for (int j = start; j >= 0; --j) {
			
			//cout << "RED: " << red[i].first << red[i].second << endl;
			//cout << "BLUE: " << blue[j].first << blue[j].second << endl;

			if (compare(red[i], blue[j])) {
				//cout << "Pair!!" << endl;
				result++;
				start = j - 1;
				isFound=true;
			}
			if (isFound) break;
		}
	}

	cout << result;
	system("pause");
	return 0;
}