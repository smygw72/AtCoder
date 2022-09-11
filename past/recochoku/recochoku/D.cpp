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

const int SIZE = 50;
int mas[SIZE][SIZE];
int A, B; // A(îí):1ÇÃêî, B(çï):0ÇÃêî
int a = 0, b = 0;

int getValue(int i, int j) {
	if (i < 0 || i >= SIZE || j < 0 || j >= SIZE) {
		return -1;
	}
	return mas[i][j];
}

bool paint(int i,int j) {

	int left = getValue(i, j - 1);
	int down = getValue(i, j - 1);

	if (left == down && left == 0) {
		if (A - a > 0) {
			mas[i][j] = 1;
			a++;
			return 1;
		}
		else {
			mas[i][j] = 0;
		
			return 0;
		}
	}
	else if (left == down && left == 1) {
		if (B - b > 0) {
			mas[i][j] = 0;
			b++;
			return 0;
		}
		else {
			mas[i][j] = 1;
			
			return 1;
		}
	}
	else {
		if (A - a >= B - b) {
			mas[i][j] = 1;
			return 1;
		}
		else {
			mas[i][j] = 0;
			return 0;
		}
	}

}

int main() {

	cin >> A >> B;
	cout << SIZE << " " << SIZE << endl;

	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			if (paint(i, j)) {
				cout << ".";
			}
			else {
				cout << "#";
			}
		}
		cout << endl;
	}
//	cout << "A:" << a << " B:" << b<<endl;


	system("pause");
	return 0;
}