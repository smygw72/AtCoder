#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAX_N = 8000;

bool dp[MAX_N + 3][MAX_N + 3][2];
int x[MAX_N + 3];
int y[MAX_N + 3];

int main() {
	string s;
	int dx, dy, dir = 1, sx;
	cin >> s >> dx >> dy;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'F')  dx--;
		else {
			sx = i;
			break;
		}
	}

	int ix = 0, iy = 0;
	for (int i = sx; i < s.size(); i++) {
		if (s[i] == 'T' && dir == 1) {
			dir *= -1;
			iy++;
		}
		else if (s[i] == 'T' && dir == -1) {
			dir *= -1;
			ix++;
		}
		else if (s[i] == 'F' && dir == -1) {
			y[iy]++;
		}
		else if (s[i] == 'F' && dir == 1) {
			x[ix]++;
		}
		//else cout << << " " << endl;

	}
	dp[0][0][0] = 1;
	dp[0][0][1] = 1;

	for (int i = 1; i <= ix; i++) {
		for (int j = 0; j <= MAX_N; j++) {
			if (j + x[i] <= MAX_N) dp[i][j][0] = dp[i - 1][abs(j - x[i])][0] || dp[i - 1][abs(j + x[i])][0];
			else dp[i][j][0] |= dp[i - 1][abs(j - x[i])][0];
		}
	}
	for (int i = 1; i <= iy; i++) {
		for (int j = 0; j <= MAX_N; j++) {
			if (j + y[i] <= MAX_N) dp[i][j][1] = dp[i - 1][abs(j - y[i])][1] || dp[i - 1][abs(j + y[i])][1];
			else dp[i][j][1] |= dp[i - 1][abs(j - y[i])][1];
		}
	}

	if (dp[ix][abs(dx)][0] && dp[iy][abs(dy)][1]) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}
