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

#define REPS(i, a, b) for (int i = a; i < b; i++)
#define REP(i, n) for (int i = 0; i < n; i++)

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int mod = 1e9 + 7;
const long double pi = 3.141592653589793238462643383279502884197;
const long double eps = 1e-7;

double get_cosine_sim(int x1, int y1, int x2, int y2)
{
    double outer_product_z;
    // double norm1 = sqrt(x1 * x1 + y1 * y1);
    // x1 /= norm1;
    // y1 /= norm1;
    // double norm2 = sqrt(x2 * x2 + y2 * y2);
    // x2 /= norm2;
    // y2 /= norm2;
    outer_product_z = x1 * y2 - y1 * x2;
    // cout << outer_product_z << endl;
    return outer_product_z;
}

int main()
{
    int ax, ay, bx, by, cx, cy, dx, dy;
    cin >> ax >> ay;
    cin >> bx >> by;
    cin >> cx >> cy;
    cin >> dx >> dy;
    // 反時計回りなので外戚のz軸の値は正になる
    if (get_cosine_sim(bx - ax, by - ay, dx - ax, dy - ay) <= 0.0)
    {
        cout << "No" << endl;
        return 0;
    }
    if (get_cosine_sim(cx - bx, cy - by, ax - bx, ay - by) <= 0.0)
    {
        cout << "No" << endl;
        return 0;
    }
    if (get_cosine_sim(dx - cx, dy - cy, bx - cx, by - cy) <= 0.0)
    {
        cout << "No" << endl;
        return 0;
    }
    if (get_cosine_sim(ax - dx, ay - dy, cx - dx, cy - dy) <= 0.0)
    {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}
