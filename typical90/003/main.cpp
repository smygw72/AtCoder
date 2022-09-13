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

static const int INF = (1 << 21);
static const long double PI = 3.141592653589793238462643383279502884197;
static const long double EPS = 1e-7;
static const int MAX = 100000;

int N;
int A, B;
vector<int> graph[MAX];
bool searched[MAX];
int dist[MAX];

void init()
{
    REP(i, N)
    {
        searched[i] = false;
        dist[i] = -1;
    }
}

// 幅優先探索
int bfs(int start_node)
{
    queue<int> q;
    q.push(start_node);
    searched[start_node] = true;
    dist[start_node] = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        REP(i, graph[node].size())
        {
            int next_node = graph[node][i];
            if (!searched[next_node] && dist[next_node] == -1)
            {
                q.push(next_node);
                searched[next_node] = true;
                dist[next_node] = dist[node] + 1;
            }
        }
    }

    int max_dist = 0;
    int max_dist_index;
    REP(i, N)
    {
        if (max_dist < dist[i])
        {
            max_dist = dist[i];
            max_dist_index = i;
        }
    }
    return max_dist_index;
}

int main()
{
    cin >> N;

    REP(i, N - 1)
    {
        cin >> A >> B;
        // bi-directional edge
        graph[A - 1].push_back(B - 1);
        graph[B - 1].push_back(A - 1);
    }

    // 木の直径を求めるアルゴリズム
    int start_node = 0; // なんでもよい
    init();
    int tmp_node = bfs(start_node);
    // cout << tmp_node << endl;

    init();
    int max_dist_index = bfs(tmp_node);
    // cout << max_dist_index << endl;

    std::cout << dist[max_dist_index] + 1 << endl;
    return 0;
}
