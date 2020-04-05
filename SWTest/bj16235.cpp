#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_SIZE 10
using namespace std;

int n, m, k;
typedef struct {
	vector<int> trees;
	int nu;
} Land;

Land graph[MAX_SIZE + 1][MAX_SIZE + 1];
int A[MAX_SIZE + 1][MAX_SIZE + 1];
int rcxy[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };

void spring() {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (graph[i][j].trees.size() == 0) continue;
			sort(graph[i][j].trees.begin(), graph[i][j].trees.end());
			for (int idx = 0; idx < graph[i][j].trees.size(); idx++) {
				int age = graph[i][j].trees[idx];
				if (graph[i][j].nu >= age) {
					graph[i][j].nu -= age;
					graph[i][j].trees[idx] = age + 1;
				}
				else {
					graph[i][j].trees[idx] = age * (-1);
				}
			}
		}
	}

}

bool compare(int a, int b) {
	return a > b;
}

void summer() {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (graph[i][j].trees.size() == 0) continue;
			sort(graph[i][j].trees.begin(), graph[i][j].trees.end(), compare);
			
			for (int idx = graph[i][j].trees.size() - 1; idx >= 0; idx--) {
				int tmp = graph[i][j].trees.back();
				if (tmp < 0) {
					graph[i][j].trees.pop_back();
					tmp *= (-1);
					graph[i][j].nu += tmp / 2;
				}
				else break;
			}
			
		}
	}

}

bool inRange(int x, int y) {
	if (x >= 1 && x <= n && y >= 1 && y <= n) return true;
	return false;
}

void fall() {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int idx = 0; idx < graph[i][j].trees.size(); idx++) {
				if (graph[i][j].trees[idx] % 5 == 0) {
					for (int t = 0; t < 8; t++) {
						int nX = i + rcxy[t][0];
						int nY = j + rcxy[t][1];
						if (inRange(nX, nY)) {
							graph[nX][nY].trees.push_back(1);
						}
					}
				}
			}

		}
	}

}

void winter() {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			graph[i][j].nu += A[i][j];
		}
	}

}

int main() {
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			graph[i][j].nu = 5;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> A[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		graph[x][y].trees.push_back(z);
	}

	for (int i = 0; i < k; i++) {
		spring();
		summer();
		fall();
		winter();
	}

	int cnt = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cnt += graph[i][j].trees.size();
		}
	}
	cout << cnt;

	return 0;
}