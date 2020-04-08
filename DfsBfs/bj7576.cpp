#include <iostream>
#include <queue>
#define MAX_SIZE 1000
using namespace std;

int n, m, day = -1;
int box[MAX_SIZE + 1][MAX_SIZE + 1];
int rcxy[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

bool inRange(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m) return true;
	return false;
}

void bfs() {
	queue<pair<int, int>> que;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (box[i][j] == 1) {
				que.push({ i, j });
			}
		}
	}

	while (!que.empty()) {
		int size = que.size();

		for (int i = 0; i < size; i++) {

			pair<int, int> xy = que.front();
			int x = xy.first;
			int y = xy.second;
			que.pop();

			for (int j = 0; j < 4; j++) {
				int nX = x + rcxy[j][0];
				int nY = y + rcxy[j][1];

				if (inRange(nX, nY) && box[nX][nY] == 0) {
					box[nX][nY] = 1;
					que.push({ nX, nY });
					
				}
			}
		}
		day++;
	}
}

bool isEnd() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (box[i][j] == 0) return false;
		}
	}
	return true;
}

int main() {
	int x, y, res = 0;
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> box[i][j];
		}
	}
	if (!isEnd()) {

		bfs();
		res = day;

		// 모든 토마토 익힐 수 없는 경우 -1 출력
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (box[i][j] == 0) {
					res = -1; break;
				}
			}
		}
	}

	cout << res;

	return 0;
}