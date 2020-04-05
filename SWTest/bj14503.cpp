#include <iostream>
#define MAX_SIZE 50
using namespace std;

int graph[MAX_SIZE + 1][MAX_SIZE + 1]; //청소 영역
bool chk[MAX_SIZE + 1][MAX_SIZE + 1]; //청소했는지 확인
int rcxy[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
int n, m, res;

void find(int r, int c, int dir) {

	if (!chk[r][c]) {
		chk[r][c] = true; res++;
	}
	bool flag = false;
	int d = dir;
	
	for (int i = 0; i < 4; i++) {
		
		int x = r + rcxy[(4 - i + d) % 4][0];
		int y = c + rcxy[(4 - i + d) % 4][1];
		

		if (!chk[x][y] && !graph[x][y]) { 
			find(x, y, (dir == 0) ? 3 : dir - 1); return;
		}
		else {
			if (dir == 0) dir = 3;
			else dir--;

			if (i == 3) {
				int n = (dir == 0) ? 3 : dir - 1;
				int nX = r + rcxy[n][0];
				int nY = c + rcxy[n][1];
				
				if (graph[nX][nY] != 1) {
					find(nX, nY, dir); return;
				}
				else return;
				
			}
		}
	}
	/*
	if (i == 4) {
		int n = (dir+2)%4;
		int nX = r + rcxy[n][0];
		int nY = c + rcxy[n][1];
		if (graph[nX][nY] == 1) return;
		else find(r + rcxy[n][0], c + rcxy[n][1], dir);
	}
	*/
	/*
	if (flag && i == 4) {
		int n = (dir == 0) ? 3 : dir - 1;
		find(r + rcxy[n][0], c + rcxy[n][2], dir);
	}
	*/
	

}

int main() {
	
	cin >> n >> m;
	int r, c, dir;
	cin >> r >> c >> dir;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
		}
	}
	
	find(r, c, dir);

	cout << res;

	return 0;
}