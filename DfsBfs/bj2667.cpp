#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_SIZE 25
using namespace std;

int n;
int total;
int graph[MAX_SIZE + 1][MAX_SIZE + 1];
vector<int> tunnelSize;
vector<pair<int, int>> rcxy;

void dfs(int row, int col, int num) {

	if (row<0 || row>=n || col<0 || col>=n) return;
	graph[row][col] = num;
	tunnelSize[num]++;

	for (int i = 0; i < 4; i++) {
		if (graph[row + rcxy[i].first][col + rcxy[i].second] == 1) {
			dfs(row + rcxy[i].first, col + rcxy[i].second, num);
		}
	}

}

int main() {
	
	int tunnelNum = 1;

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}
	tunnelSize.resize(n * n, 0);

	rcxy.push_back({ -1, 0 }); rcxy.push_back({ 1, 0 });
	rcxy.push_back({ 0, -1 }); rcxy.push_back({ 0, 1 });

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (graph[i][j] == 1) {
				dfs(i, j, ++tunnelNum);
			}
		}
	}
	
	for (int i = 0; i < tunnelSize.size(); i++) {
		if (tunnelSize[i] != 0) total++;
	}
	cout << total << endl;
	tunnelSize.resize(total + 2);
	sort(tunnelSize.begin(), tunnelSize.end());

	for (int i = 2; i < 2 + total; i++) {
		cout << tunnelSize[i] << endl;
	}

	return 0;
}