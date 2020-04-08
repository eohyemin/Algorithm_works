#include <iostream>
#include <queue>
#define MAX_SIZE 8
using namespace std;

int n, m, maxArea;
int graph[MAX_SIZE + 1][MAX_SIZE + 1];
int tmpGraph[MAX_SIZE + 1][MAX_SIZE + 1];
int rcxy[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

void checkArea(int (*bfsGraph)[MAX_SIZE+1]) {

	int area = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (bfsGraph[i][j] == 0) area++;
		}
	}
	if (area > maxArea) {
		maxArea = area;
	}

}

void cpy(int(*a)[MAX_SIZE + 1], int(*b)[MAX_SIZE + 1]) { // a = b, b를 a에 복사
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = b[i][j];
		}
	}
}

bool inRange(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m) return true;
	return false;
}

void bfs() {

	int bfsGraph[MAX_SIZE + 1][MAX_SIZE + 1];
	cpy(bfsGraph, tmpGraph);
	queue<pair<int, int>> que;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (bfsGraph[i][j] == 2) que.push({ i, j });
		}
	}

	while (!que.empty()) {
		pair<int, int> xy = que.front();
		que.pop();
		int x = xy.first; 
		int y = xy.second;

		for (int i = 0; i < 4; i++) {
			int nX = x + rcxy[i][0];
			int nY = y + rcxy[i][1];

			if (inRange(nX, nY) && bfsGraph[nX][nY] == 0) {
				que.push({ nX, nY }); 
				bfsGraph[nX][nY] = 2;
			}
		}
	}

	checkArea(bfsGraph);

}



void wall(int cnt) {

	if (cnt == 3) {
		bfs(); return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tmpGraph[i][j] == 0) {
				tmpGraph[i][j] = 1;
				wall(cnt + 1);
				tmpGraph[i][j] = 0;
			}
		}
	}

}

int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
			tmpGraph[i][j] = graph[i][j];
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tmpGraph[i][j] == 0) {
				tmpGraph[i][j] = 1;
				wall(1);
				tmpGraph[i][j] = 0;
			}
		}
	}

	cout << maxArea;

	return 0;
}