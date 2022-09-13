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
static const int MAX = 300000;

struct Student
{
    int index;
    int B;

    // 最後のconstを忘れると"instantiated from here"というエラーが出てコンパイルできないので注意
    bool operator<(const Student &right) const
    {
        return B < right.B;
    }
};

ll A[MAX];
Student student[MAX];
int N, Q;

int search(const ll student_rate, ll &student_score, int &left)
{
    REPS(i, left, N)
    {
        ll left_score = abs(student_rate - A[i]);
        if (i == N - 1)
        {
            student_score = left_score;
            return i;
        }
        ll right_score = abs(student_rate - A[i + 1]);
        if (left_score < right_score)
        {
            student_score = left_score;
            return i;
        }
    }
}

int main()
{
    cin >> N;
    REP(i, N)
    {
        cin >> A[i];
    }
    cin >> Q;

    sort(A, A + N);

    REP(i, Q)
    {
        student[i].index = i;
        cin >> student[i].B;
    }

    sort(student, student + Q);

    int left = 0;

    ll scores[MAX];
    REP(i, Q)
    {
        ll score;
        left = search(student[i].B, score, left);
        scores[student[i].index] = score;
    }

    REP(i, Q)
    {
        cout << scores[i] << endl;
    }

    return 0;
}
