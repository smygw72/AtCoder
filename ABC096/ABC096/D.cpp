#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<map>
#include<tuple>
#include<algorithm>
#include<numeric>
#include<math.h>

#define REPS(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int mod = 1e9 + 7;
const long double pi = 3.141592653589793238462643383279502884197;
const long double eps = 1e-7;

std::vector<int> eratosthenes_sieve(int n) {
	std::vector<int> ps(n + 1);
	std::iota(ps.begin() + 2, ps.end(), 2);
	for (int i = 2; i * i <= n; ++i)
		if (ps[i])
			for (int j = i * i; j <= n; j += i) ps[j] = 0;
	return ps;
}

std::vector<int> make_primes(int n) {
	std::vector<int> ps = eratosthenes_sieve(n);
	ps.erase(std::remove(ps.begin(), ps.end(), 0), ps.end());
	return ps;
}
int main() {
	int N;
	cin >> N;
	vector<int> vec = make_primes(55555);
	
	int count = 0;
	REP(i, vec.size()) {
		if (vec[i] % 5 == 1) {
			cout << vec[i] << " ";
			count++;
			if (count == N) break;
		}
	}
	system("pause");
	return 0;
}