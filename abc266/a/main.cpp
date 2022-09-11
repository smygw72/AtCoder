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

const int mod = 1e9 + 7;
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
    string s;
    cin >> s;
    int length = s.size();
    if (length % 2)
    { // odd
        cout << s[(length + 1) / 2 - 1] << endl;
    }
    else
    {
        cout << s[length / 2 - 1] << endl;
    }
    return 0;
}
