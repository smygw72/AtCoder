#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int solve(int K) {
	deque<ii> dq;
	vector<int> vis(K, 0);

	dq.push_front(ii(1, 1)); // num(%K), cost
	while (!dq.empty()) {
		ii p = dq.front(); dq.pop_front();
		int curr = p.first, cnt = p.second;
		if (curr == 0) return cnt;

		vis[curr] = 1;
		int next = (curr + 1) % K;
		if (vis[next] == 0)
			dq.push_back(ii(next, cnt + 1));

		next = (curr * 10) % K;
		if (vis[next] == 0)
			dq.push_front(ii(next, cnt));
	}
}

int main() {
	int K; cin >> K;
	cout << solve(K) << endl;
	return 0;
}