#include <iostream>
#include <vector>
#include <queue>
#define MAX_VERTEX 1000
using namespace std;

int vertexCnt, edgeCnt, start;
int graph[MAX_VERTEX + 1][MAX_VERTEX + 1];
int visit[MAX_VERTEX + 1];
queue<int> que;

void dfs(int row) {
	
	visit[row] = 1;

	cout << row << " ";
	for (int i = 1; i <= vertexCnt; i++) {
		if (graph[row][i] && !visit[i]) {
			
			dfs(i);
		}
	}
	
}

void bfs(int start) {

	que.push(start);
	visit[start] = 0;

	while (!que.empty()) {
		int row = que.front();
		que.pop();

		cout << row << " ";

		for (int i = 1; i <= vertexCnt; i++) {
			if (graph[row][i] && visit[i]) {
				visit[i] = 0;
				que.push(i);
			}

		}
	}

}

int main() {
	cin >> vertexCnt >> edgeCnt >> start;
	for (int i = 0; i < edgeCnt; i++) {
		int x, y;
		cin >> x >> y;
		graph[x][y] = graph[y][x] = 1;
	}

	dfs(start); cout << endl;
	bfs(start); cout << endl;

	return 0;
}