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

int mas[100][100]; // ƒ}ƒX–Ú
int weight[100][100]; // d‚Ý

int main() {

	REP(i, 100) {
		REP(j, 100) {
			cin >> mas[i][j];
		}
	}

	setY(_CenterPoints);
	setPhi();
	setWeight();

	system("pause");
	return 0;
}

float phi(const int i1, const int j1, const int i2, const int j2)
{
	return abs(i1 - i2) + abs(j1 - j2);
}

void SetY()
{
	Y.resize(N, 2);

	for (int i = 0; i < N; ++i) {
		Y.coeffRef(i, 0) = after[i].x;
		Y.coeffRef(i, 1) = after[i].y;
	}
}

void SetPhi()
{
	Phi.resize(N, N);

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			Phi.coeffRef(i, j) = phi(X[i], X[j]);
		}
	}
}

void setWeight()
{
	W.resize(N, 2);

	Eigen::PartialPivLU<Eigen::MatrixXf> solver(Phi);

	W = solver.solve(Y);
}
