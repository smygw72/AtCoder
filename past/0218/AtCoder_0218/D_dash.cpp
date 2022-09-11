#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<vector<char>> field_t;

typedef pair<int, int> point_t;

point_t operator+(const point_t &lhs, const point_t &rhs)
{
	point_t p = { lhs.first + rhs.first, lhs.second + rhs.second };
	return p;
}

bool operator==(const point_t &lhs, const point_t &rhs)
{
	return (lhs.first == rhs.first) && (lhs.second == rhs.second);
}

bool is_in_field(int col, int row, const point_t &point)
{
	const int c = point.second;
	const int r = point.first;
	return (0 <= c && c < col) && (0 <= r && r < row);
}

int solve(int col, int row, field_t &field, const point_t &start, const point_t &goal)
{
	// 2. �e�}�X�̖K�◚��(memo)���쐬����
	//    memo�ɂ̓X�^�[�g���炻�̃}�X�܂ł̕������i�[����(�����l��0)
	vector<vector<int>> memo;
	for (int i = 0; i < row; ++i) {
		vector<int> v(col, 0);
		memo.push_back(v);
	}

	// �ړ�����(�㉺���E)
	const point_t points[] = {
		{ -1, 0 },{ 1, 0 },{ 0, -1 },{ 0, 1 },
	};

	// 3. �X�^�[�g�̃}�X���L���[�Ɋi�[����
	queue<point_t> q;
	q.push(start);

	// 11. 4����10���L���[����ɂȂ�܂ŌJ��Ԃ�
	while (!q.empty()) {
		// 4. �L���[�̐擪�����}�X�擾����
		point_t cur = q.front(); q.pop();

		// 5. ���o�����}�X���S�[���Ȃ�I��
		if (cur == goal) {
			return memo[cur.first][cur.second];
		}

		for (const auto &point : points) {
			// 6. �菇4�Ŏ��o�����}�X(cur)����㉺���E�̉��ꂩ�Ɉړ�����
			point_t next = cur + point;
			// 7. �ړ���̃}�X(next)�����H�O�łȂ����Ƃ��m�F����(���H�O�̏ꍇ�͎菇6�ɖ߂�)
			if (is_in_field(col, row, next)) {
				const char s = field[next.first][next.second];
				// 8. �ړ���̃}�X(next)�����܂��̓S�[���ł��邱�Ƃ��m�F����(���ł��S�[���ł��Ȃ��ꍇ�͎菇6�ɖ߂�)
				if (s == '.' || s == 'g') {
					// 9. �ړ���̃}�X(next)�����K��ł��邱�Ƃ��m�F����(�K��ς݂̏ꍇ�͎菇6�ɖ߂�)
					if (memo[next.first][next.second] == 0) {
						// 10. �ړ���̃}�X(next)���L���[�Ɋi�[���A�K�◚�����X�V����
						q.push(next);
						memo[next.first][next.second] = memo[cur.first][cur.second] + 1;
					}
				}
			}
		}
	}
	return -1;
}

int main()
{
	int col, row;
	cin >> row >> col;

	point_t start, goal;
	field_t field;

	start.first = 0;
	start.second = 0;
	goal.first = row-1;
	goal.second = col-1;

	int numBlock = 0;

	// 1. ���H(field)���쐬����
	for (int i = 0; i < row; ++i) {
		vector<char> v;
		for (int j = 0; j < col; ++j) {
			char c;
			cin >> c;

			if (c == '#') {
				numBlock++;
			}
			if (i == 0 && j == 0) {
				c == 's';
			}
			else if (i == (row - 1) && j == (col - 1)) {
				c == 'g';
			}
			v.push_back(c);
		}
		field.push_back(v);
	}

	// �ŒZ������solve�Ōv�Z����
	int result = solve(col, row, field, start, goal);
	if (result != -1) {
		cout << (col*row - result - 1 - numBlock) << endl;
	}
	else {
		cout << "-1";
	}
	system("pause");
	return 0;
}