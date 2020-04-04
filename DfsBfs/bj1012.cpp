#include <iostream>
#include <vector>
#define MAX_SIZE 50
using namespace std;

int testCnt;
int totalCnt;
int m, n, k;
int graph[MAX_SIZE + 1][MAX_SIZE + 1];
vector<pair<int, int>> rcxy;

void dfs(int row, int col, int num) {

	if (row < 0 || row >= m || col < 0 || col >= n) return;

	graph[row][col] = num;
	for (int i = 0; i < 4; i++) {
		if (graph[row + rcxy[i].first][col + rcxy[i].second] == 1) {
			dfs(row + rcxy[i].first, col + rcxy[i].second, num);
		}
	}

}

int main() {

	cin >> testCnt;
	int num = 1;
	vector<int> res;
	res.resize(testCnt);

	for (int cnt = 0; cnt < testCnt; cnt++) {
		totalCnt = 0;
		cin >> m >> n >> k;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				graph[i][j] = 0;
			}
		}

		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			graph[x][y] = 1;
		}
		rcxy.push_back({ -1, 0 }); rcxy.push_back({ 1, 0 });
		rcxy.push_back({ 0, -1 }); rcxy.push_back({ 0, 1 });

		for (int x = 0; x < m; x++) {
			for (int y = 0; y < n; y++) {
				if (graph[x][y] == 1) {
					totalCnt++;
					dfs(x, y, ++num);
				}
			}
		}
		res[cnt] = totalCnt;
	}

	for (int i = 0; i < testCnt; i++) {
		cout << res[i] << endl;
	}

	return 0;
}