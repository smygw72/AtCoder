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
#include<set>

#define REPS(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int mod = 1e9 + 7;
const long double pi = 3.141592653589793238462643383279502884197;
const long double eps = 1e-7;

signed main() {
	string str;
	int K;
	cin >> str >> K;

	set<char> alphabet_set;
	set<string> ans_set;

	// ������Ɏg���Ă���A���t�@�x�b�g���
	REP(i, str.size()) {
		alphabet_set.insert(str[i]);
	}

	// 1�����ڂ�i�Ԗڂ̃A���t�@�x�b�g�̕����������set�ɒǉ�
	for(char alphabet : alphabet_set) {

		// str��j�����ڂ�T��
		REP(j, str.size()) {
			if (str[j] == alphabet) {
				
				// �������set�ɒǉ�
				int length = min((int)str.size() - j + 1, 50);
				REPS(k, 1, length) {
					ans_set.insert(str.substr(j, k));
				}
			}
		}
		if (ans_set.size() >= K) break;
	}

	int count = 0;
	for (string st : ans_set) {
		count++;
		if (count == K) {
			cout << st;
			break;		}
	}
	system("pause");
	return 0;
}