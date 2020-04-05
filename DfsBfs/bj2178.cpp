#include <iostream>
#include <queue>
#include <vector>
#define MAX_SIZE 100
using namespace std;

typedef struct {
	int x, y, dist;
} Point;

int n, m, res;
int graph[MAX_SIZE + 1][MAX_SIZE + 1];
bool visited[MAX_SIZE + 1][MAX_SIZE + 1] = { {false, } };
queue<Point> que;
vector<pair<int, int>> rcxy;

bool inRange(int x, int y) {
	if (x >= 1 && x <= n && y >= 1 && y <= m) return true;
	return false;
}

void bfs() {
	que.push({ 1, 1, 1 });
	visited[1][1] = true;

	while (!que.empty()) {
		Point p = que.front();
		que.pop();

		if (p.x == n && p.y == m) {
			res = p.dist;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int nX = p.x + rcxy[i].first;
			int nY = p.y + rcxy[i].second;
			if (inRange(nX, nY) && !visited[nX][nY] && graph[nX][nY]) {
				visited[nX][nY] = true;
				que.push({ nX, nY, p.dist+1 });
			}
		}
	}

}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}
	rcxy.push_back({ 0, -1 }); rcxy.push_back({ 0, 1 });
	rcxy.push_back({ -1, 0 }); rcxy.push_back({ 1, 0 });

	bfs();
	
	printf("%d", res);

	return 0;
}