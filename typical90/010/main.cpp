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
static const int MAX = 100000;

ll sum[MAX + 1][2];

int main()
{
    int N;
    cin >> N;

    // init
    sum[0][0] = 0;
    sum[0][1] = 0;

    int C, P;
    REP(i, N)
    {
        cin >> C >> P;
        REP(j, 2)
        {
            sum[i + 1][j] = sum[i][j];
        }
        sum[i + 1][C - 1] += P;
    }

    // REP(i, N + 1)
    // {
    //     cout << sum[i][0] << " ";
    // }
    // cout << endl;
    // REP(i, N + 1)
    // {
    //     cout << sum[i][1] << " ";
    // }
    // cout << endl;

    int Q, L, R;
    cin >> Q;
    ll output[MAX][2];
    REP(i, Q)
    {
        cin >> L >> R;
        REP(j, 2)
        {
            output[i][j] = (sum[R][j] - sum[L - 1][j]);
        }
    }

    REP(i, Q)
    {
        cout << output[i][0] << " " << output[i][1] << endl;
    }

    return 0;
}
