#include <iostream>
#include <queue>
#include <vector>
#define MAX_SIZE 20
using namespace std;

typedef struct {
	int x;
	int y;
	int dist;
} Fish;

int n, posX, posY, minX, minY, dist, minDist;
int ssize = 2;
int graph[MAX_SIZE + 1][MAX_SIZE + 1];
bool visit[MAX_SIZE + 1][MAX_SIZE + 1];
queue<Fish> que;
vector<pair<int, int>> rcxy;

bool inRange(int x, int y) {
	if (x >= 0 && y >= 0 && x < n && y < n) return true;
	return false;
}

bool search(int r, int c) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visit[i][j] = false;
		}
	}
	
	que.push({ r, c, 0 });
	visit[r][c] = true;

	minDist = MAX_SIZE * MAX_SIZE;

	while (!que.empty()) {
		int x, y;
		Fish fish = que.front();
		x = fish.x; y = fish.y; dist = fish.dist;
		que.pop();
		
		if (graph[x][y] != 0 && graph[x][y] != 9 && graph[x][y] < ssize) {
			if (minDist > dist) {
				minX = x; minY = y; minDist = dist;
			}
			else if (minDist == dist) {
				if (minX == x) {
					if (minY > y) {
						minY = y;
					}
				}
				else if (minX > x) {
					minX = x; minY = y;
				}
			}
		}

		for (int i = 0; i < 4; i++) {
			int nX = x + rcxy[i].first;
			int nY = y + rcxy[i].second;
			if (!visit[nX][nY] && inRange(nX, nY) && graph[nX][nY] <= ssize) {
				que.push({ nX, nY, dist+1 }); visit[nX][nY] = true;
			}
		}
	}
	if (minX != MAX_SIZE + 1) return true;
	return false;

}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 9) {
				posX = i; posY = j;
			}
		}
	}
	rcxy.push_back({ -1, 0 }); rcxy.push_back({ 0, -1 });
	rcxy.push_back({ 0, 1 }); rcxy.push_back({ 1, 0 });

	bool flag = true;
	int cnt = 0; int sec = 0;

	while (flag) {
		minX = MAX_SIZE + 1; minY = MAX_SIZE + 1;
		flag = search(posX, posY);
		if (flag) {
			sec += minDist;
			cnt += 1;
			graph[minX][minY] = 9; graph[posX][posY] = 0;
			posX = minX; posY = minY;
			if (cnt == ssize) {
				ssize++; cnt = 0;
			}
		}
	}
	cout << sec;

	return 0;
}