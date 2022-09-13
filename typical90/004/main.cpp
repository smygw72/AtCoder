#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <array>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <math.h>

#define REPS(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using si = stack<int>;
using qi = queue<int>;
using li = list<int>;

static const int INF = (1 << 21);
static const long double PI = 3.141592653589793238462643383279502884197;
static const long double EPS = 1e-7;
static const int MAX = 2000;

int A[MAX][MAX];
int row_sum[MAX] = {0};
int col_sum[MAX] = {0};

int main()
{
    int H, W;
    cin >> H >> W;
    REP(i, H)
    {
        REP(j, W)
        {
            cin >> A[i][j];
            row_sum[i] += A[i][j];
            col_sum[j] += A[i][j];
        }
    }

    REP(i, H)
    {
        REP(j, W)
        {
            int B = row_sum[i] + col_sum[j] - A[i][j];
            cout << B;
            if (j != (W - 1))
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}
