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

int N;

bool validate(string seq)
{
    int sum = 0;
    int pos_count = 0;
    int neg_count = 0;
    for (string::iterator itr = seq.begin(); itr != seq.end(); ++itr)
    {
        if (*itr == '(')
        {
            sum++;
            pos_count++;
        }
        else
        {
            sum--;
            neg_count++;
        }
        if (sum < 0)
            return false;
    }
    if (pos_count != (N / 2))
        return false;
    if (neg_count != (N / 2))
        return false;
    return true;
}

int main()
{
    cin >> N;
    if (N % 2 != 0)
    {
        cout << endl;
        return 0;
    }

    vector<string> dict;
    // bit全探索
    // "("を0, ")"を1とする
    for (int bit = 0; bit < (1 << N); ++bit)
    {
        // i桁目
        string seq = "";
        for (int i = 0; i < N; ++i)
        {
            if (bit & (1 << i)) // 1
            {
                seq += ")";
            }
            else // 0
            {
                seq += "(";
            }
        }
        if (validate(seq))
        {
            dict.push_back(seq);
        }
    }
    sort(dict.begin(), dict.end());
    REP(i, dict.size())
    cout << dict[i] << endl;

    return 0;
}
