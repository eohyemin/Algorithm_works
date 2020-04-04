#include <iostream>
#define MAX_CNT 100
using namespace std;

int computerCnt;
int edgeCnt;
int total;
int graph[MAX_CNT + 1][MAX_CNT + 1];
int visit[MAX_CNT + 1];

void dfs(int start) {

	visit[start] = 1;

	for (int i = 1; i <= computerCnt; i++) {
		if (graph[start][i] && !visit[i]) {
			total++;
			dfs(i);
		}
	}

}

int main() {

	cin >> computerCnt;
	cin >> edgeCnt;
	for (int i = 0; i < edgeCnt; i++) {
		int x, y;
		cin >> x >> y;
		graph[x][y] = graph[y][x] = 1;
	}

	dfs(1);
	cout << total;

	return 0;
}