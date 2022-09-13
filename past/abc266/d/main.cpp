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
int T[100000], X[100000];
ll A[100000];
ll score[100000][5] = {0};
bool flag[100000][5] = {false};

void print_status()
{
    REP(i, T[N - 1] + 1)
    {
        REP(j, 5)
        {
            cout << score[i][j] << " ";
        }
        cout << endl;
    }
    REP(i, T[N - 1] + 1)
    {
        REP(j, 5)
        {
            cout << flag[i][j] << " ";
        }
        cout << endl;
    }
}

ll get_new_score(int target_t, int target_x)
{
    // 2分木探索
    int left_i = -1;
    int right_i = N;
    int middle_i = left_i + (right_i - left_i) / 2;
    ll new_score = 0;
    while ((right_i - left_i) > 1)
    {
        if (T[middle_i] < target_t)
        {
            left_i = middle_i;
        }
        else if (T[middle_i] > target_t)
        {
            right_i = middle_i;
        }
        else
        {
            if (X[middle_i] == target_x)
                new_score = A[middle_i];
            break;
        }
        middle_i = left_i + (right_i - left_i) / 2;
    }
    return new_score;
}

void init()
{
    // 腑抜けくんの初期位置は0
    score[0][0] = 0;
    flag[0][0] = true;

    // t=3までは動ける範囲以外に制限がある
    REP(t, 4)
    {
        for (int i = 4; i > t; i--)
        {
            score[t][i] = 0;
            flag[t][i] = true;
        }
    }
}

ll get_score(int t, int x)
{
    // DP
    ll new_score = get_new_score(t, x);

    // if exists memo, get memo
    if (flag[t - 1][x] == false)
    {
        score[t - 1][x] = get_score(t - 1, x);
        flag[t - 1][x] = true;
    }
    if (x != 0)
    {
        if (flag[t - 1][x - 1] == false)
        {
            score[t - 1][x - 1] = get_score(t - 1, x - 1);
            flag[t - 1][x - 1] = true;
        }
    }
    if (x != 4)
    {
        if (flag[t - 1][x + 1] == false)
        {
            score[t - 1][x + 1] = get_score(t - 1, x + 1);
            flag[t - 1][x + 1] = true;
        }
    }

    if (x == 0)
    {
        score[t][x] = max(score[t - 1][x], score[t - 1][x + 1]) + new_score;
    }
    else if (x == 4)
    {
        score[t][x] = max(score[t - 1][x - 1], score[t - 1][x]) + new_score;
    }
    else
    {
        score[t][x] = max(max(score[t - 1][x], score[t - 1][x + 1]), score[t - 1][x - 1]) + new_score;
    }
    flag[t][x] = true;
    return score[t][x];
}

int main()
{
    cin >> N;

    REP(i, N)
    {
        cin >> T[i] >> X[i] >> A[i];
    }
    ll max_score = 0;
    ll tmp_score;

    init();
    // print_status();
    REP(i, 5)
    {
        if (flag[T[N - 1]][i] == false)
        {
            tmp_score = get_score(T[N - 1], i);
            flag[T[N - 1]][i] = true;
        }
        else
        {
            tmp_score = score[T[N - 1]][i];
        }
        if (max_score < tmp_score)
            max_score = tmp_score;
    }
    cout << max_score << endl;
    // print_status();
    return 0;
}