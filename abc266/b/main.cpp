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

const ll mod = 998244353;
const long double pi = 3.141592653589793238462643383279502884197;
const long double eps = 1e-7;

void print_vector(vi vec)
{
    REP(i, vec.size())
    {
        cout << vec[i] << " ";
    }
}

int main()
{
    ll N;
    cin >> N;
    ll a;
    if (N % mod == 0)
    {
        a = N / mod;
    }
    else
    {
        a = ceil((double)N / mod - 1);
    }
    // cout << a << endl;
    ll x = N - mod * a;
    cout << x << endl;

    return 0;
}
