#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
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

int N=0, L=0, K=0;
unsigned int A[100000];

void print_vector(vi vec)
{
    REP(i, vec.size())
    {
        cout << vec[i] << " ";
    }
}

bool try_split(vi length, int score)
{
    int idx = 0;

    REP(i, K)
    {
        int sum = 0;
        while(sum < score)
        {
            if(idx == N + 1){
                return false;
            }
            sum += length[idx];
            idx++;
        }
    }
    // rest
    if(idx == (N + 1)){
        return false;
    }
    int sum = L - A[idx - 1];
    if (sum < score) return false;

    return true;
}


int binary_search(vi length)
{
    int left_score = 0;
    int right_score = L;
    while((right_score - left_score) > 1){
        // cout << "left: " << left_score << endl;
        // cout << "right: " << right_score << endl;
        // cout << endl;
        int mid_score = left_score + (right_score - left_score) / 2;
        bool result = try_split(length, mid_score);
        // cout << result << endl;
        if (result)
        {
            // If success, score is bigger
            left_score = mid_score;
       }
        else
        {
            // If failure, score is smaller
            right_score = mid_score;
        }
    }
    return left_score;
}


int main()
{
    cin >> N >> L;
    cin >> K;
    vi length(N + 1);
    REP(i, N)
    {
        cin >> A[i];
        if (i == 0)
        {
            length[0] = A[i];
        }
        else
        {
            length[i] = A[i] - A[i - 1];
        }
    }
    length[N] = L - A[N - 1];
    cout << binary_search(length) << endl;

    return 0;
}
